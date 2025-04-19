#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_FILE_CONTENT_LENGTH 10 * 1024 * 1024  // 10MB
#define MAX_FILES 2000
#define MAX_DIR_DEPTH 20

typedef struct {
    char *filename;      // 完整路径
    char *relative_path; // 相对于base_path的路径
    char *shortname;     // 仅文件名
    char *content;
    size_t content_size;
} FileInfo;

char base_path[PATH_MAX] = {0};  // 存储用户指定的基础路径

// 检查是否应该忽略该目录
bool should_ignore_dir(const char *dirname) {
    // 忽略以.开头的目录和名为build的目录
    return (dirname[0] == '.' || strcmp(dirname, "build") == 0);
}

// 获取相对于base_path的路径
char* get_relative_path(const char *full_path) {
    if (strncmp(full_path, base_path, strlen(base_path)) == 0) {
        const char *relative = full_path + strlen(base_path);
        // 跳过路径开头的'/'
        if (*relative == '/') relative++;
        return strdup(relative);
    }
    return strdup(full_path);  // 如果不匹配base_path，返回完整路径
}

// 打印目录树结构
void print_directory_tree(const char *path, int depth, int *file_count) {
    DIR *dir;
    struct dirent *ent;
    struct stat st;
    static char *indents[MAX_DIR_DEPTH] = {0};
    
    // 初始化缩进字符串
    if (indents[0] == NULL) {
        for (int i = 0; i < MAX_DIR_DEPTH; i++) {
            indents[i] = malloc(i * 4 + 1);
            memset(indents[i], ' ', i * 4);
            indents[i][i*4] = '\0';
        }
    }

    if ((dir = opendir(path)) == NULL) {
        return;
    }

    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }

        char new_path[PATH_MAX];
        snprintf(new_path, sizeof(new_path), "%s/%s", path, ent->d_name);

        if (lstat(new_path, &st) == -1) {
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            if (should_ignore_dir(ent->d_name)) {
                continue;
            }
            printf("%s├── %s/\n", indents[depth], ent->d_name);
            print_directory_tree(new_path, depth + 1, file_count);
        } else {
            printf("%s│   ├── %s\n", indents[depth], ent->d_name);
            (*file_count)++;
        }
    }

    closedir(dir);
}

// 递归遍历目录，收集文件信息
int traverse_directory(const char *path, FileInfo *file_array, int *index) {
    DIR *dir;
    struct dirent *ent;
    struct stat st;

    if ((dir = opendir(path)) == NULL) {
        perror("opendir");
        return -1;
    }

    while ((ent = readdir(dir)) != NULL && *index < MAX_FILES) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }

        char new_path[PATH_MAX];
        snprintf(new_path, sizeof(new_path), "%s/%s", path, ent->d_name);

        if (lstat(new_path, &st) == -1) {
            perror("lstat");
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            if (should_ignore_dir(ent->d_name)) {
                continue;
            }
            traverse_directory(new_path, file_array, index);
        } else {
            FILE *file = fopen(new_path, "rb");
            if (file != NULL) {
                fseek(file, 0, SEEK_END);
                long file_size = ftell(file);
                fseek(file, 0, SEEK_SET);

                if (file_size > MAX_FILE_CONTENT_LENGTH) {
                    printf("Warning: File %s is too large (%ld bytes), skipping...\n", 
                           new_path, file_size);
                    fclose(file);
                    continue;
                }

                file_array[*index].content = malloc(file_size + 1);
                if (file_array[*index].content == NULL) {
                    perror("malloc");
                    fclose(file);
                    continue;
                }

                size_t bytes_read = fread(file_array[*index].content, 1, file_size, file);
                file_array[*index].content[bytes_read] = '\0';
                file_array[*index].content_size = bytes_read;

                file_array[*index].filename = strdup(new_path);
                file_array[*index].relative_path = get_relative_path(new_path);
                
                // 存储短文件名（不含路径）
                const char *basename = strrchr(new_path, '/');
                if (basename) {
                    file_array[*index].shortname = strdup(basename + 1);
                } else {
                    file_array[*index].shortname = strdup(new_path);
                }

                if (file_array[*index].filename == NULL || 
                    file_array[*index].shortname == NULL ||
                    file_array[*index].relative_path == NULL) {
                    perror("strdup");
                    if (file_array[*index].filename) free(file_array[*index].filename);
                    if (file_array[*index].shortname) free(file_array[*index].shortname);
                    if (file_array[*index].relative_path) free(file_array[*index].relative_path);
                    free(file_array[*index].content);
                    fclose(file);
                    continue;
                }

                (*index)++;
                fclose(file);
            }
        }
    }

    closedir(dir);
    return 0;
}

void display_file_content(const FileInfo *file_array, int file_count, const char *filename) {
    int found = 0;
    for (int i = 0; i < file_count; i++) {
        if (file_array[i].shortname != NULL && 
            strcmp(file_array[i].shortname, filename) == 0) {
            printf("\n=== File: %s (%s) ===\n", 
                   file_array[i].shortname, file_array[i].relative_path);
            printf("Content size: %zu bytes\n", file_array[i].content_size);
            printf("----------------------------------------\n");
            printf("%.*s\n", (int)file_array[i].content_size, file_array[i].content);
            printf("----------------------------------------\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("File '%s' not found.\n", filename);
    }
}

void free_file_info(FileInfo *file_array, int file_count) {
    for (int i = 0; i < file_count; i++) {
        if (file_array[i].filename != NULL) {
            free(file_array[i].filename);
        }
        if (file_array[i].shortname != NULL) {
            free(file_array[i].shortname);
        }
        if (file_array[i].relative_path != NULL) {
            free(file_array[i].relative_path);
        }
        if (file_array[i].content != NULL) {
            free(file_array[i].content);
        }
    }
}

void print_help() {
    printf("\nAvailable commands:\n");
    printf("  l or list      - List all files\n");
    printf("  t or tree      - Show directory tree structure\n");
    printf("  f <filename>   - Show content of specified file\n");
    printf("  h or help      - Show this help message\n");
    printf("  q or quit      - Quit the program\n\n");
}

void list_all_files(const FileInfo *file_array, int file_count) {
    printf("\nAll files (%d):\n", file_count);
    for (int i = 0; i < file_count; i++) {
        if (file_array[i].shortname != NULL) {
            printf("- %s (%s)\n", file_array[i].shortname, file_array[i].relative_path);
        }
    }
    printf("\n");
}

int main() {
    // 硬编码路径
    const char *hardcoded_path = "/home/eyk/1code/重构对流层/英语"; 
    if (realpath(hardcoded_path, base_path) == NULL) {
        perror("realpath");
        return 1;
    }
    printf("Base directory: %s\n", base_path);

    FileInfo file_array[MAX_FILES] = {0};
    int file_count = 0;

    printf("\nLoading files...\n");
    if (traverse_directory(base_path, file_array, &file_count) != 0) {
        fprintf(stderr, "Error traversing directory\n");
        return 1;
    }

    printf("\nLoaded %d files. Type 'help' for commands.\n", file_count);
    
    char input[PATH_MAX * 2];
    while (printf("\n> "), fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = 0;
        
        if (strcmp(input, "q") == 0 || strcmp(input, "quit") == 0) {
            break;
        }
        else if (strcmp(input, "h") == 0 || strcmp(input, "help") == 0) {
            print_help();
        }
        else if (strcmp(input, "l") == 0 || strcmp(input, "list") == 0) {
            list_all_files(file_array, file_count);
        }
        else if (strcmp(input, "t") == 0 || strcmp(input, "tree") == 0) {
            printf("\nDirectory tree structure:\n");
            int total_files = 0;
            print_directory_tree(base_path, 0, &total_files);
            printf("\nTotal files: %d\n", total_files);
        }
        else if (strncmp(input, "f ", 2) == 0) {
            display_file_content(file_array, file_count, input + 2);
        }
        else if (strlen(input) > 0) {
            printf("Unknown command. Type 'help' for available commands.\n");
        }
    }

    free_file_info(file_array, file_count);
    return 0;
}
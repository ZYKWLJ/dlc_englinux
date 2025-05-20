// #include "../../../include/shellText/include.h"

// // 精确查找单词

// // 章节信息结构体
// typedef struct
// {
//     int start_page;
//     int end_page;
//     int match_count;
// } Chapter;

// // 打印章节匹配统计信息
// void print_chapter_stats(Chapter *chapters, int chapter_count)
// {
//     // printf("cahapters_count=%d\n\n",chapter_count);
//     const char *chapter_names[100];
//     const char *match_counts[100];
//     chapter_names[0] = strdup("章节数");
//     match_counts[0] = strdup("匹配次数");
//     for (int i = 1; i <= chapter_count; i++)
//     {
//         char chapter_name[50];
//         char match_count_str[20];
//         sprintf(chapter_name, "第 %d 章", i);
//         sprintf(match_count_str, "%d 处匹配", chapters[i - 1].match_count);
//         chapter_names[i] = strdup(chapter_name);
//         match_counts[i] = strdup(match_count_str);
//     }
//     chapter_names[chapter_count+1] = NULL;
//     match_counts[chapter_count+1] = NULL;

//     const char **columns[] = {chapter_names, match_counts};
//     text_print_help(columns, sizeof(columns) / sizeof(columns[0]));

//     // 释放动态分配的内存
//     for (int i = 0; i < chapter_count; i++)
//     {
//         free((void *)chapter_names[i]);
//         free((void *)match_counts[i]);
//     }
// }

// int find_and_highlight(char **s, int s_size, char *t)
// {
//     // 定义章节信息
//     Chapter chapters[] = {
//         {1, 11, 0},
//         {12, 90, 0},
//         {91, 200, 0},
//         {201, 205, 0},
//         {206, 254, 0},
//         {255, 352, 0},
//         {353, 368, 0},
//         {369, 420, 0},
//         {421, s_size, 0}};
//     int chapter_count = sizeof(chapters) / sizeof(chapters[0]);

//     int flag = 0;
//     int first = 1;
//     int current_page_count = 0; // 计算本页面共有多少处匹配。
//     int total_page_count = 0;   // 计算所有页面共有多少处匹配。
//     int page_count = 0;         // 统计页面数！

//     for (int i = 0; i < s_size; i++)
//     {
//         char *p = s[i];
//         int found = 0;
//         while (*p)
//         {
//             if (strncmp(p, t, strlen(t)) == 0)
//             {
//                 found = 1;
//                 break;
//             }
//             p++;
//         }

//         if (found)
//         {
//             p = s[i];
//             while (*p) // 先计算本页面出共多少处匹配！
//             {
//                 if (strncmp(p, t, strlen(t)) == 0)
//                 {
//                     current_page_count++;
//                     p += strlen(t);
//                 }
//                 else
//                 {
//                     p++;
//                 }
//             }

//             // 统计当前页面匹配属于哪个章节
//             for (int j = 0; j < chapter_count; j++)
//             {
//                 if (i + 1 >= chapters[j].start_page && i + 1 <= chapters[j].end_page)
//                 {
//                     chapters[j].match_count += current_page_count;
//                     break;
//                 }
//             }

//             printf("%s%s\n第%d页，共%d处匹配:%s\n", BOLD, BLUE, i + 1, current_page_count, RESET);
//             total_page_count += current_page_count; // 累计总共匹配的次数！
//             current_page_count = 0;
//             page_count++; // 统计页面数！
//             p = s[i];
//             while (*p)
//             {
//                 if (strncmp(p, t, strlen(t)) == 0)
//                 {
//                     // count++;
//                     printf("%s%s%s%s", BOLD, YELLOW, t, RESET);
//                     p += strlen(t);
//                     flag = 1;
//                 }
//                 else
//                 {
//                     putchar(*p);
//                     p++;
//                 }
//             }
//             first = 0;
//             printf("\n\n");
//         }
//     }

//     // 输出每个章节的匹配数量
//     printf("\n%s%s\"%s\"%s%s%s--各章节匹配数量统计：%s\n",BOLD, RED, t, RESET,BLUE,BOLD,RESET);
//     print_chapter_stats(chapters, chapter_count);
//     printf("\n%s%s\"%s\"%s%s%s--共在%d页中出现，共%d处匹配%s\n", BOLD, RED, t, RESET, BOLD, BLUE, page_count, total_page_count, RESET);

//     return flag; // 判断是否找到！
// }

// // 函数用于获取除第一个单词外的剩余字符，给find函数使用！
// void get_remaining_chars(char *input, char *output)
// {
//     // 找到第一个空格的位置
//     char *first_space = strchr(input, ' ');
//     if (first_space != NULL)
//     {
//         // 跳过空格
//         first_space++;
//         // 将剩余字符复制到输出字符串
//         strcpy(output, first_space);
//     }
//     else
//     {
//         // 如果没有空格，输出空字符串
//         output[0] = '\0';
//     }
// }

// void text_find(char *str)
// {
//     // printf("%s%s[查找知识点 ......]> \n%s", BOLD, YELLOW, RESET);
//     // printf("查找特定的知识点。\n");
//     int size = 0;
//     for (int i = 0; strcmp(all_pages[i], "NULL"); i++) // 计算一共有多少页！软编码！方便后续加入页面！
//     {
//         size++;
//         // printf("size:%d\n",size);
//     }
//     // printf("这一步开始查找size:%d\n",size);
//     // 为 output 分配内存
//     char *output = (char *)malloc(1024); // 假设最大长度为 1024
//     if (output == NULL)
//     {
//         fprintf(stderr, "内存分配失败\n");
//         return;
//     }
//     // printf("%s%s待查找内容为text: %s%s", BOLD, YELLOW, output, RESET);
//     get_remaining_chars(str, output);
//     // printf("%s%s待查找内容为text: %s%s", BOLD, YELLOW, output, RESET);
//     if (!find_and_highlight(all_pages, size, output))
//     {
//         printf("%s%s暂无与%s相关知识点\n%s", BOLD, RED, output, RESET);
//     }
//     free(output);
//     // 这里也需要将find命令一分为二！先在前面判断出，后面再进行查找！
// }


#include "../../../include/shellText/include.h"

// Precise word search

// Chapter information structure
typedef struct {
    int start_page;
    int end_page;
    int match_count;
} Chapter;

// Print chapter matching statistics
void print_chapter_stats(Chapter *chapters, int chapter_count) {
    // printf("Chapter count=%d\n\n", chapter_count);
    const char *chapter_names[100];
    const char *match_counts[100];
    chapter_names[0] = strdup("Chapter");
    match_counts[0] = strdup("Matches");
    
    for (int i = 1; i <= chapter_count; i++) {
        char chapter_name[50];
        char match_count_str[20];
        sprintf(chapter_name, "Chapter %d", i);
        sprintf(match_count_str, "%d Matches", chapters[i - 1].match_count);
        chapter_names[i] = strdup(chapter_name);
        match_counts[i] = strdup(match_count_str);
    }
    
    chapter_names[chapter_count + 1] = NULL;
    match_counts[chapter_count + 1] = NULL;
    
    const char **columns[] = {chapter_names, match_counts};
    text_print_help(columns, sizeof(columns) / sizeof(columns[0]));
    
    // Free dynamically allocated memory
    for (int i = 0; i < chapter_count; i++) {
        free((void *)chapter_names[i]);
        free((void *)match_counts[i]);
    }
}

int find_and_highlight(char **s, int s_size, char *t) {
    // Define chapter information
    Chapter chapters[] = {
        {1, 11, 0},
        {12, 90, 0},
        {91, 200, 0},
        {201, 205, 0},
        {206, 254, 0},
        {255, 352, 0},
        {353, 368, 0},
        {369, 420, 0},
        {421, s_size, 0}
    };
    int chapter_count = sizeof(chapters) / sizeof(chapters[0]);

    int flag = 0;
    int first = 1;
    int current_page_count = 0; // Matches on current page
    int total_page_count = 0;   // Total matches across all pages
    int page_count = 0;         // Number of pages with matches

    for (int i = 0; i < s_size; i++) {
        char *p = s[i];
        int found = 0;
        
        // Check if the word exists on the page
        while (*p) {
            if (strncmp(p, t, strlen(t)) == 0) {
                found = 1;
                break;
            }
            p++;
        }

        if (found) {
            p = s[i];
            current_page_count = 0;
            
            // Count matches on current page
            while (*p) {
                if (strncmp(p, t, strlen(t)) == 0) {
                    current_page_count++;
                    p += strlen(t);
                } else {
                    p++;
                }
            }

            // Update chapter match count
            for (int j = 0; j < chapter_count; j++) {
                if (i + 1 >= chapters[j].start_page && i + 1 <= chapters[j].end_page) {
                    chapters[j].match_count += current_page_count;
                    break;
                }
            }

            // Print page results with highlighting
            printf("%s%sPage %d, %d Matches:%s\n", BOLD, BLUE, i + 1, current_page_count, RESET);
            total_page_count += current_page_count;
            page_count++;
            current_page_count = 0;
            p = s[i];
            
            while (*p) {
                if (strncmp(p, t, strlen(t)) == 0) {
                    printf("%s%s%s%s", BOLD, YELLOW, t, RESET);
                    p += strlen(t);
                    flag = 1;
                } else {
                    putchar(*p);
                    p++;
                }
            }
            first = 0;
            printf("\n\n");
        }
    }

    // Print chapter statistics
    printf("\n%s%sSearch for \"%s\"%s%s%s-- Chapter Match Statistics:%s\n", 
           BOLD, RED, t, RESET, BLUE, BOLD, RESET);
    print_chapter_stats(chapters, chapter_count);
    
    // Print summary
    printf("\n%s%s\"%s\"%s%s%s-- Found in %d pages, %d total matches%s\n", 
           BOLD, RED, t, RESET, BOLD, BLUE, page_count, total_page_count, RESET);

    return flag; // 1 if found, 0 otherwise
}

// Get remaining characters after the first word (for find command)
void get_remaining_chars(char *input, char *output) {
    char *first_space = strchr(input, ' ');
    if (first_space != NULL) {
        first_space++;
        strcpy(output, first_space);
    } else {
        output[0] = '\0';
    }
}

void text_find(char *str) {
    // Calculate total pages (soft-coded, replace with dynamic method later)
    int size = 0;
    while (strcmp(all_pages[size], "NULL") != 0) {
        size++;
    }

    char *output = (char *)malloc(1024);
    if (output == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    get_remaining_chars(str, output);
    
    if (!find_and_highlight(all_pages, size, output)) {
        printf("%s%sNo results found for \"%s\"%s\n", BOLD, RED, output, RESET);
    }
    
    free(output);
}
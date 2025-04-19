#include "../../../include/shellText/include.h"

void text_execute_two_token(char *token[], char *origin_str)
{
    // 检查是否为中文字符
    if (strcmp(token[0], "find") == 0 || strcmp(token[0], "f") == 0)
    {
        char *output = (char *)malloc(1024); // 假设最大长度为 1024
        text_find(origin_str);
        return; // 高亮并查找
    }
    if (strcmp(token[0], "list") == 0 || strcmp(token[0], "ls") == 0)
    {
        // printf("list\n");
        if (!is_all_digit(token[1]))
        {
            printf(ERROR_CHAPTER_NOT_DIGIT, BOLD, RED, token[1], RESET);
        }
        int chapter = atoi(token[1]);
        if (chapter < 0 || chapter > 9)
        {
            printf(ERROR_CHAPTER_OUT, BOLD, RED, chapter, RESET);
        }
        display_chapters(chapter);
        return;
    }
    if (strcmp(token[0], "page") == 0 || strcmp(token[0], "p") == 0)
    {
        // printf("page\n");

        if (!is_all_digit(token[1]))
        {
            printf(ERROR_PAGE_NOT_DIGIT, BOLD, RED, token[1], RESET);
        }
        int page = atoi(token[1]);
        if (page < 0 || page > 430)
        {
            printf(ERROR_PAGE_OUT, BOLD, RED, page, RESET, BOLD, YELLOW, RESET);
        }
        printf("%s\n\n", all_pages[page - 1]);
        return;
    }
    else
    {
        printf(ERROR_CMDS, BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET);
        text_find_similar_commands(origin_str);
        return;
    }
}
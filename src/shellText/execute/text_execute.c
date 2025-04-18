#include "../../../include/shellText/include.h"

void text_execute(char *str)
{
    // 1. 先将整个输入字符串转为小写
    for (char *p = str; *p; p++)
    {
        *p = tolower((unsigned char)*p); // 使用unsigned char避免符号扩展问题
    }

    // printf("this is executor\n");
    // 调用词法分析器进行分析！
    // 词法分析器的作用是将输入的字符串分割成一个个的单词（token），并返回一个指向这些单词的指针数组。
    char *origin_str = (char *)malloc(strlen(str) * sizeof(char)); // 保留原始命令！
    origin_str[strlen(str)] = '\0';                                // 防止乱码！
    strncpy(origin_str, str, strlen(str));
    int token_num;
    char *token[100];
    text_lexer(str, token, &token_num);
    if (token_num == 1)
    {
        text_execute_one_token(token, token_num, origin_str);
    }
    else if (token_num == 2)
    {
        // printf("%s\t%s\t%s\n", token[0], token[1],origin_str);
        text_execute_two_token(token, origin_str);
    }
    else if (token_num > 2)
    {
        if (strcmp(token[0], "find") == 0 || strcmp(token[0], "f") == 0)
        {
            text_find(origin_str); // 查找除了第一个单词find之外的内容！
        }
        else
        {
            printf(ERROR_CMDS, BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET);
            text_find_similar_commands(origin_str);
            return;
        }
    }
}
# include "../../../include/shellText/include.h"

// 精确查找单词
// 判断字符串是否全是中文
int find_and_highlight(char **s, int s_size, char *t)
{
    int flag = 0;
    int first = 1;
    int count = 0;
    for (int i = 0; i < s_size; i++)
    {
        char *p = s[i];
        int found = 0;
        while (*p)
        {
            if (strncmp(p, t, strlen(t)) == 0)
            {
                found = 1;
                break;
            }
            p++;
        }
        if (found)
        {
            printf("%s%s\n第%d页搜索结果:%s\n", BOLD, BLUE, i + 1, RESET);
            if (!first)
            {
                // putchar(',');
                // puts("");
            }
            p = s[i];
            while (*p)
            {
                if (strncmp(p, t, strlen(t)) == 0)
                {

                    printf("%s%s%s%s", BOLD, YELLOW, t, RESET);
                    p += strlen(t);
                    flag = 1;
                }
                else
                {
                    putchar(*p);
                    p++;
                }
            }
            first = 0;
            printf("\n\n");
        }
    }
    // printf("\n");
    return flag; // 判断是否找到！
}

// 函数用于获取除第一个单词外的剩余字符，给find函数使用！
void get_remaining_chars(char *input, char *output)
{
    // 找到第一个空格的位置
    char *first_space = strchr(input, ' ');
    if (first_space != NULL)
    {
        // 跳过空格
        first_space++;
        // 将剩余字符复制到输出字符串
        strcpy(output, first_space);
    }
    else
    {
        // 如果没有空格，输出空字符串
        output[0] = '\0';
    }
}

void text_find(char *str)
{
    // printf("%s%s[查找知识点 ......]> \n%s", BOLD, YELLOW, RESET);
    // printf("查找特定的知识点。\n");
    int size = 0;
    for (int i = 0; strcmp(all_pages[i], "NULL"); i++)
    {
        size++;
        // printf("size:%d\n",size);
    }
    // printf("这一步开始查找size:%d\n",size);
    // 为 output 分配内存
    char *output = (char *)malloc(1024); // 假设最大长度为 1024
    if (output == NULL)
    {
        fprintf(stderr, "内存分配失败\n");
        return;
    }
    // printf("%s%s待查找内容为text: %s%s", BOLD, YELLOW, output, RESET);
    get_remaining_chars(str, output);
    // printf("%s%s待查找内容为text: %s%s", BOLD, YELLOW, output, RESET);
    if (!find_and_highlight(all_pages, size, output))
    {
        printf("%s%s暂无与%s相关知识点\n%s", BOLD, RED, output, RESET);
    }
    free(output);
    // 这里也需要将find命令一分为二！先在前面判断出，后面再进行查找！
}

# include "../../../include/englinux/execute/eg_similarInstructions.h"
char *eg_instructions_all[] = {
    // 全局指令
    "help",    // 帮助指令 0
    "h",
    "find",    // 查找知识点 2
    "clear",   // 清屏 3
    "quit",    // 退出程序 4
    "q",
    "f",
    "total",
    "back",
    "b",
    "author",
    "story",
};


// 计算两个字符串的重复字符数
int eg_count_common_chars(const char *str1, const char *str2)
{
    int common = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int visited[len2];//如果正确的指令被访问过了，就置为1，否则为0！正确的！
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (tolower(str1[i]) == tolower(str2[j]) && !visited[j]/*防止重复访问*/)
            {
                common++;
                visited[j] = 1;
                break;
            }
        }
    }
    return common;
}

// Find similar commands
void eg_find_similar_commands(char *input)
{
    int input_len = strlen(input);
    int found = 0;
    // printf("Command set size: %d\n", sizeof(eg_instructions_all)/sizeof(eg_instructions_all[0]));
    
    for (int i = 0; i < sizeof(eg_instructions_all)/sizeof(eg_instructions_all[0]); i++)
    {
        int common = eg_count_common_chars(input, eg_instructions_all[i]);
        if (common > input_len / 2) // Consider commands similar if more than half the characters match
        {
            if (!found)
            {
                printf("Did you mean:\n");
                found = 1;
            }
            printf(YELLOW "%s\t" RESET, eg_instructions_all[i]);
        }
    }
    
    if (!found)
    {
        printf("No similar commands found.\n");
    }
    else
    {
        printf("\n");
    }
}
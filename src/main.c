#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
// #include <readline/history.h>
// #include <readline/readline.h>
#include "../include/shellText/include.h"

// 教材内容
void text()
{
    // 注册信号处理函数
    signal(SIGINT, text_exit_signal_handler);
    char str[1000];
    while (1)
    {
        char prompt[100];
        // sprintf(prompt, "%s%s[对流层~请输入指令]> %s", BOLD, GREEN, RESET);
        sprintf(prompt, TEXT_PROMPT, BOLD, GREEN, YELLOW, BOLD, GREEN, RESET);
        // str = readline(prompt);
        printf(prompt);
        fgets(str, 1000, stdin);
        str[strlen(str) - 1] = '\0';
        if (str == NULL)
        {
            // 用户按下 Ctrl+D
            printf("\n%s%sExiting program...%s\n", RED, BOLD, RESET);
            break;
        }
        // 执行指令
        text_execute(str); // 这里传入的是原始字符串，可能会被修改
    }
}

// 主函数
int main()
{
    system("chcp 65001 > nul"); // 隐藏命令输出
    char *str;
    text_print_copyright();
    text();
    return 0;
}

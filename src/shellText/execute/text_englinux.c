#include "../../../include/shellText/include.h"
#include "../../../include/englinux/execute/eg_execute.h"
#include "../../../include/englinux/display/eg_copyRight.h"
#include "../../../include/englinux/display/eg_prompt.h"
// 单词查询
void englinux()
{
    // 注册信号处理函数
    signal(SIGINT, text_exit_signal_handler);
    // char str[1000];
    _eg_print_copyright();
    char str[1000];
    while (1)
    {
        char prompt[100];
        // sprintf(prompt, "%s%s[对流层~请输入指令]> %s", BOLD, GREEN, RESET);
        sprintf(prompt, EG_PROMPT, BOLD, GREEN, YELLOW, BOLD, GREEN, RESET);
        // str = readli
        // ne(prompt);
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
        eg_execute(str); // 这里传入的是原始字符串，可能会被修改
        if (strcmp(str, "b") == 0 || strcmp(str, "back") == 0)
        {
            break;
        }
    }
}

#include "../../../include/shellText/include.h"
#include "../../../include/englinux/execute/eg_execute.h"
#include "../../../include/englinux/display/eg_copyRight.h"
#include "../../../include/englinux/display/eg_prompt.h"
// 单词查询
void englinux()
{
    // 注册信号处理函数
    signal(SIGINT, text_exit_signal_handler);
    char *str;
     _eg_print_copyright();
    while (1)
    {
        char prompt[100];
        sprintf(prompt, EG_PROMPT, BOLD, GREEN, YELLOW, BOLD, GREEN, RESET);
        str = readline(prompt);

        if (str == NULL)
        {
            // 用户按下 Ctrl+D
            printf("\n程序终止\n");
            break;
        }
        if (strlen(str) == 0)
        {
            // 空输入，继续循环
            free(str);
            continue;
        }

        // 复制 str
        char *str_copy = strdup(str);
        if (str_copy == NULL)
        {
            perror("内存分配失败");
            free(str);
            continue;
        }

        // 执行指令
        // printf("这里接入英语的查询\n");
        eg_execute(str);
        // 为了命令的一致性，所以把back的动作放在里面了
        if(strcmp(str,"back")==0||strcmp(str,"b")==0){
            return;
        }
        // 添加到历史记录
        add_history(str_copy); // 这里传入的是原始复制字符串，原始字符串的修改对我没影响

        // 释放复制的字符串
        free(str_copy);
        // 释放 readline 分配的内存
        free(str);
        // while (getchar()!='\n');
    }
}

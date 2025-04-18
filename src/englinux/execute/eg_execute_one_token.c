#include "../../../include/englinux/execute/eg_execute_one_token.h"
void execute_one_token(char *token[], int token_num, char *origin_str)
{
    if (strcmp(token[0], "help") == 0)
    {
        eg_help();
        find_help();
        return;
    }
    else if (strcmp(token[0], "clear") == 0)
    {
        clear();
        return;
    }
    else if (strcmp(token[0], "exit") == 0)
    {
        eg_exit_signal_handler(2);
        return;
    }
    else if (strcmp(token[0], "author") == 0)
    {
        eg_author();
        return;
    }else if (strcmp(token[0], "total") == 0)
    {
        eg_total_words();
        return;
    }else if (strcmp(token[0], "back") == 0){
        // 退出单词查询
        text_print_copyright();
        return;
    }
    // 单长度指令find、f需要单独判断！
    else if (strcmp(token[0], "find") == 0 || strcmp(token[0], "f") == 0)
    {
        printf(EG_ERROR_FIND_F_ONLY_ONE_ARGUMENT, BOLD, YELLOW, RESET);
        printf(EG_ERROR_FOR_HELP, BOLD, YELLOW, RESET);
        return;
    }
    else
    {
        // printf("%s%s%s--无效指令！%s(按下%s%shelp%s查看指令表)\n", BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET); // 这里提示的信息也是原字符串！
        printf(EG_ERROR_CMDS, BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET);
        eg_find_similar_commands(origin_str);
        return;
    }
}
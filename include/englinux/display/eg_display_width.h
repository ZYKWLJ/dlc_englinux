# ifndef _EG_DISPLAY_WIDTH_H
# define _EG_DISPLAY_WIDTH_H
#include <stdio.h>
int display_width(const char *str);

// 打印固定宽度的字符串，考虑中文字符
void print_padded(const char *str, int width);
# endif
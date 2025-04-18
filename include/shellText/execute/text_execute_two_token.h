# ifndef TWO_TOKEN_H
# define TWO_TOKEN_H
#include "../display/text_error.h"
# include "../display/text_color.h"
# include "../display/text_display.h"
#include "text_is_all_digit.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "text_find.h"
#include "text_help.h"
#include"text_parser_first_token.h"
#include"text_parser_second_token.h"
void text_execute_two_token(char*token[], char *origin_str);
#endif
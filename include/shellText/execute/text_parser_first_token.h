# ifndef PARSER_FIRST_TOKEN_H
# define PARSER_FIRST_TOKEN_H
#include "../display/text_color.h"
#include "../display/text_error.h"
#include "text_is_all_digit.h"
// #include"is_all_"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int text_parser_first_token(char *token, char *full_command);
# endif
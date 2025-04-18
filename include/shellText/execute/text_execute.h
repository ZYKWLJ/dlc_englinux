/**
 * filename:execute.h
 * description:
 * author:EthanYankang
 * create time:2025/03/31 14:43:55
 */
#ifndef _EXECUTE_H_
#define _EXECUTE_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "text_clear.h"
#include "../display/text_error.h"
#include "text_execute_one_token.h"
#include "text_execute_two_token.h"
#include "../lexer/text_lexer.h"
#include "text_is_all_digit.h"
#include "text_find.h"
void text_execute(char *str);
int is_all_digit(const char *str);
#endif
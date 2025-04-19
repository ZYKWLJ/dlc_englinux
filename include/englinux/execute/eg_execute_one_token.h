#ifndef _EG_ONE_TOKEN_H
#define _EG_ONE_TOKEN_H
#include "eg_similarInstructions.h"
#include "../display/eg_color.h"
#include "eg_find.h"
#include "eg_help.h"
#include "../display/eg_endSay.h"
#include "../display/eg_error.h"
#include "../display/eg_story.h"
#include "eg_clear.h"
#include "../display/eg_author.h"
#include "../display/eg_find_help.h"
#include "eg_parser_fourth_token.h"
#include "eg_parser_first_token.h"
#include "eg_parser_second_token.h"
#include "eg_parser_third_token.h"
#include "eg_total_words.h"
void execute_one_token(char *token[], int token_num, char *origin_str);
#endif
# include "../../../include/shellText/include.h"
void author(){
    const char*author[]={AUTHOR,AUTHOR_DESCRIPTION1,AUTHOR_DESCRIPTION2,AUTHOR_DESCRIPTION3,NULL};
    // const char* author_description[]={NULL};
    const char **columns[] = {author};
    text_print(columns, sizeof(columns) / sizeof(columns[0]));
}
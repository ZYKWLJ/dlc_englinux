# include "../../../include/shellText/include.h"

void text_clear()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

}
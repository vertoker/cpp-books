#include <iostream>
#include "string.h"

int main()
{
    const char* s1 = "first";
    const char* s2 = "second";
    char buf[100];
    char* s = buf;

    strcpy(s, s1);
    strcat(s, s2);

    std::cout << s << std::endl;

    return 0;
}
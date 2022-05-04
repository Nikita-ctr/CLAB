
#include <ctype.h>
#include <stdio.h>

char* RemoveDigits(char* input)
{
    char* dest = input;
    char* src = input;

    while(*src)
    {
        if (isdigit(*src)) { src++; continue; }
        *dest++ = *src++;
    }
    *dest = '\0';
    return input;
}

int main()
{
    char inText[] = "123 Mic2key 456";
    printf("The result is %s\n", RemoveDigits(inText));
    // Expected Output: " Mickey
}
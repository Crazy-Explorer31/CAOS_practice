#include <stdio.h>
#include <stdlib.h>

int main()
{
     const char* s1 = getenv("PATH");
     const char* s2 = getenv("A");

    // If the environment variable doesn't exist, it returns NULL
    printf("PATH: %s\n", (s1 != NULL) ? s1 : " ");
    printf("A: %s\n", (s2 != NULL) ? s2 : " ");

    return 0;
}
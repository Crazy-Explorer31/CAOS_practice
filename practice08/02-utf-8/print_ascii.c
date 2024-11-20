#include <stdio.h>

int main() {
    char str[] = {0x48, 0x69, '\0'};

    printf("%s\n", str);
    printf("%lu\n", sizeof(str));
}


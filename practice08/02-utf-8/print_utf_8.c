#include <stdio.h>

int main() {
    // unicode
    // https://symbl.cc/en/unicode-table/#cyrillic
    // ё --- u+0451

    // utf-8
    // 1 byte,  7 bit,  0xxx xxxx
    // 2 byte, 11 bit,  110xxxxx 10xxxxxx
    // 3 byte. 16 bit,  1110xxxx 10xxxxxx 10xxxxxx
    // 4 byte. 21 bit,  11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

    // ё --- u+0451
    // 00000100 01010001 => 11 значящих => 2 byte, 11 bit,  110xxxxx 10xxxxxx
    // 11010001 10010001 utf-8
    // 0xd1 91
    char str[] = {0xd1, 0x91, '\0'};
    printf("%s\n", str);
    printf("%lu\n", sizeof(str));

    // ё = е + ..
    // u+0435 u+0308
    char str1[] = {0xd0, 0xb5, 0xcc, 0x88, '\0'};
    printf("%s\n", str1);
    printf("%lu\n", sizeof(str1));

    // U+1FA77 -- heart
    char str2[] = {0xf0, 0x9f, 0xa9, 0xb7, '\0'};
    printf("%s\n", str2);
    printf("%lu\n", sizeof(str2));


    char str3[] = {0xf0, 0x9f, 0x91, 0xa8, '\0'};
    printf("%s\n", str3);
    printf("%lu\n", sizeof(str3));

    char str4[] = {0xf0, 0x9f, 0x91, 0xa8, 0xf0, 0x9f, 0x8f, 0xbd, 0x0a, '\0'};
    printf("%s\n", str4);
    printf("%lu\n", sizeof(str4));

}


/*
0 0000
1 0001
2 0010
3 0011
4 0100
5 0101
6 0110
7 0111
8 1000
9 1001
a 1010
b 1011
c 1100
d 1101
e 1110
f 1111
*/

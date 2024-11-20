#include <wchar.h>
#include <stddef.h>
#include <locale.h>

int main() {
    // Устанавливаем локаль для программу равную <<локали>> в системе
    setlocale(LC_ALL, "");

    // Unicode-символ 'Я' имеет код U+042F
    wchar_t my_char = L'\u042f';

    // wprintf преобразует utf-32 в utf-8, т.к. я установил locale для программы как
    // равную <<локали>> в системе (т.е. в utf-8)
    wprintf(L"%lc %d\n", my_char, sizeof(wchar_t));

    return 0;
}




#include <stdlib.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int mod = strtol(?, NULL, 10);
    int rfd = open(?, ?);
    int wfd = open(?, ?);

    while (1) {
        unsigned char mask;
        read(rfd, &mask, sizeof(mask));
        // а если ошибка? т.е. считали не sizeof(mask)

        for (int j = 0; j < 8; ++j) {
            // расчет суммы s с использованием i
            if (если j бит в mask 1) {
                write(wfd, &s, sizeof(s));
                // а если ошибка?
            }
         }
        i++;
    }
}

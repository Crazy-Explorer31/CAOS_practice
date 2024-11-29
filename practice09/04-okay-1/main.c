#include <stdio.h>

void okay(double a, double b, double *r);

int main(void)
{
    double a, b, r;
    okay(a, b, &r);
    printf("%g\n", r);

    return 0;
}

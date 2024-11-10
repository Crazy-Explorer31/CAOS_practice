#include <stdlib.h>

// чего перед "typedef struct RandomOperations" не хватает для успешной компиляции?
// см. слайды про список внимательно!)
typedef struct RandomOperations {
    void (*destroy)(struct RandomGenerator *p);
    int (*next)(struct RandomGenerator *p);
} RandomOperations;


// линейный конгруэнтный генератор
// https://ru.wikipedia.org/wiki/%D0%9B%D0%B8%D0%BD%D0%B5%D0%B9%D0%BD%D1%8B%D0%B9_%D0%BA%D0%BE%D0%BD%D0%B3%D1%80%D1%83%D1%8D%D0%BD%D1%82%D0%BD%D1%8B%D0%B9_%D0%BC%D0%B5%D1%82%D0%BE%D0%B4
typedef struct RandomGenerator
{
    RandomOperations ops;
    // ...
} RandomGenerator;


//NB: при обьявлении функции учтены не все требования условия
int my_rand_next(struct RandomGenerator *p) {
    // ...
}

//NB: при обьявлении функции учтены не все требования условия
void my_rand_destroy(struct RandomGenerator *p) {
    // ...
}
RandomGenerator *random_create(int you_need_good_name) {
    // тут просят calloc
    //...
    //NB: тут не учтено указание из условия
    generator->ops->destroy = my_rand_destroy;
    generator->ops->next = my_rand_next;
    //...
    return generator;
}

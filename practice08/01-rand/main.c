int main() {
    RandomGenerator *rr = random_create(1234);
    for (int j = 0; j < 100; ++j) {
        printf("%d\n", rr->ops->next(rr));
    }
    rr->ops->destroy(rr);

    /*
    Что можно понять из этого фрагмента:
        * про параметры и возвращаемое значение random_create?
        * про поля RandomGenerator?
        * про параметры функций next и destroy?
    */

    return 0;
}
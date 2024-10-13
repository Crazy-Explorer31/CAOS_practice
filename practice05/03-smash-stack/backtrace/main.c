void print_tb();

void foo() {
    print_tb();
}
void bar() {
    foo();
}
int main() {
    bar();
    return 0;
}


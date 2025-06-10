#include <iostream>
#include <thread>

struct A {
    int val  = 3;
    A() {
        std::cout << "ctor" << std::endl; // конструктор
    }
    A(const A&) {
        std::cout << "copy ctor" << std::endl; // конструктор копирования
    }
};

void thread_sum(int i, int j) {
    std::cout << "hello sum: " << i + j  << std::endl;
}

//1.
// void thread_append(A a) {
//     a.val  += 3;
// }

// 2.
void thread_append(A& a) {
    a.val  += 3;
}

int main() {
    std::thread t_sum(thread_sum, 5, 6);
    t_sum.join();

    A a;
    //1.
    // std::thread t_append(thread_append, a);
    //2.
    std::thread t_append(thread_append, std::ref(a));
    t_append.join();

    std::cout << a.val << "\n";
}

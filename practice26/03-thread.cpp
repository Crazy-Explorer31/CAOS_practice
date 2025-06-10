#include <iostream>
#include <thread> // Без .h, так как в C++ находимся!!!

void thread_func() {
    std::cout << "hello world" << std::endl;
}

int main() {
    std::thread thr(thread_func);

    thr.join(); // Обязательно использовать join, иначе будет ошибка типа "Aborted (Core dumped)"
    //thr.detach();

    // sleep(1);
    // std::this_thread::sleep_for(std::chrono::seconds(1));
}

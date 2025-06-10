#include <iostream>
#include <thread>

struct B {
    static void call_stat() {
        std::cout << "B static is called" << std::endl;
    }

    void call() {
        std::cout << "B is called" << std::endl;
    }
};


int main() {

    {
        B b;
        std::thread t_b(B::call_stat); // можем вызвать только static функции
        // Если функиця не static, то будет ошибка "invalid use of non-static member function"
        t_b.join();
        // выводит "B static is called"
    }

    {
        B b;
        std::thread t_b(&B::call, &b); // Чтобы вызвать non-static функцию, нужно указать функцию, которую
                                       // хотим вызвать, и объект, у которого эту функцию хотим вызвать
        t_b.join();
        // выводит "B is called"
    }



   // Еще можем передать lambda функцию
   int val = 5;
   std::thread t_l(
       [val]() {
           std::cout << "Lambda called with val=" << val << std::endl;
       }
   );
   t_l.join();
   // выводит "Lambda called with val=5"


}

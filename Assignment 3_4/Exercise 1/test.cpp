#include "Array_Stack.h"
#include <iostream>

int main(void)
{
    Array_stack a;
    std::cout << "Is empty: " << a.is_empty() << std::endl;
    std::cout << "Is full: " << a.is_full() << std::endl;

    a.push(10);
    a.push(20);

    std::cout << a.pull() << "\n"
              << a.pull() << std::endl;

    return 0;
}
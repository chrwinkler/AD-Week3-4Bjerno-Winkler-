#include "Array_Stack.h"
#include <iostream>

int main(void)
{
    Array_stack *a = new (Array_stack);

    std::cout << "Is empty: " << a->is_empty() << std::endl;
    std::cout << "Is full: " << a->is_full() << std::endl;

    a->push(10);
    a->push(20);
    a->push(30);

    std::cout << a->pull() << std::endl;
    std::cout << a->pull() << std::endl;
    std::cout << a->pull() << std::endl;

    for (int i = 0; i < 99; i++)
    {
        a->push(1);
    }
    std::cout << "Is full: " << a->is_full() << std::endl;

    a->push(2);

    std::cout << "Is full: " << a->is_full() << std::endl;

    return 0;
}
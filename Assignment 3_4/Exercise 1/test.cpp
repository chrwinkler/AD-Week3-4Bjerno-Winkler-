#include "Array_Stack.h"
#include <iostream>

int main(void)
{
    Array_stack *a = new (Array_stack);

    std::cout << "Is empty: " << a->is_empty() << std::endl; // Checks that the stack is empty
    std::cout << "Is full: " << a->is_full() << std::endl;   // Checks that it is not full

    a->push(10); // Pushes 3 values
    a->push(20);
    a->push(30);

    std::cout << a->pull() << std::endl;
    std::cout << a->pull() << std::endl;
    std::cout << a->pull() << std::endl; // Pulls the 3 values

    for (int i = 0; i < 99; i++) // Fills the stack with one's
    {
        a->push(1);
    }
    std::cout << "Is full: " << a->is_full() << std::endl; // Checks that it is full

    a->push(2); // Tries to push 2 to the full stack, which will extend the stack

    std::cout << "Is full: " << a->is_full() << std::endl; // Checks if the stack is full now that it has been extended

    std::cout << a->pull() << std::endl; // Pulls first 3 values at the top of the stack
    std::cout << a->pull() << std::endl;
    std::cout << a->pull() << std::endl;

    delete[] a;
    return 0;
}
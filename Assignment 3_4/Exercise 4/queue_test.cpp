#include <iostream>

#include "queue.h"

int main()
{
    Queue<int> *q = new Queue<int>();

    std::cout << "Is the queue empty: " << q->is_empty() << std::endl;
    std::cout << "Inserting 10, 20 and 30..." << std::endl;
    q->enqueue(10);
    q->enqueue(20);
    q->enqueue(30);
    std::cout << "Is the queue empty: " << q->is_empty() << std::endl;
    std::cout << "Emptying queue... \n";
    for (int i = 0; i < 3; i++)
    {
        int x = q->dequeue();
        std::cout << x << std::endl;
    }

    delete q;
    return 0;
}
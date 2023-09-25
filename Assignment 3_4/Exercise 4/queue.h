#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>
#include "stack_class.h"

template <typename T> // Template for different data types
class Queue
{

private:
    Stack<T> *stack;
    int s = 0; // Counter for number of elements in queue

public:
    Queue() { stack = new Stack<T>(); } // Constructor for stack
    ~Queue() { delete stack; }

    T dequeue() // Pop elements from queue
    {
        T m[s];

        for (int i = s - 1; i >= 0; i--) // Fills a temporary array with all elements
        {
            m[i] = stack->pop();
        }

        T x = m[0]; // Last element in queue to be returned

        for (int i = 1; i < s; i++)
        {
            stack->push(m[i]); // Inserts all other elements back into queue
        }
        s--;
        return x;
    }

    void enqueue(T x)
    {
        stack->push(x); // Uses push function from stack
        s++;
    }

    bool is_empty() // Checks if queue(stack) is empty
    {
        return stack->empty();
    }
};

#endif
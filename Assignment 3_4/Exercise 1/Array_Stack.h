#include <iostream>

using namespace std;

class Array_stack
{
private:
    int elements = 0; // Counter of actual elements in stack
    int size = 100;   // Starting size of stack
    int cur_size = size;
    int arr[]; // Array variable which holds the stack

public:
    Array_stack();

    void push(int);
    int pull();
    void DoubleA(int); // Doubles the size of the stack when needed
    bool is_full();
    bool is_empty();
};
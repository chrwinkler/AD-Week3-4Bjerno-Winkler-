#include "Array_Stack.h"

Array_stack::Array_stack() // Constructor
{
    int elements = 0;    // number of actual elements in stack
    int cur_size = size; // Setting the current size of the stack
    arr[cur_size];       // Initializing the array functioning as our stack

    for (int i = 0; i < cur_size; i++) // Stack starts full of 0
    {
        arr[i] = 0;
    }
}

bool Array_stack::is_empty()
{
    if (elements == 0) // Checks if the stack is empty
    {
        return true;
    }
    else
        return false;
}

bool Array_stack::is_full() // Compares our count of actual elements to the current size of the stack
{
    if (elements >= cur_size)
    {
        return true;
    }
    else
        return false;
}

void Array_stack::push(int x)
{
    if (is_empty() == true) // If the stack is empty, simply insert the value at index 0
    {
        arr[0] = x;
        elements += 1; // Updating number of elements in stack
    }
    if (is_full() == true) // Checks if the stack is full before pushing
    {
        cout << "Stack is full, doubling then pushing: " << x << endl;
        DoubleA(x); // If the stack is full, then double the size, then push
    }
    else
    {
        int k = 0;
        for (int i = cur_size - 1; i >= 1; i = i - 1) // If the stack is not full or empty, shift all elements one index higher
        {
            k = arr[i - 1];
            arr[i] = k;
        }
        arr[0] = x; // then insert the new element at index 0
        elements += 1;
        if (is_full() == true)
        {
            cout << "Stack is now full, pushing again will extend the stack!" << endl;
        }
    }
}

int Array_stack::pull()
{
    if (is_empty() == true) // Checks for empty stack before pulling
    {
        std::cout << "The stack is empty" << std::endl;
        return 0;
    }
    int x = arr[0]; // The element to pull is always at index 0, (unless the stack is empty)
    int k;
    for (int i = 0; i <= cur_size - 2; i++) // Shift all elements to one index lower
    {
        k = arr[i + 1];
        arr[i] = k;
    }
    elements = elements - 1; // Update actual number of elements
    return x;
}

void Array_stack::DoubleA(int x) // Function for doubling the size of the stack when full
{
    int array[cur_size * 2]; // Creates a new array of double the size
    cur_size = 2 * cur_size; // Updates our current size
    int k = 0;
    for (int i = (cur_size / 2) - 1; i >= 0; i--) // Copies the values into the new array
    {
        k = arr[i];
        array[i + 1] = k;
    }
    array[0] = x; // Pushes the value we couldn't push before to index 0

    elements += 1;

    arr[cur_size] = {0};                    // Reassigns arr to be double the size
    for (int i = cur_size / 2; i >= 0; i--) // Copies back the values into our stack
    {
        arr[i] = array[i];
    }
    cout << "The stack has been doubled in size, it now holds up to " << cur_size << " elements" << endl;
}
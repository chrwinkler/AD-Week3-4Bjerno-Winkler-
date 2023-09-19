#include "Array_Stack.h"

Array_stack::Array_stack()
{
    int cur_size = size;
    int array[cur_size];
    this->arr = array;
}

bool Array_stack::is_empty()
{
    if (this->arr[0] == 0)
    {
        return true;
    }
    else
        return false;
}

bool Array_stack::is_full()
{
    if (this->arr[cur_size - 1] != 0)
    {
        return true;
    }
    else
        return false;
}

void Array_stack::push(int x)
{
    if (is_empty())
    {
        this->arr[0] = x;
    }
    if (is_full())
    {
        DoubleA(this->arr, x);
    }
    else
    {
        int k = 0;
        for (int i = cur_size - 1; i > 0; i--)
        {
            k = this->arr[i - 1];
            this->arr[i] = k;
        }
        this->arr[0] = x;
    }
}

int Array_stack::pull()
{
    if (is_empty())
    {
        std::cout << "The stack is empty" << std::endl;
        return 0;
    }
    int x = this->arr[0];
    int k;
    for (int i = 0; i < cur_size - 2; i++)
    {
        k = this->arr[i + 1];
        this->arr[i] = k;
    }
    return x;
}

void Array_stack::DoubleA(int arr[], int x)
{
    int Darray[Dsize];
    cur_size = Dsize;
    int k = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        k = this->arr[i];
        Darray[i + 1] = k;
    }
    Darray[0] = x;
    this->arr = Darray;
}
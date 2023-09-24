#include "Array_Stack.h"

Array_stack::Array_stack()
{
    int elements = 0;
    int cur_size = size;
    int *array = new int[cur_size];
    for (int i = 0; i < cur_size; i++)
    {
        arr[i] = 0;
    }
}

bool Array_stack::is_empty()
{
    if (elements == 0)
    {
        return true;
    }
    else
        return false;
}

bool Array_stack::is_full()
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
    if (is_empty() == true)
    {
        arr[0] = x;
        elements += 1;
    }
    if (is_full() == true)
    {
        DoubleA(x);
    }
    else
    {
        int k = 0;
        for (int i = cur_size - 1; i >= 1; i = i - 1)
        {
            k = arr[i - 1];
            arr[i] = k;
        }
        arr[0] = x;
        elements += 1;
    }
}

int Array_stack::pull()
{
    if (is_empty() == true)
    {
        std::cout << "The stack is empty" << std::endl;
        return 0;
    }
    int x = arr[0];
    int k;
    for (int i = 0; i <= cur_size - 2; i++)
    {
        k = arr[i + 1];
        arr[i] = k;
    }
    elements = elements - 1;
    return x;
}

void Array_stack::DoubleA(int x)
{
    int Darray[2 * cur_size] = {0};
    cur_size = 2 * cur_size;
    int k = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        k = arr[i];
        Darray[i + 1] = k;
    }
    Darray[0] = x;
    elements += 1;

    delete[] arr;

    arr[cur_size];
    for (int i = 0; i < cur_size; i++)
    {
        arr[i] = Darray[i];
    }

    delete[] Darray;
}
#pragma once
#include <iostream>

using namespace std;

class Array_stack
{
private:
    int size = 100;
    int Dsize = 200;
    int cur_size = size;
    int *arr;

public:
    Array_stack();

    void push(int);
    int pull();
    void DoubleA(int *, int);
    bool is_full();
    bool is_empty();
};
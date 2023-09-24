#include <iostream>

using namespace std;

class Array_stack
{
private:
    int elements = 0;
    int size = 100;
    int Dsize = 200;
    int cur_size = size;
    int arr[];

public:
    Array_stack();

    void push(int);
    int pull();
    void DoubleA(int);
    bool is_full();
    bool is_empty();
};
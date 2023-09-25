#include <iostream>
#include "stdlib.h"
int search(int mat[][2], int n, int x) // mat = matrix, n is number of rows or collumns, x is the value we are searcing for
{
    if (n == 0) // If the matrix is of size zero we exit
        return -1;

    int smallest = mat[0][0], largest = mat[n - 1][n - 1]; // If x is not within the bounds of the smallest and largest value we exit
    if (x < smallest || x > largest)
        return -1;

    // set indexes for top right element
    int i = 0, j = n - 1;
    while (i < n && j >= 0) // Starts in the top right of the matrix then, compares for each collumn, when the right collumn is found
    {                       // It goes down the rows in the collumn
        if (mat[i][j] == x)
        {
            std::cout << "Element found at " << i << ", " << j << std::endl;
            return 1;
        }
        if (mat[i][j] > x)
            j--;

        // Check if mat[i][j] < x
        else
            i++;
    }

    std::cout << "n Element not found" << std::endl;
    return 0;
}

int main()
{
    int n = 2;
    int mat[2][2];
    int f = 2;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            mat[i][j] = f;
            f++;
        }
    }
    search(mat, n, 10);
    search(mat, n, 2);
    search(mat, n, 5);

    return 0;
}
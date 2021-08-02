//pointer relation with array
// link: https://www.geeksforgeeks.org/pointer-array-array-pointer/
//1 . 1D array
/*
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5] = {1, 2, 3, 45, 5};
    int *p = arr;
    int(*ptr)[5] = &arr;
    cout << sizeof(*ptr);
    cout << endl;
    cout << sizeof(*p);
}
*/

//2.2D array
// C program to print the values and
// address of elements of a 2-D array
#include <stdio.h>

int main()
{
    int arr[3][4] = {
        {10, 11, 12, 13},
        {20, 21, 22, 23},
        {30, 31, 32, 33}};
    int i, j;
    for (i = 0; i < 3; i++)
    {
        printf("Address of %dth array = %p %p\n",
               i, arr[i], *(arr + i));

        for (j = 0; j < 4; j++)
            printf("%d %d ", arr[i][j], *(*(arr + i) + j));
        printf("\n");
    }

    return 0;
}

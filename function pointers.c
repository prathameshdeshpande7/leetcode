// Online C++ compiler to run C++ program online
#include <iostream>
#include <math.h>
int compare(const void *a, const void *b)
{
    if (abs(*(int *)a) > abs(*(int *)b))
        return 1;
    return 0;
}
void bubble_sort(int *a, int n, int (*compare)(const void *a, const void *b))
{
    int i, j, temp;
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (compare (&a[j], &a[j + 1]))
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int main() {
    int i, n;
    int a[] = { 34, 65, 2, -1, -99};
    n = sizeof(a)/sizeof(a[0]);
    bubble_sort(a, n, compare);
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}

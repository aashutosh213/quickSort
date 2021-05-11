#include <iostream>

using namespace std;

void print(int arr[], int n)
{
    for (int i{0}; i < n; i++)
    {
        cout << arr[i] << " ,";
    }
    cout << endl;
}

void swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int partition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = l - 1;

    for (int j{l}; j <= h; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    return i;
}

void quickSort(int arr[], int l, int h)
{
    if (l >= h)
        return;

    int m = partition(arr, l, h);

    quickSort(arr, l, m - 1);
    quickSort(arr, m + 1, h);
}

int main()
{
    int arr[]{-12, 9, 6, 3, 5, 2, 8, -5, 1, 0};

    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    print(arr, n);

    return 0;
}
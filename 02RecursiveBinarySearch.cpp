#include <bits/stdc++.h>
using namespace std;

int RecursiveBsearch(int arr[], int low, int high, int x)

{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == x)
        return mid;

    else if (arr[mid] > x)
        return RecursiveBsearch(arr, low, mid - 1, x);

    else
        return RecursiveBsearch(arr, mid + 1, high, x);
}

int main(int argc, char const *argv[])
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << RecursiveBsearch(arr, 0, n - 1, 40);
    return 0;
}

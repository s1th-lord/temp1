// Time Complexity = O(logn) -- best Solution
// Auxilliary Space -- O(1)
#include <bits/stdc++.h>
using namespace std;

int FirstOccurrence(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else
        {
            if (mid == 0 || arr[mid - 1] != arr[mid])
                return mid;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {10, 20, 20, 40, 50, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << FirstOccurrence(arr, n, 20);
    return 0;
}

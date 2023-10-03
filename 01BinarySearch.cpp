#include<bits/stdc++.h>
using namespace std;

// Binary Search is a searching algorithm used in a sorted array by repeatedly dividing the search interval in half. 
// The idea of binary search is to use the information that the array is sorted and reduce the time complexity to O(Log n). 

int Bsearch(int arr[], int n, int x){
    int low = 0, high = n-1;
    while (low<high)
    {
        int mid = (low+high)/2;
        if (arr[mid]==x)
            return mid;
        else if(arr[mid]>x)
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
    
}
int main(int argc, char const *argv[])
{
    int arr[] = {10,20,30,40,50,60,80};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<Bsearch(arr,n,20);
    return 0;
}

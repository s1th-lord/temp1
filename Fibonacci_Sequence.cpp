#include <iostream>
using namespace std;

void fibbonaciSequence(int val, int *Array)
{
for (int i = 2; i < val; i++)
{
Array[i] = Array[i-1] + Array[i-2];
}
}

int main()
{
cout << "Enter the number of terms of series : ";
int val;
cin >> val;
int *arr = new int[val];
arr[0] = 0;
arr[1] = 1;
fibbonaciSequence(val, arr);

for (int i = 0; i < val; i++)
{
cout << arr[i] << " ";
}

delete[] arr;
}


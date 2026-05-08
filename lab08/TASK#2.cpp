#include <iostream>
using namespace std;


void func(int n)
{
    if (n <= 0)
    {
        return;
    }

    cout << n << endl;
    func(n - 1);
}



int sum(int n = 10)
{
    if (n <= 0)
    {
        return 0;
    }

    return n + sum(n - 1);
}



int max(int a[], int size)
{

    if (size == 1)
    {
        return a[0];
    }


    int m = max(a, size - 1);


    return (a[size - 1] > m) ? a[size - 1] : m;
}



int countDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }

    if (n % 10 != 0)
    {
        return 1 + countDigits(n / 10);
    }

    return countDigits(n / 10);
}



void displayDigits(int n)
{
    if (n == 0)
    {
        cout << endl;
        {
            return;
        }
    }

    cout << n % 10 << " ";
    displayDigits(n / 10);
}



int binarySearch(int a[], int low, int high, int v)
{

    if (low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;

    if (a[mid] == v)
    {
        return mid;
    }

    if (v > a[mid])
    {
        return binarySearch(a, mid + 1, high, v);
    }

    return binarySearch(a, low, mid - 1, v);
}


int main()
{
    cout << "Testing func(5):" << endl;
    func(5);

    cout << "\nTesting sum(10): " << sum(10) << endl;

    int arr[] = { 4, 9, 2, 15, 7 };
    int size = 5;

    cout << "\nTesting max(): " << max(arr, size) << endl;

    int num = 10203545;
    cout << "\nTesting countDigits(" << num << "): " << countDigits(num) << endl;

    cout << "\nTesting displayDigits(12345): ";
    displayDigits(12345);

    int sortedArr[] = { 2, 4, 6, 8, 10, 12, 14 };
    int n = 7;
    int value = 10;

    int index = binarySearch(sortedArr, 0, n - 1, value);

    cout << "\nTesting binarySearch(): " << endl;

    if (index != -1)
    {
        cout << value << " found at index " << index << endl;
    }
    else
    {
        cout << value << " not found" << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fibonacciSearch(vector<int> arr, int n, int x)
{
    int fib2 = 0;
    int fib1 = 1;
    int fib = fib2 + fib1;
 
    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    int offset = -1;
    while (fib > 1) {
        int i = min(offset + fib2, n - 1);

        if (arr[i] < x) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if (arr[i] > x) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else {
            return i;
        }
    }

    if (fib1 && arr[offset + 1] == x) {
        return offset + 1;
    }

    return -1;
}

int main()
{
    vector<int> arr = { 10, 22, 35, 40, 45, 50, 80, 82,
                        85, 90, 100, 120, 125 };
    int n = arr.size();
    int x = 85;

    int index = fibonacciSearch(arr, n, x);

    if (index == -1) {
        cout << "Element is not present in array" << endl;
    }
    else {
        cout << "Element is present at index " << index << endl;
    }

    return 0;
}

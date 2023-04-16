#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

bool myCmp(pair<int, int> a, pair<int, int> b)
{
    double r1 = (double)a.first / a.second;
    double r2 = (double)b.first / b.second;
    return r1 > r2;
}

double fknapSack(int cap, pair<int, int> a[], int n)
{
    sort(a, a + n, myCmp);
    double res = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].second <= cap)
        {
            res += a[i].first;
            cap = cap - a[i].second;
        }
        else
        {
            res += a[i].first * ((double)cap / a[i].second);
            break;
        }
    }
    return res;
}

int main()
{
    int capacity, n;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;
    cout << "Enter number of items: ";
    cin >> n;

    pair<int, int> arr[n];
    for (int i = 0; i < n; i++)
    {
        int value, weigth;
        cout << "enter value and weigth of  " << i + 1 << " item:" << endl;
        cin >> value;
        cin >> weigth;
        arr[i].first = value;
        arr[i].second = weigth;
    }

    double result = fknapSack(capacity, arr, n);
    cout << result;

    return 0;
}
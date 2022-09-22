#include <bits/stdc++.h>
using namespace std;

int max_numbers(int num)
{
    int count = 0;
    int temp = num;
    int decr = 0, max = 0;

    while (temp > 0)
    {
        count++;
        temp /= 10;
    }

    int arr[count - 1];

    while (decr < count - 1)
    {

        temp = num;

        arr[decr] = temp % 100;
        if (max < arr[decr])
        {
            max = arr[decr];
        }
        cout << arr[decr] << " ";
        num /= 10;
        decr++;
        cout << decr << " ";
    }

    return max;
}

int main()
{
    int i = 38798789;
    int res = max_numbers(i);
    cout << res << "";
}
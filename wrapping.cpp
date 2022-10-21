#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void minRectangle(int n, int minSize = 6000, int counter = 1)
{

    if (n / 3 < counter || n > 1000)
    {
        if (n == 1)
        {
            minSize = 4;
        }
        cout << minSize << endl;
        return;
    }

    if (n % counter == 0)
    {
        int row = counter;
        int column = n / counter;

        int len = n / 3;

        for (int line = 1; line < len; line++)
        {
            
            if (column % line == 0)
            {
                int col = column / line;
                int min = 2 * (row * col) + 2 * (col * line) + 2 * (row * line);
                if (minSize > min)
                {
                    minSize = min;
                }
                
            }
        }
    }
    minRectangle(n, minSize, counter + 1);
}

int main()
{
    int len;
    cin>>len;
    int arr[len-1];

    for(int i=0;i<len;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<len;i++)
    {
        minRectangle(arr[i]);
    }
    
    return 0;
}
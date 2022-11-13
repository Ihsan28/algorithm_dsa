#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string strng, int s, int e)
{
    while (s < e)
    {
        if (strng[s] != strng[e])
        {
            return false;
        }
        s++;
        e--;
    }
    return true;
}

int minPalPartion(string strng, int s, int e)
{
    if (s >= e || isPalindrome(strng, s, e))
    {
        return 0;
    }
    int ans = INT_MAX, count;

    for (int k = s; k < e; k++)
    {
        count = minPalPartion(strng, s, k) + minPalPartion(strng, k + 1, e)+1;

        ans=min(ans,count);
    }
    return ans;
}

int main()
{
    string strng = "ababbbabbababa";

    cout << minPalPartion(strng, 0, strng.length() - 1);

    return 0;
}
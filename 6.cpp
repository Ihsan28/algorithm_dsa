#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print_string(int n, vector<string> str)
{
    for (int i = 0; i < n; i++)
    {
        cout<<"Case "<<i+1<<": ";
        string s = str[i];
        int number = 0;
        string temp;

        for (int j = 0; j <= s.size(); j++)
        {
            if (s[j] >= '0' && s[j] <= '9')
            {
                number = number * 10 + (s[j] - '0');
            }
            else
            {
                if(number>0)
                {
                    
                    for (int k = 0; k < number; k++)
                    {
                        cout << temp;
                    }
                    number = 0;
                    temp = "";
                }
                temp = s[j];
                 
            }
        }
        
        cout << "\n";
    }
}

int main()
{
  int n;
  cin >> n;

  vector<string> strng;
  for (int i = 0; i < n; i++)
  {
    string str;
    cin >> str;
    strng.push_back(str);
  }
  print_string(n, strng);
  return 0;
}
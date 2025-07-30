#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s = "Trisha is Talented";
    string ans = "";
    string str = "";
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            reverse(str.begin(), str.end());
            if (!ans.empty() && !str.empty())
            {
                ans = ans + " " + str;
            }
            else
            {

                ans += str;
            }
            str = "";
        }
        else
        {
            str += s[i];
        }
    }
    if (!str.empty())
    {
        reverse(str.begin(), str.end());
        ans = ans + " " + str;
    }
    for (char i : ans)
    {
        cout << i;
    }
    return 0;
}
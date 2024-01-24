#include <bits/stdc++.h>
using namespace std;

void isValidString(string s)
{
    stack<char> stk;

    for (char c : s)
    {
        if (c == '0')
        {
            if (!stk.empty() && stk.top() == '1')
            {
                stk.pop();
            }
            else
            {
                stk.push(c);
            }
        }
        else if (c == '1')
        {
            if (!stk.empty() && stk.top() == '0')
            {
                stk.pop();
            }
            else
            {
                stk.push(c);
            }
        }
    }
    if (stk.empty())
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string s;
        cin >> s;
        isValidString(s);
    }

    return 0;
}
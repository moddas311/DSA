#include <bits/stdc++.h>
using namespace std;
void elimination(string s)
{
    stack<char> myStack;

    for (char c : s)
    {
        if (!myStack.empty() && myStack.top() == '0' && c == '1')
        {
            myStack.pop();
        }
        else
        {
            myStack.push(c);
        }
    }

    if (myStack.empty())
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
        elimination(s);
    }
    return 0;
}
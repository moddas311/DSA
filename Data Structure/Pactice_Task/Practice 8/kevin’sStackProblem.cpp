#include <bits/stdc++.h>
string kevinStackProblem(string &s)
{
    // Write your code here.
    stack<char> stk;
    for (char c : s)
    {
        stk.push(c);
    }

    string str;

    while (!stk.empty())
    {
        str.push_back(stk.top());
        stk.pop();
    }
    return str;
}

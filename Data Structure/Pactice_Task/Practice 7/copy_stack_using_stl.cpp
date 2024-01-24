#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> stk, newStk;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        stk.push(value);
    }
    while (!stk.empty())
    {
        newStk.push(stk.top());
        stk.pop();
    }
    while (!newStk.empty())
    {
        cout << newStk.top() << " ";
        newStk.pop();
    }
    return 0;
}
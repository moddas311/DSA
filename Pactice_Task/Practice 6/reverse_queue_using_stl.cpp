#include <bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> qiu;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        qiu.push(value);
    }

    stack<int> stk;
    while (!qiu.empty())
    {
        stk.push(qiu.front());
        qiu.pop();
    }

    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }

    return 0;
}
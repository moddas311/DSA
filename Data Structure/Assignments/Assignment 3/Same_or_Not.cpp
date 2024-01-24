#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    stack<int> stk;
    queue<int> qiu;

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        stk.push(value);
    }

    for (int i = 0; i < m; i++)
    {
        int value;
        cin >> value;
        qiu.push(value);
    }

    bool flag = true;

    if (stk.size() != qiu.size())
    {
        flag = false;
    }

    while (!stk.empty() && !qiu.empty())
    {
        if (stk.top() != qiu.front())
        {
            flag = false;
            break;
        }
        stk.pop();
        qiu.pop();
    }
    if (flag)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
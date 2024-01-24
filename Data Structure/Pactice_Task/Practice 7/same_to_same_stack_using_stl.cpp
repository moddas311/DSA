#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> stk;
    queue<int> qiu;
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        stk.push(value);
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int value;
        cin >> value;
        qiu.push(value);
    }

    int flag = 1;

    if (stk.size() != qiu.size())
    {
        flag = 0;
    }
    while (!stk.empty() && !qiu.empty())
    {
        if (stk.top() != qiu.front())
        {
            flag = 0;
            break;
        }
        stk.pop();
        qiu.pop();
    }
    if (flag == 1)
        cout << "YES" << endl;
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
class myStack
{
public:
    vector<int> v;
    void push(int value)
    {
        v.push_back(value);
    }
    void pop()
    {
        v.pop_back();
    }
    int top()
    {
        return v.back();
    }
    int size()
    {
        return v.size();
    }
    bool empty()
    {
        return v.empty();
    }
};
int main()
{
    myStack stk;
    myStack stk_2;
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
        stk_2.push(value);
    }

    int flag = 1;

    if (stk.size() != stk_2.size())
    {
        flag = 0;
    }
    while (!stk.empty())
    {
        if (stk.top() != stk_2.top())
        {
            flag = 0;
            break;
        }
        stk.pop();
        stk_2.pop();
    }
    if (flag == 1)
        cout << "YES" << endl;
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
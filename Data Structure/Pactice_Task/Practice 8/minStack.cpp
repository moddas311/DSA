#include <bits/stdc++.h>
class minStack
{
public:
    list<int> lst;
    stack<int> mini;

    int sz = 0;
    minStack() {}
    void push(int num)
    {
        sz++;
        lst.push_back(num);
        if (mini.empty())
        {
            mini.push(num);
        }
        else
        {
            if (num <= mini.top())
            {
                mini.push(num);
            }
        }
    }
    int pop()
    {
        if (sz == 0)
            return -1;
        else
        {
            sz--;
            if (lst.back() == mini.top())
            {
                mini.pop();
            }
            int x = lst.back();
            lst.pop_back();
            return x;
        }
    }
    int top()
    {
        if (sz == 0)
            return -1;
        else
            return lst.back();
    }
    int getMin()
    {
        if (sz == 0)
            return -1;
        else
        {
            return mini.top();
        }
    }
};
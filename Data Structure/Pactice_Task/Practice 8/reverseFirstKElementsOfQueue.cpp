#include <bits/stdc++.h>

queue<int> reverseElements(queue<int> q, int k)
{
    stack<int> stk;

    for (int i = 0; i < k; i++)
    {
        stk.push(q.front());
        q.pop();
    }

    queue<int> newQ;
    while (!q.empty())
    {
        newQ.push(q.front());
        q.pop();
    }

    while (!stk.empty())
    {
        q.push(stk.top());
        stk.pop();
    }

    while (!newQ.empty())
    {
        q.push(newQ.front());
        newQ.pop();
    }
    return q;
}

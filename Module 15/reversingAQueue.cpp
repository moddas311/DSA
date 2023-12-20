#include <bits/stdc++.h>
queue<int> reverseQueue(queue<int> q)
{
    // Write your code here.
    stack<int> copyStk;
    while (!q.empty())
    {
        copyStk.push(q.front());
        q.pop();
    }

    while (!copyStk.empty())
    {
        q.push(copyStk.top());
        copyStk.pop();
    }

    return q;
}
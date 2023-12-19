#include <bits/stdc++.h>
using namespace std;
class myQueue
{
public:
    list<int> l;
    void push(int value)
    {
        l.push_back(value);
    }

    void pop()
    {
        l.pop_front();
    }

    int front()
    {
        return l.front();
    }

    int size()
    {
        return l.size();
    }

    bool empty()
    {
        return l.empty();
    }
};
int main()
{
    myQueue q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        q.push(value);
    }

    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }

    if (!q.empty())
    {
        cout << q.front() << endl;
    }

    return 0;
}
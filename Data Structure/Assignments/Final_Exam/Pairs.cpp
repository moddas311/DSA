#include <bits/stdc++.h>
using namespace std;

class Pairs
{
public:
    string name;
    int id;
    Pairs(string name, int id)
    {
        this->name = name;
        this->id = id;
    }
};

class cmp
{
public:
    bool operator()(Pairs a, Pairs b)
    {
        if (a.name > b.name)
        {
            return true;
        }

        else if (a.name < b.name)
        {
            return false;
        }
        else
        {
            if (a.id < b.id)
            {
                return true;
            }
            else
                return false;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    priority_queue<Pairs, vector<Pairs>, cmp> cmpQ;

    for (int i = 0; i < n; i++)
    {
        string name;
        int id;
        cin >> name >> id;
        Pairs obj(name, id);
        cmpQ.push(obj);
    }

    while (!cmpQ.empty())

    {
        cout << cmpQ.top().name << " " << cmpQ.top().id << endl;
        cmpQ.pop();
    }

    return 0;
}
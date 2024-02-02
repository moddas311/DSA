#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v, c; // u-> start, v-> distance, c-> cost
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

const int N = 10e5 + 5;
int dis[N];

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edgeList;

    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edgeList.push_back(Edge(u, v, c));
        edgeList.push_back(Edge(v, u, c)); // undirected edgelist er jonno.
    }

    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }

    dis[0] = 0; // src jodi input nei tahole 0 er sthane input er src hbe .

    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge ed : edgeList)
        {
            int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;

            if (dis[u] < INT_MAX && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }

    bool cycle = false;

    for (Edge ed : edgeList)
    {
        int u, v, c;
        u = ed.u;
        v = ed.v;
        c = ed.c;

        if (dis[u] < INT_MAX && dis[u] + c < dis[v])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
    {
        cout << "Cycle Found. No answer" << endl;
    }

    else
    {
        for (int i = 0; i < n; i++)
            cout << i << "->" << dis[i] << endl;
    }
    return 0;
}
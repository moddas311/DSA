#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll mx = 1e16;
const ll N = 1005;
ll dis[N];

class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, ll c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edgeList;

    while (e--)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        edgeList.push_back(Edge(u, v, c));
    }

    int src;
    cin >> src;

    int t;
    cin >> t;

    for (int i = 1; i <= n; i++)
    {
        dis[i] = mx;
    }

    dis[src] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge ed : edgeList)
        {
            ll u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;

            if (dis[u] < mx && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }

    bool cycle = false;

    for (Edge ed : edgeList)
    {
        ll u, v, c;
        u = ed.u;
        v = ed.v;
        c = ed.c;

        if (dis[u] < mx && dis[u] + c < dis[v])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
    {
        cout << "Negative Cycle Detected" << endl;
    }

    else
    {
        while (t--)
        {
            ll dest;
            cin >> dest;

            if (dis[dest] == mx)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dis[dest] << endl;
            }
        }
    }

    return 0;
}
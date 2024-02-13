#include <bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
using namespace std;

const ll N = 1e5 + 5;
vector<pi> adjLst[N];
ll dstance[N];
ll par[N];

class cmp
{
public:
    bool operator()(pi a, pi b)
    {
        return a.second > b.second;
    }
};
void dijkstra(ll src)
{
    priority_queue<pi, vector<pi>, cmp> pQ;
    pQ.push({src, 0});
    dstance[src] = 0;

    while (!pQ.empty())
    {
        pi parent = pQ.top();
        pQ.pop();

        ll parentNode = parent.first;
        ll parentCost = parent.second;

        for (pi child : adjLst[parentNode])
        {
            ll childNode = child.first;
            ll childCost = child.second;

            if (parentCost + childCost < dstance[childNode])
            {
                dstance[childNode] = parentCost + childCost;
                pQ.push({childNode, dstance[childNode]});
                par[childNode] = parentNode;
            }
        }
    }
}
int main()
{
    ll node, edge;
    cin >> node >> edge;
    while (edge--)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adjLst[u].push_back({v, w});
        adjLst[v].push_back({u, w});
    }
    for (ll i = 1; i <= node; i++)
    {
        dstance[i] = 1e18;
        par[i] = -1;
    }

    dijkstra(1);

    if (dstance[node] == 1e18)
        cout << -1 << endl;

    else
    {
        vector<ll> path;
        ll x = node;
        while (x != -1)
        {
            path.push_back(x);
            x = par[x];
        }

        reverse(path.begin(), path.end());

        for (ll value : path)
        {
            cout << value << " ";
        }
    }
    return 0;
}
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll mx = 1e15;
const ll N = 1005;
vector<pair<int, int>> v[N];
ll dis[N];

class cmp
{
public:
    bool operator()(pair<int, ll> a, pair<int, ll> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int src)
{
    priority_queue<pair<int, ll>, vector<pair<int, ll>>, cmp> pQ;

    pQ.push({src, 0});
    dis[src] = 0;

    while (!pQ.empty())
    {
        pair<int, ll> parent = pQ.top();
        pQ.pop();

        int node = parent.first;
        ll cost = parent.second;

        for (pair<int, ll> child : v[node])
        {
            int childNode = child.first;
            ll childCost = child.second;

            if (cost + childCost < dis[childNode])
            {
                dis[childNode] = cost + childCost;
                pQ.push({childNode, dis[childNode]});
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    int src;
    cin >> src;

    int test;
    cin >> test;

    while (test--)
    {
        ll dest, maxCost;
        cin >> dest >> maxCost;

        for (int i = 0; i <= n; i++)
        {
            dis[i] = mx;
        }

        dijkstra(src);

        if (dis[dest] <= maxCost)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}

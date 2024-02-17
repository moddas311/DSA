#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;
int parent[N];
int group_size[N];

class Edge
{
public:
    int u, v;
    ll w;
    Edge(int u, int v, ll w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

void dsu_initiallize(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}

int dsu_find(int node)
{
    if (parent[node] == -1)
        return node;
    int leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}

void dsu_union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if (group_size[leaderA] > group_size[leaderB])
    {
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int main()
{
    int node, edge;
    cin >> node >> edge;
    dsu_initiallize(node);
    vector<Edge> edg_Lst;

    while (edge--)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edg_Lst.push_back(Edge(u, v, w));
    }

    sort(edg_Lst.begin(), edg_Lst.end(), cmp);
    ll totalCost = 0;
    int city = node;
    int cunt = 0;

    for (auto ed : edg_Lst)
    {
        int leaderA = dsu_find(ed.u);
        int leaderB = dsu_find(ed.v);

        if (leaderA == leaderB)
        {
            cunt++;
            continue;
        }

        else
        {
            dsu_union_by_size(ed.u, ed.v);
            totalCost += ed.w;
            city--;
        }
    }

    if (city > 1)
        cout << "Not Possible" << endl;
    else
        cout << cunt << " " << totalCost << endl;

    return 0;
}
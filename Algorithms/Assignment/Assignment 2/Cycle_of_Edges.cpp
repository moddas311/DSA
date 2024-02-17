#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N];
int group_size[N];

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

int main()
{
    int node, edge;
    cin >> node >> edge;
    int cunt = 0;
    dsu_initiallize(node);

    while (edge--)
    {
        int u, v;
        cin >> u >> v;
        int leaderA = dsu_find(u);
        int leaderB = dsu_find(v);

        if (leaderA == leaderB)
            cunt++;
        else
            dsu_union_by_size(u, v);
    }

    cout << cunt << endl;
    return 0;
}
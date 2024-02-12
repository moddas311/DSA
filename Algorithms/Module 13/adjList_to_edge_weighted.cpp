#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    int node, edge;
    cin >> node >> edge;
    vector<pair<int, int>> adjLst[node];

    while (edge--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjLst[u].push_back({v, w});
    }

    vector<Edge> edgeLst;
    for (int i = 0; i < node; i++)
    {
        for (pair<int, int> child : adjLst[i])
        {
            int childNode = child.first;
            int cost = child.second;
            edgeLst.push_back({i, childNode, cost});
        }
    }

    for (Edge edge : edgeLst)
    {
        cout << edge.u << " " << edge.v << " " << edge.w << endl;
    }

    return 0;
}
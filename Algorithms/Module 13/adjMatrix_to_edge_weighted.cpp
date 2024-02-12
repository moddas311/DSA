#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u,
        v,
        w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    int n;
    cin >> n;
    int adjMatrix[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adjMatrix[i][j];
        }
    }

    vector<Edge> edgeLst;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adjMatrix[i][j] > 0)
            {
                edgeLst.push_back({Edge(i, j, adjMatrix[i][j])});
            }
        }
    }

    for (Edge edge : edgeLst)
    {
        cout << edge.u << " " << edge.v << " " << edge.w << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node, edge;
    cin >> node >> edge;

    int adjMatrix[node][node];

    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            adjMatrix[i][j] = -1;
            if (i == j)
                adjMatrix[i][j] = 0;
        }
    }
    while (edge--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w;
    }

    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {

            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
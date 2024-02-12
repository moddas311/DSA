#include <bits/stdc++.h>
using namespace std;

void convertLstToMatrix(int n, vector<pair<int, int>> adjList[])
{
    int adjMatrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adjMatrix[i][j] = -1;
            if (i == j)
                adjMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (auto child : adjList[i])
        {
            int childNode = child.first;
            int cost = child.second;
            adjMatrix[i][childNode] = cost;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int node, edge;
    cin >> node >> edge;

    vector<pair<int, int>> adjList[node];

    while (edge--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adjList[u].push_back({v, w});
    }

    convertLstToMatrix(node, adjList);

    return 0;
}
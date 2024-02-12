#include <bits/stdc++.h>
using namespace std;

void convertLstToMatrix(int n, vector<int> adjList[])
{
    int adjMatrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adjMatrix[i][j] = 0;
            if (i == j)
                adjMatrix[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int child : adjList[i])
        {
            adjMatrix[i][child] = 1;
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

    vector<int> adjList[node];

    while (edge--)
    {
        int u, v;
        cin >> u >> v;

        // directed graph er jonno o same code just (adjList[v].push_back(u)) ei line ta ignode korlei hbe.
        adjList[u].push_back(v);
        adjList[v].push_back(u); // directed graph e ei line ta hobe na just baki sob thik thakbe.
    }

    convertLstToMatrix(node, adjList);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
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

    vector<pair<int, int>> edgeLst;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adjMatrix[i][j] == 1 && i != j)
            {
                edgeLst.push_back({i, j});
            }
        }
    }

    for (pair<int, int> edge : edgeLst)
    {
        cout << edge.first << " " << edge.second << endl;
    }
    return 0;
}
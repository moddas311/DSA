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

    vector<pair<int, int>> adjLst[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adjMatrix[i][j] > 0)
            {
                adjLst[i].push_back({j, adjMatrix[i][j]});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << "->";
        for (pair<int, int> child : adjLst[i])
        {
            cout << "{" << child.first << "," << child.second << "}";
        }
        cout << endl;
    }

    return 0;
}
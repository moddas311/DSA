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

    vector<int> adjLst[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adjMatrix[i][j] == 1 && i != j)
            {
                adjLst[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << "->";
        for (int child : adjLst[i])
        {
            cout << child << " ";
        }
        cout << endl;
    }

    return 0;
}
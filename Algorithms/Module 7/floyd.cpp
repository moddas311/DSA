#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n, e;
    cin >> n >> e;
    ll adjList[n][n];

    // every node e infinity value and i,j index e 0.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adjList[i][j] = INT_MAX;
            if (i == j)
                adjList[i][j] = 0;
        }
    }

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adjList[a][b] = c;
    }

    // protita node theke protita node

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adjList[i][k] + adjList[k][j] < adjList[i][j])
                {
                    adjList[i][j] = adjList[i][k] + adjList[k][j];
                }
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (adjList[i][j] == INT_MAX)
    //         {
    //             cout << "inf ";
    //         }
    //         else
    //         {
    //             cout << adjList[i][j] << " ";
    //         }
    //     }
    //     cout << endl;
    // }

    // jodi negetive cycle pawa jai
    for (int i = 0; i < n; i++)
    {
        if (adjList[i][i] < 0)
        {
            cout << "Cycle detected" << endl;
            break;
        }
    }

    return 0;
}
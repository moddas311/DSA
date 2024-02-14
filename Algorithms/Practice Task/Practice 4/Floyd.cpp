#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll adjList[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adjList[i][j];
            if (adjList[i][j] == -1)
            {
                adjList[i][j] = INT_MAX; 
            }
        }
    }

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

    int max_shortest_distance = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adjList[i][j] != INT_MAX && adjList[i][j] > max_shortest_distance)
            { 
                max_shortest_distance = adjList[i][j];
            }
        }
    }

    cout << max_shortest_distance << endl;

    return 0;
}

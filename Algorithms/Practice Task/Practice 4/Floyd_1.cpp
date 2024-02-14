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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adjList[i][j] == INT_MAX)
            {
                cout <<INT_MAX;
            }
            else
            {
                cout << adjList[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

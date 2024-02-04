#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll mx = 1e16;

int main()
{
    ll n, e;
    cin >> n >> e;
    ll adjList[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adjList[i][j] = mx;
            if (i == j)
                adjList[i][j] = 0;
        }
    }

    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (adjList[a][b] > c)
        {
            adjList[a][b] = c;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adjList[i][k] + adjList[k][j] < adjList[i][j])
                {
                    adjList[i][j] = adjList[i][k] + adjList[k][j];
                }
            }
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        if (adjList[x][y] == mx)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << adjList[x][y] << endl;
        }
    }

    return 0;
}
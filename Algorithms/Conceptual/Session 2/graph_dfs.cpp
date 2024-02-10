#include <bits/stdc++.h>
using namespace std;

const int N = 101;
vector<int> adjLst[N];
int visited[N];
int cnt = 0;

void dfs(int src)
{
    cnt++;
    visited[src] = true;

    for (int child : adjLst[src])
    {
        if (!visited[child])
        {
            dfs(child);
        }
    }
}

int main()
{
    int node, edge;
    cin >> node >> edge;

    while (edge--)
    {
        int u, v;
        cin >> u >> v;
        adjLst[u].push_back(v);
        adjLst[v].push_back(u);
    }

    int components = 0;
    int count = 0;

    for (int i = 1; i <= node; i++)
    {
        if (!visited[i])
        {
            cnt = 0;
            dfs(i);
            if (cnt > 1)
            {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}
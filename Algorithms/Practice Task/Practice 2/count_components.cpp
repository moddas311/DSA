#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjLst[N];
bool isVisited[N];

void dfs(int src)
{
    isVisited[src] = true;

    for (int child : adjLst[src])
    {
        if (!isVisited[child])
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
    
    int cnt = 0;

    for (int i = 0; i < node; i++)
    {
        if (!isVisited[i])
        {
            dfs(i);
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
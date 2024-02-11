#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjLst[N];
bool isVisisted[N];
int Count = 0;

void dfs(int src)
{
    Count++;
    isVisisted[src] = true;

    for (int child : adjLst[src])
    {
        if (!isVisisted[child])
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

    memset(isVisisted, false, sizeof(isVisisted));
    int n;
    cin >> n;
    dfs(n);
    cout << Count << endl;
    return 0;
}
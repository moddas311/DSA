#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjLst[N];
bool isVisited[N];
int countNode;

void dfs(int src)
{
    countNode++;
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

    memset(isVisited, false, sizeof(isVisited));

    int cnt = 0;
    vector<int> ans;

    for (int i = 0; i < node; i++)
    {
        if (!isVisited[i])
        {
            countNode = 0;
            dfs(i);
            ans.push_back(countNode);
        }
    }

    sort(ans.begin(), ans.end());

    for (int i : ans)
        cout << i << " ";
    return 0;
}
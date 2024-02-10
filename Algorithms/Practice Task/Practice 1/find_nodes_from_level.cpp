#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjLst[N];
bool isVisisted[N];

void bfs(int src, int lvl)
{
    queue<pair<int, int>> Q;
    vector<int> levelNodes;
    Q.push({src, 0});
    isVisisted[src] = true;

    while (!Q.empty())
    {
        pair<int, int> parent = Q.front();
        Q.pop();
        int node = parent.first;
        int level = parent.second;

        if (level == lvl)
        {
            levelNodes.push_back(node);
        }

        for (int child : adjLst[node])
        {
            if (!isVisisted[child])
            {
                Q.push({child, level + 1});
                isVisisted[child] = true;
            }
        }
    }
    sort(levelNodes.begin(), levelNodes.end(), greater<int>());
    for (int value : levelNodes)
    {
        cout << value << " ";
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

    int src = 0;
    int lvl;
    cin >> lvl;
    memset(isVisisted, false, sizeof(isVisisted));
    bfs(src, lvl);

    return 0;
}
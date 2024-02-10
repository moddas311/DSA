#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjLst[N];
bool isVisisted[N];

// bfs function
void bfs(int src, int dstination)
{
    queue<pair<int, int>> Q;
    Q.push({src, 0});
    isVisisted[src] = true;
    bool found = false;

    while (!Q.empty())
    {
        pair<int, int> parent = Q.front();
        Q.pop();

        int node = parent.first;
        int level = parent.second;

        if (node == dstination)
        {
            cout << level << endl;
            found = true;
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
    if (!found)
        cout << -1 << endl;
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

    int Query;
    cin >> Query;
    while (Query--)
    {
        int src, dstination;
        cin >> src >> dstination;
        memset(isVisisted, false, sizeof(isVisisted));
        bfs(src, dstination);
    }
    return 0;
}

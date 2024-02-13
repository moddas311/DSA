/* Link: https://cses.fi/problemset/submit/1667/ */

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjLst[N];
bool visited[N];
int parent[N];

void bfs(int src)
{
    queue<int> Q;
    Q.push(src);
    visited[src] = true;

    while (!Q.empty())
    {
        int par = Q.front();
        Q.pop();
        for (int child : adjLst[par])
        {
            if (!visited[child])
            {
                Q.push(child);
                visited[child] = true;
                parent[child] = par;
            }
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

    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    bfs(1);

    if (visited[1] && visited[node])
    {
        vector<int> ans;
        while (node != -1)
        {
            ans.push_back(node);
            node = parent[node];
        }

        cout << ans.size() << endl;
        reverse(ans.begin(), ans.end());

        for (int i : ans)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
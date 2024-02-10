#include <bits/stdc++.h>
using namespace std;

const int N = 101;
vector<int> adjLst[N];
int visited[N];

int bfs(int src)
{
    int count = 0;
    queue<int> Q;
    Q.push(src);
    visited[src] = true;

    while (!Q.empty())
    {
        int parent = Q.front();
        Q.pop();
        count++;

        for (int child : adjLst[parent])
        {
            if (!visited[child])
            {
                Q.push(child);
                visited[child] = true;
            }
        }
    }
    return count;
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
            int sz = bfs(i);
            if (sz > 1)
                // components++;
                count++;
        }
    }

    // cout << components << endl;
    cout << count << endl;
    return 0;
}
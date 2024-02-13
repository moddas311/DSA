#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjLst[N];
bool isVisited[N];
int dstance[N];

void bfs(int src)
{
    queue<int> Q;
    Q.push(src);
    isVisited[src] = true;
    dstance[src] = 0;

    while (!Q.empty())
    {
        int parent = Q.front();
        Q.pop();

        for (int child : adjLst[parent])
        {
            if (!isVisited[child])
            {
                isVisited[child] = true;
                Q.push(child);
                dstance[child] = dstance[parent] + 1;
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

    memset(isVisited, false, sizeof(isVisited));
    memset(dstance, -1, sizeof(dstance));

    int src, destination, k;
    cin >> src >> destination >> k;

    bfs(src);

    if (dstance[destination] != -1 && dstance[destination] <= k * 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
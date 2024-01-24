#include <bits/stdc++.h>
using namespace std;

const int N = 10e+5;
vector<int> v[N];
bool isVisited[N];

void bfs(int src)
{
    cout << src << endl;
    isVisited[src] = true;

    for (int i = 0; i < v[src].size(); i++)
    {
        int child = v[src][i];
        if (!isVisited[child])
        {
            bfs(child);
        }
    }

    // for (int child : v[src])
    // {
    //     if (!isVisited[child])
    //     {
    //         bfs(child);
    //     }
    // }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(isVisited, false, sizeof(isVisited));
    bfs(0);
    return 0;
}

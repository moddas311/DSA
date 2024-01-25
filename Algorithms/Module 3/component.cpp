#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool isVisited[1003];

void dfs(int src)
{
    cout << src << endl;
    isVisited[src] = true;

    for (int child : v[src])
    {
        if (!isVisited[child])
        {
            dfs(child);
        }
    }
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

    int components = 0;

    memset(isVisited, false, sizeof(isVisited));

    for (int i = 0; i < n; i++)
    {
        if (!isVisited[i])
        {
            dfs(i);
            components++;
        }
    }

    cout << "Components- " << components << endl;
    return 0;
}

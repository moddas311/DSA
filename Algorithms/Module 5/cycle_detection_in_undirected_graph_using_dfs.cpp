#include <bits/stdc++.h>
using namespace std;

const int N = 10e5 + 5;
vector<int> adjLst[N];
bool isVisited[N];
bool isPathVisited[N];
bool cycle;

void dfs(int src)
{
    isVisited[src] = true;
    isPathVisited[src] = true;

    for (int child : adjLst[src])
    {
        if (isPathVisited[child])
            cycle = true;

        if (!isVisited[child])
            dfs(child);
    }
    isPathVisited[src] = false;
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adjLst[a].push_back(b);
    }

    memset(isVisited, false, sizeof(isVisited));
    memset(isPathVisited, false, sizeof(isPathVisited));
    cycle = false;

    for (int i = 0; i < n; i++)
    {
        if (!isVisited[i])
        {
            dfs(i);
        }
    }

    if (cycle)
        cout << "Cycle Detected" << endl;
    else
        cout << "Cycle Not Found!" << endl;
    return 0;
}
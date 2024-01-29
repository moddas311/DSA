#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool isVisited[N];
vector<int> adjLst[N];
int parentArray[N];
bool cycle;

void bfs(int src)
{
    queue<int> Q;
    Q.push(src);
    isVisited[src] = true;

    while (!Q.empty())
    {
        int parent = Q.front();
        Q.pop();

        // cout << parent << endl;
        for (int child : adjLst[parent])
        {
            if (isVisited[child] && parentArray[parent] != child)
            {
                cycle = true;
            }

            if (!isVisited[child])
            {
                isVisited[child] = true;
                parentArray[child] = parent;
                Q.push(child);
            }
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
        adjLst[a].push_back(b);
        adjLst[b].push_back(a);
    }

    memset(isVisited, false, sizeof(isVisited));
    memset(parentArray, -1, sizeof(parentArray));
    cycle = false;

    for (int i = 0; i < n; i++)
    {
        if (!isVisited[i])
        {
            bfs(i);
        }
    }

    if (cycle)
        cout << "Cycle Found" << endl;
    else
        cout << "Cyle Not Found" << endl;
    return 0;
}
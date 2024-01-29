#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool isVisited[N];
vector<int> adjLst[N];
int parentArray[N];
bool cycle;

void dfs(int parent)
{
    isVisited[parent] = true;

    for (int child : adjLst[parent])
    {
        if (isVisited[child] && child != parentArray[parent])
        {
            cycle = true;
        }

        if (!isVisited[child])
        {
            parentArray[child] = parent;
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
            dfs(i);
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << parentArray[i] << " ";
    // }

    if (cycle)
        cout << "Cycle Found" << endl;
    else
        cout << "Cyle Not Found" << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool isVisit[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    isVisit[src] = true;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        cout << parent << endl;

        /*
        for (int i = 0; i < v[parent].size(); i++)
        {
            int child = v[parent][i];
            cout << child << endl;
        }
        */

        for (int child : v[parent])
        {
            // cout << child << endl;
            if (!isVisit[child])
            {
                q.push(child);
                isVisit[child] = true;
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
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int src;
    cin >> src;
    memset(isVisit, false, sizeof(isVisit));
    bfs(src);
    return 0;
}
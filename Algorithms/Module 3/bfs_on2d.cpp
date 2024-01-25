#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[20][20];
bool isVisited[20][20];
int level[100][100];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    else
        return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> Q;
    Q.push({si, sj});
    isVisited[si][sj] = true;
    level[si][sj] = 0;

    while (!Q.empty())
    {
        pair<int, int> parent = Q.front();
        int a = parent.first, b = parent.second;
        Q.pop();

        cout << a << " " << b << endl;

        for (int i = 0; i < d.size(); i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;

            if (isValid(ci, cj) == true && isVisited[ci][cj] == false)
            {
                Q.push({ci, cj});
                isVisited[ci][cj] = true;
                level[ci][cj] = level[a][b] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int si, sj;
    cin >> si >> sj;

    memset(isVisited, false, sizeof(isVisited));
    memset(level, -1, sizeof(level));
    bfs(si, sj);
    cout << level[0][3] << endl;

    return 0;
}
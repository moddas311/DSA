#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1001;
char adjMatrix[N][N];
bool isVisited[N][N];
pair<int, int> path[N][N];
vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

bool isValid(int i, int j)
{
    return !isVisited[i][j] && adjMatrix[i][j] != '#' && i >= 1 && i <= n && j >= 1 && j <= m;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> Q;
    Q.push({si, sj});
    isVisited[si][sj] = true;
    while (!Q.empty())
    {
        pair<int, int> parent = Q.front();
        int x = parent.first;
        int y = parent.second;
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ci = x + d[i].first;
            int cj = y + d[i].second;
            if (isValid(ci, cj))
            {
                isVisited[ci][cj] = true;
                Q.push({ci, cj});
                path[ci][cj] = {d[i].first, d[i].second};
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    int si, sj, di, dj;

    memset(isVisited, false, sizeof(isVisited));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            path[i][j] = {-1, -1};
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> adjMatrix[i][j];
            if (adjMatrix[i][j] == 'D')
            {
                si = i;
                sj = j;
            }
            if (adjMatrix[i][j] == 'R')
            {
                di = i;
                dj = j;
            }
        }
    }

    bfs(si, sj);

    if (isVisited[di][dj])
    {
        vector<pair<int, int>> ans;
        pair<int, int> des = {di, dj};

        while (des.first != si || des.second != sj)
        {
            ans.push_back({path[des.first][des.second]});
            des.first -= ans.back().first;
            des.second -= ans.back().second;
        }

        reverse(ans.begin(), ans.end());

        int s = si;
        int sr = sj;

        for (auto i : ans)
        {

            if (adjMatrix[s + i.first][sr + i.second] == '.')
            {
                adjMatrix[s + i.first][sr + i.second] = 'X';
                s = s + i.first;
                sr = sr + i.second;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << adjMatrix[i][j];
        }
        cout << endl;
    }
    return 0;
}
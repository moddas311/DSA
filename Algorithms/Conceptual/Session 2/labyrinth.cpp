#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1001;
int maze[N][N];
int isVisited[N][N];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool isValid(int ci, int cj)
{
    return !isVisited[ci][cj] && maze[ci][cj] != -1 && ci >= 0 && ci < n && cj >= 0 && cj < m;
}

void bfs(pair<int, int> src)
{
    queue<pair<int, int>> Q;
    Q.push(src);
    isVisited[src.first][src.second] = true;

    while (!Q.empty())
    {
        auto parent = Q.front();
        Q.pop();
        int x = parent.first;
        int y = parent.second;

        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isValid(newX, newY))
            {
                Q.push({newX, newY});
                isVisited[newX][newY] = true;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    pair<int, int> src, dstination;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '#')
                maze[i][j] = -1;
            if (s[j] == 'A')
                src = {i, j};
            if (s[j] == 'B')
                dstination = {i, j};
        }
    }

    bfs(src);

    if (isVisited[dstination.first][dstination.second])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
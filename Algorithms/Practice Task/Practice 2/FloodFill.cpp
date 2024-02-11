/* Link: https://leetcode.com/problems/flood-fill/description/ */

class Solution
{
public:
    int n, m;
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool isVisited[105][105];

    bool isValid(int ci, int cj)
    {
        return ci >= 0 && ci < n && cj >= 0 && cj < m;
    }

    void bfs(vector<vector<int>> &image, int sr, int sc, int color)
    {
        queue<pair<int, int>> Q;
        Q.push({sr, sc});
        isVisited[sr][sc] = true;

        int startColor = image[sr][sc];

        while (!Q.empty())
        {
            pair<int, int> parent = Q.front();
            int a = parent.first;
            int b = parent.second;
            Q.pop();

            image[a][b] = color;

            for (int i = 0; i < 4; i++)
            {
                int ci = a + d[i].first;
                int cj = b + d[i].second;

                if (isValid(ci, cj) && !isVisited[ci][cj] && image[ci][cj] == startColor)
                {
                    Q.push({ci, cj});
                    isVisited[ci][cj] = true;
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        n = image.size();
        m = image[0].size();
        memset(isVisited, false, sizeof(isVisited));

        bfs(image, sr, sc, color);

        return image;
    }
};
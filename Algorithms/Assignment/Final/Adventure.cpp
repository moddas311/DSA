#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int knapsack(int n, int weight[], int value[], int w)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }

    if (dp[n][w] != -1)
        return dp[n][w];

    if (weight[n - 1] <= w)
    {
        int op1 = knapsack(n - 1, weight, value, w - weight[n - 1]) + value[n - 1];
        int op2 = knapsack(n - 1, weight, value, w);

        return dp[n][w] = max(op1, op2);
    }

    else
    {
        int op2 = knapsack(n - 1, weight, value, w);
        return dp[n][w] = op2;
    }
}
int main()
{
    int test;
    cin >> test;

    while (test--)
    {
        memset(dp, -1, sizeof(dp));

        int n, w;

        cin >> n >> w;

        int weight[n];
        int value[n];

        for (int i = 0; i < n; i++)
        {
            cin >> weight[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> value[i];
        }

        cout << knapsack(n, weight, value, w) << endl;
    }
    return 0;
}
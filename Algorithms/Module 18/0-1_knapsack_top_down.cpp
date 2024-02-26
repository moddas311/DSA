#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e3;
const int maxW = 1e3;

int dp[maxN][maxW];

int knapsack(int n, int weight[], int value[], int W)
{

    if (n == 0 || weight == 0)
        return 0;

    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }
    if (weight[n - 1] <= W)
    {
        // duita option

        // 1. niye dekhbo
        int option_1 = knapsack(n - 1, weight, value, W - weight[n - 1]) + value[n - 1];

        // 2. na niye dekhbo
        int option_2 = knapsack(n - 1, weight, value, W);

        return dp[n][W] = max(option_1, option_2); // Complexity O(n*W).
    }

    else
    {
        // ektai option
        // 2. na niye dekha
        int option_2 = knapsack(n - 1, weight, value, W);
        return dp[n][W] = option_2;
    }
}

int main()
{
    int n;
    cin >> n;
    int weight[n], value[n];

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    int W;
    cin >> W;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << knapsack(n, weight, value, W);
    return 0;
}
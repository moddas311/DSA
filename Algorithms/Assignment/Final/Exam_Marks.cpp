#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];

bool knapsack(int n, int arr[], int w)
{
    if (n == 0)
    {
        if (w == 0)
            return 1;
        else
            return 0;
    }

    if (dp[n][w] != -1)
        return dp[n][w];

    if (arr[n - 1] <= w)
    {
        int option_1 = knapsack(n - 1, arr, w - arr[n - 1]);
        int option_2 = knapsack(n - 1, arr, w);
        return dp[n][w] = option_1 || option_2;
    }

    else
    {
        int option_2 = knapsack(n - 1, arr, w);
        return dp[n][w] = option_2;
    }
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        memset(dp, -1, sizeof(dp));
        
        int n, m;
        cin >> n >> m;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int mark = 1000 - m;
        bool possble = knapsack(n, arr, mark);

        if (possble)
            cout << "YES" << endl;

        else
            cout << "NO" << endl;
    }
    return 0;
}
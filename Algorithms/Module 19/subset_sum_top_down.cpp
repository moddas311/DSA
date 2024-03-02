#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

bool sub_set(int n, int arr[], int sum)
{

    if (n == 0)
    {
        if (sum == 0)
            return true;
        else
            return false;
    }

    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }

    if (arr[n - 1] <= sum)
    {
        bool option_1 = sub_set(n - 1, arr, sum - arr[n - 1]);
        bool option_2 = sub_set(n - 1, arr, sum);

        return dp[n][sum] = option_1 || option_2;
    }

    else
        return dp[n][sum] = sub_set(n - 1, arr, sum);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum;
    cin >> sum;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            dp[i][j] = -1;
        }
    }

    if (sub_set(n, arr, sum))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
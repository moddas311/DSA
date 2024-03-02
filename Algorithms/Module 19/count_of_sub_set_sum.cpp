// Method-1: 

/* 
#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int sub_set(int n, int arr[], int sum)
{

    if (n == 0)
    {
        if (sum == 0)
            return 1;
        else
            return 0;
    }

    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }

    if (arr[n - 1] <= sum)
    {
        int option_1 = sub_set(n - 1, arr, sum - arr[n - 1]);
        int option_2 = sub_set(n - 1, arr, sum);

        return dp[n][sum] = option_1 + option_2;
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

    cout << sub_set(n, arr, sum);
    return 0;
} 
*/

// Method-2:
#include <bits/stdc++.h>
using namespace std;

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

    int dp[n + 1][sum + 1];

    dp[0][0] = 1;
    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    /* 
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    } 
    */

    cout << dp[n][sum] << endl;
    return 0;
}
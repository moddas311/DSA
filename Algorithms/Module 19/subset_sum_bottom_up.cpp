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

    bool dp[n + 1][sum + 1];

    dp[0][0] = true;

    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                /*
                bool option_1 = dp[i - 1][j - arr[i - 1]];
                bool option_2 = dp[n - 1][j];
                dp[i][j] = option_1 || option_2;
                */

                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= sum; j++)
    //     {
    //         if (dp[i][j])
    //             cout << "T ";
    //         else
    //             cout << "F ";
    //     }
    //     cout << endl;
    // }

    if (dp[n][sum])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
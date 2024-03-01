#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;

        int totalChocolate = 0;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            totalChocolate += arr[i];
        }

        if (totalChocolate % 2 != 0)
        {
            cout << "NO" << endl;
        }

        else
        {
            int equalChocolate = totalChocolate / 2;
            int dp[n + 1][equalChocolate + 1];
            dp[0][0] = 1;
            
            for (int i = 1; i <= equalChocolate; i++)
            {
                dp[0][i] = 0;
            }

            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= equalChocolate; j++)
                {
                    if (arr[i - 1] <= j)
                    {
                        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }

            if (dp[n][equalChocolate] == 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
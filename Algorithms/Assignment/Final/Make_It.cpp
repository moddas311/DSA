#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int dp[N];

int make(int step, int n)
{
    if (step == n)
        return 1;

    if (step > n)
        return 0;

    if (dp[step] != -1)
        return dp[step];

    int option_1 = make(step + 3, n);
    int option_2 = make(step * 2, n);

    return dp[step] = option_1 || option_2;
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        memset(dp, -1, sizeof(dp));
        
        int n;
        cin >> n;

        int possible = make(1, n);
        if (possible == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
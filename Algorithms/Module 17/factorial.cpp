#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if (n == 0) // Basecase
        return 1;

    int chotoFactorial = fact(n - 1);
    return chotoFactorial * n;
}

int main()
{
    int n;
    cin >> n;
    // cout << fact(n); // factorial using recuirsion.

    int ans = 1;
    for (int i = 1; i <= n; i++) // factorial using loop.
    {
        ans *= i;
    }

    cout << ans;
    return 0;
}

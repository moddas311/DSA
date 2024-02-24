#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sum[n];
    sum[0] = 0;
    sum[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        sum[i] = sum[i - 1] + sum[i - 2];
    }

    cout << sum[n] << endl;
    return 0;
}
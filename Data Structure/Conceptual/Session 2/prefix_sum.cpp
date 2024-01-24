#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, tanel = -1;
        cin >> n;
        vector<int> a(n);

        for (int &x : a)
            cin >> x;

        vector<int> pSum(n);
        pSum[0] = a[0];

        // prefix sum.
        for (int i = 1; i < n; i++)
        {
            pSum[i] = pSum[i - 1] + a[i];
        }

        for (int i = 0; i < n; i++)
        {
            int left = pSum[i] - a[i];
            int right = pSum[n - 1] - pSum[i];

            if (left == right)
                tanel = i;
        }
        cout << tanel << endl;
    }
    return 0;
}
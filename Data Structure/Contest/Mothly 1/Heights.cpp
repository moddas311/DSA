#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    for (int i = 0; i < n; i++)
    {
        int before = -1, after = -1;

        for (int j = 0; j < i; j++)
        {
            if (h[j] > before)
            {
                before = h[j];
            }
        }

        for (int j = i + 1; j < n; j++)
        {
            if (h[j] > after)
            {
                after = h[j];
            }
        }
        cout << before << " " << after << endl;
    }
    return 0;
}
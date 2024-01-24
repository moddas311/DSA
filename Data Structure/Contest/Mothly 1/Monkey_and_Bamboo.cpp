#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int h, a, b;
        cin >> h >> a >> b;
        if (a >= h)
        {
            int time = 1;
            cout << time << endl;
        }
        else if (a <= b)
        {
            cout << "Impossible" << endl;
        }
        else
        {
            int time = ceil((h - a) / (a - b) * 2) + 1;
            cout << time << endl;
        }
    }
    return 0;
}
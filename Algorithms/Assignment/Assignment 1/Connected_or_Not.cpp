#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    int adMat[n][n];

    memset(adMat, 0, sizeof(adMat));

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        adMat[a][b] = 1;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int A, B;
        cin >> A >> B;
        if (adMat[A][B] == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            if (A == B)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    int adMatrix[n][n];

    memset(adMatrix, 0, sizeof(adMatrix));

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        adMatrix[a][b] = 1;
        adMatrix[b][a] = 1; // directed graph e ei connection thake na.
    }

    /*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adMatrix[i][j] << " ";
        }
        cout << endl;
    }
    */

    if (adMatrix[1][3] == 1)
        cout << "Connection Ache!" << endl;
    else
        cout << "Connection Nai!" << endl;
    return 0;
}
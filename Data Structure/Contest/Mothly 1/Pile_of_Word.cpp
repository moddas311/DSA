#include <bits/stdc++.h>
using namespace std;

bool pileOfWord(string s1, string s2)
{
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string S, S_2;
        cin >> S >> S_2;
        if (pileOfWord(S, S_2))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
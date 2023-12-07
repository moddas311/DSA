#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    vector<int> letterCount(26, 0);
    for (char ch : s)
    {
        letterCount[ch - 'a']++;
    }
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        if (letterCount[ch - 'a'] > 0)
        {
            cout << ch << " "
                 << ":"
                 << " " << letterCount[ch - 'a'] << endl;
        }
    }
    return 0;
}
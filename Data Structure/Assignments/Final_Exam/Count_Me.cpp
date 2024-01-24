#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin >> test;
    cin.ignore();
    while (test--)
    {
        string name;
        getline(cin, name);
        string word;
        stringstream ss(name);

        map<string, int> countMp;
        while (ss >> word)
        {
            countMp[word]++;
        }

        int maxName = 0;

        for (auto it = countMp.begin(); it != countMp.end(); it++)
        {
            maxName = max(maxName, it->second);
        }

        map<string, int> countMp_2;
        stringstream ss_2(name);

        while (ss_2 >> word)
        {
            countMp_2[word]++;
            if (maxName == countMp_2[word])
            {
                cout << word << " " << countMp_2[word] << endl;
                break;
            }
        }
    }

    return 0;
}

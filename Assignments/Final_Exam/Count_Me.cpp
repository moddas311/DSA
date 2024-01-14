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

        stringstream ss(name);
        map<string, int> countMp;

        string word;
        while (ss >> word)
        {
            countMp[word]++;
        }

        int maxNumber = 0;
        // string mostFreqName;

        for (auto it = countMp.begin(); it != countMp.end(); it++)
        {
            maxNumber = max(maxNumber, it->second);
        }

        map<string, int> countMp_2;
        stringstream ss_2(name);
        while (ss_2 >> word)
        {
            if (maxNumber == countMp_2[word])
            {
                cout << word << " " << countMp_2[word] << endl;
            }
        }
    }

    return 0;
}

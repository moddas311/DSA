#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int> mp;

    mp["Musfiqur"] = 15; // O(logN)
    mp["Masrafee"] = 02;
    mp["Shakib"] = 75;
    mp["Tamim"] = 29;

    // itarator use kore output like array
    for (auto it = mp.begin(); it != mp.end(); it++) // O(NlogN)
    {
        cout << it->first << " " << it->second << endl; // O(logN)
    }

    // count jodi hoy taile pawa jabe otherwise nai
    if (mp.count("Moddasir"))
    {
        cout << "Ache!" << endl;
    }
    else
    {
        cout << "Nai" << endl;
    }
    return 0;
}
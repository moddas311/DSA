#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    // cout << v.max_size() << endl;
    // cout << v.capacity() << endl;
    v.push_back(10);
    // cout << v.capacity() << endl;
    v.push_back(20);
    // cout << v.capacity() << endl;
    v.push_back(30);
    // cout << v.capacity() << endl;
    v.push_back(40);
    // cout << v.capacity() << endl;
    v.push_back(50);
    // cout << v.capacity() << endl;
    // v.clear(); // clear function use kore just size 0 hoy but memory theke delete hoy na.
    v.resize(2);
    v.resize(7, 50);
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    // cout << v[3]; // memory theke delete na howar karone amra chaile eivabe value gula access korte pari.
    return 0;
}
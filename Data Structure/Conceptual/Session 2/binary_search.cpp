#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    int searchItem;
    cin >> searchItem;

    int find = -1;
    int left = 0, right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (a[mid] == searchItem)
        {
            find = mid;
            left = mid + 1;  // for right most index.
            right = mid - 1; // for left most index
            break;           // left most index er jonno break kora jabe na.
        }

        else if (a[mid] < searchItem)
        {
            left = mid + 1;
        }

        else
        {
            right = mid - 1;
        }
    }

    if (find == -1)
        cout << "Found" << endl;
    else
        cout << "Not Found!" << endl;
    return 0;
}
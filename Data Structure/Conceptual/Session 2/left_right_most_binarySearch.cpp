#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &a, int searchItem, bool isLeft)
{
    int find = -1;
    int left = 0, right = a.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (a[mid] == searchItem)
        {
            find = mid;
            if (isLeft)
                right = mid - 1;
            else
                left = mid + 1;
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
    return find;
}

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

    int left = binary_search(a, searchItem, true);
    int right = binary_search(a, searchItem, false);

    // cout << left << " " << right << "mid: " << (left + right) / 2 << endl;
    cout << left - right + 1; // count how many elements ache eikhane.

    // ekoi elements ekadikbar ache kina.
    if (left != right)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
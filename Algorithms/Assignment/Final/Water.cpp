#include <bits/stdc++.h>
using namespace std;

int result_1;
int right_idx;
int result_2;
int left_idx;

void hight(int n, int arr[])
{
    if (n == 0)
        return;

    if (arr[n - 1] > result_1)
    {
        result_1 = arr[n - 1];
        right_idx = n - 1;
    }

    hight(n - 1, arr);
}

void hight_2(int n, int arr[])
{
    if (n == 0)
        return;
        
    if (arr[n - 1] > result_2 && arr[n - 1] != result_1)
    {
        result_2 = arr[n - 1];
        left_idx = n - 1;
    }
    hight_2(n - 1, arr);
}
int main()
{
    int test;
    cin >> test;

    while (test--)
    {
        result_1 = INT_MIN;
        result_2 = INT_MIN;

        left_idx = -1;
        right_idx = -1;

        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        hight(n, arr);
        hight_2(n, arr);

        if (left_idx > right_idx)
            cout << right_idx << " " << left_idx << endl;
        else
            cout << left_idx << " " << right_idx << endl;
    }

    return 0;
}
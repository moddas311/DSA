#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int weight[], int value[], int W)
{

    if (n == 0 || W == 0)
        return 0;

    if (weight[n - 1] > W)
        return knapsack(n - 1, weight, value, W);

    int include_current = value[n - 1] + knapsack(n - 1, weight, value, W - weight[n - 1]);
    int exclude_current = knapsack(n - 1, weight, value, W);

    return max(include_current, exclude_current);
}

int main()
{
    int n, W;
    cin >> n >> W;
    int weight[n], value[n];

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
    }

    cout << knapsack(n, weight, value, W);
    return 0;
}

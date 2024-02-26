#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int weight[], int value[], int W)
{

    if (n < 0 || weight == 0)
        return 0;

    if (weight[n] <= W)
    {
        // duita option

        // 1. niye dekhbo
        int option_1 = knapsack(n - 1, weight, value, W - weight[n]) + value[n];

        // 2. na niye dekhbo
        int option_2 = knapsack(n - 1, weight, value, W);

        return max(option_1, option_2);
    }

    else
    {
        // ektai option
        // 2. na niye dekha
        int option_2 = knapsack(n - 1, weight, value, W);
        return option_2;
    }
}

int main()
{
    int n;
    cin >> n;
    int weight[n], value[n];

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    int W;
    cin >> W;

    cout << knapsack(n - 1, weight, value, W);
    return 0;
}
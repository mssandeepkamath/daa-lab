#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int knapSack(int val[], int wt[], int W, int n)
{

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}

int main()
{
    int n, val[100], wt[100], W;
    cout << "Enter number of items\n";
    cin >> n;
    cout << "Enter the value of " << n << " items\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    cout << "Enter the weights of " << n << " items\n";
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    cout << "Enter the capacity of knapsack\n";
    cin >> W;
    int max_val = knapSack(val, wt, W, n);
    cout << "The maximum value that can be obtained is: " << max_val << "\n";
    cout << "DP table\n";

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "Items included are\n";
    cout << "[ ";
    int w = W;
    for (int i = n; i >= 1 && max_val >= 0; i--)
    {
        if (max_val != dp[i - 1][w])
        {
            cout << i << " ";
            max_val -= val[i - 1];
            w -= wt[i - 1];
        }
    }
    cout << " ]\n";
    return 0;
}
/**
#include <iostream>
#include <algorithm> // For min function

using namespace std;

// Coin Change - Number of Ways
int coinChangeNumWays(int coins[], int n, int amount)
{
    int dp[n+1][amount+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (i == 0) dp[i][j] = 0;
            if (j == 0) dp[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            dp[i][j] = dp[i-1][j];
            if (j >= coins[i-1])
            {
                dp[i][j] += dp[i][j - coins[i-1]];
            }
        }
    }
    return dp[n][amount];
}

// Coin Change - Minimum Number of Coins
int coinChangeMinCoins(int coins[], int n, int amount)
{
    int INF = 1e9;
    int dp[n+1][amount+1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (i == 0) dp[i][j] = INF;
            if (j == 0) dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            dp[i][j] = dp[i-1][j];
            if (j >= coins[i-1])
            {
                dp[i][j] = min(dp[i][j], dp[i][j - coins[i-1]] + 1);
            }
        }
    }
    return dp[n][amount] == INF ? -1 : dp[n][amount];
}

int main()
{
    int coins[] = {3, 8, 9};
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount = 11;

    cout << "Coin Change - Number of Ways: " << coinChangeNumWays(coins, n, amount) << endl;
    cout << "Coin Change - Minimum Number of Coins: " << coinChangeMinCoins(coins, n, amount) << endl;

    return 0;
}
**/














#include <iostream>
#include <algorithm> // For min function

const int mx = 1e3+123;
int coins[mx];
using namespace std;

// Coin Change - Number of Ways
int coinChangeNumWays(int coins[], int n, int amount)
{
    int dp[n+1][amount+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (i == 0) dp[i][j] = 0;
            if (j == 0) dp[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            dp[i][j] = dp[i-1][j];
            if (j >= coins[i-1])
            {
                dp[i][j] += dp[i][j - coins[i-1]];
            }
        }
    }
    return dp[n][amount];
}

// Coin Change - Minimum Number of Coins
int coinChangeMinCoins(int coins[], int n, int amount)
{
    int INF = 1e9;
    int dp[n+1][amount+1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (i == 0) dp[i][j] = INF;
            if (j == 0) dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            dp[i][j] = dp[i-1][j];
            if (j >= coins[i-1])
            {
                dp[i][j] = min(dp[i][j], dp[i][j - coins[i-1]] + 1);
            }
        }
    }
    return dp[n][amount] == INF ? -1 : dp[n][amount];
}

int main()
{
    int n, amount;
    cin >> n >> amount;
    for( int i = 0; i < n; i++ )
    {
        cin >> coins[i];
    }

    cout << "Coin Change - Number of Ways: " << coinChangeNumWays(coins, n, amount) << endl;
    cout << "Coin Change - Minimum Number of Coins: " << coinChangeMinCoins(coins, n, amount) << endl;

    return 0;
}

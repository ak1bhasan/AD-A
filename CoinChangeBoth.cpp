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




Coin Change - Number of Ways: 1
Coin Change - Minimum Number of Coins: 2


**/










/**

#include<bits/stdc++.h>
using namespace std;

// Changed parameter to vector<int>&
int coinChangeNumWays(const vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 0);  // Initialize all to 0
    dp[0] = 1;

    for (auto coin : coins) {  // Range-based for loop
        for (int j = coin; j <= amount; j++) {
            dp[j] += dp[j - coin];
        }
    }
    return dp[amount];
}

// Changed parameter to vector<int>&
int coinChangeMinCoins(const vector<int>& coins, int amount) {
    const int INF = 1e9;
    vector<int> dp(amount + 1, INF);  // Initialize with INF directly
    dp[0] = 0;

    for (auto coin : coins) {  // Range-based for loop
        for (int j = coin; j <= amount; j++) {
            dp[j] = min(dp[j], dp[j - coin] + 1);
        }
    }
    return dp[amount] == INF ? -1 : dp[amount];
}

int main() {
    int n, amount;
    cin >> n;
    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cin >> amount;

    cout << "Number of Ways: " << coinChangeNumWays(coins, amount) << endl;
    cout << "Minimum Coins: " << coinChangeMinCoins(coins, amount) << endl;

    return 0;
}





/**
Input:
3
3 8 9
11
*/






#include<bits/stdc++.h>
using namespace std;

int coinChangeNumWays( const vector<int> &coins, int amount )
{
    vector<int> dp(amount+1, 0);
    dp[0] = 1;

    for( auto coin : coins ) {
        for( int j = coin; j <= amount; j++ ) {
            dp[j] += dp[j-coin];
        }
    }
    return dp[amount];
}

int coinChangeMinCoins( const vector<int> &coins, int amount )
{
    int INF = 1e9;
    vector<int> dp(amount+1, INF);
    dp[0] = 0;
    for( auto coin : coins ) {
        for( int j = coin; j <= amount; j++ ) {
            dp[j] = min(dp[j], dp[j-coin]+1);
        }
    }
    return dp[amount] == INF ? -1 : dp[amount];
}

int main()
{
    int n, amount; cin >> n;
    vector<int> coins(n);
    for( int i = 0; i < n; i++ ) cin >> coins[i];
    cin >> amount;

    cout << "Number of ways: " << coinChangeNumWays( coins, amount ) << endl;
    cout << "Minimum Coins: " << coinChangeMinCoins( coins, amount ) << endl;
}

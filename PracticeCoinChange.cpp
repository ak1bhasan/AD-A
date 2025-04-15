#include<bits/stdc++.h>

const int mx = 1e5+123;
int coins[mx];

using namespace std;

int coinChangeNumWays( int coins[], int n, int amount )
{
    int dp[n+1][amount+1];

    for( int i = 0; i <= n; i++ )
    {
        for( int j = 0; j <= amount; j++ )
        {
            if( i == 0 ) dp[i][j] = 0;
            if( j == 0 ) dp[i][j] = 1;
        }
    }
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= amount; j++ )
        {
            dp[i][j] = dp[i-1][j];
            if( j >= coins[i-1] )
            {
                dp[i][j] += dp[i][j-coins[i-1]];
            }
        }
    }
    return dp[n][amount];
}

int coinChangeMinCoins( int coins[], int n, int amount )
{
    int INF = 1e9;
    int dp[n+1][amount+1];

    for( int i = 0; i <= n; i++ )
    {
        for( int j = 0; j <= amount; j++ )
        {
            if( i == 0 ) dp[i][j] = INF;
            if( j == 0 ) dp[i][j] = 0;
        }
    }

    for( int i = 0; i <= n; i++ )
    {
        for( int j = 0; j <= amount; j++ )
        {
            dp[i][j] = dp[i-1][j];
            if( j >= coins[i-1] )
            {
                dp[i][j] = min( dp[i][j], dp[i][j-coins[i-1]]+1 );
            }
        }
    }
    return dp[n][amount] == INF ? -1 : dp[n][amount];
}
int main()
{
    int n, amount;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> coins[i];
    }
    cin >> amount;

    cout << "Coin Change - Number of ways "
         << coinChangeNumWays( coins, n, amount ) << endl;
    cout << "Coin Change - Minimum Number of ways "
         << coinChangeMinCoins( coins, n, amount ) << endl;
}

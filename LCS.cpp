/**
#include<bits/stdc++.h>
using namespace std;
int lcs(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    int dp[n + 1][m + 1];

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }

            else
            {
                if(s1[i] == s2[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1],dp[i - 1][j]);
                }
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string s1; cin >> s1;
    string s2; cin >> s2;

    cout << lcs(s1, s2) << endl;
}

**/








/**
#include <bits/stdc++.h>

using namespace std;

int lcs(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    int dp[n+1][m+1];

    for (int i=0;i<=n;i++) {
        for (int j=0;j<=m;j++) {
            if (i==0 || j==0) {
                dp[i][j] = 0;
            } else {
                if (s1[i] == s2[j]) {
                    // the two characters are the same
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    // not same
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
    }

    int i=n, j=m;
    string res = "";
    while (i>=0 && j>=0) {
        if (s1[i] == s2[j]) {
            res += s1[i];
            i--;
            j--;
        } else {
            if (dp[i-1][j] >= dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    return dp[n][m];
}

int main() {
    //string s1 = "CANADA";
    //string s2 = "CAMBODIA";

    string s1,s2; cin >> s1 >> s2;

    cout << lcs(s1, s2) << endl;
}

/**
Output:

CADA
4
*/









/**
#include<bits/stdc++.h>
using namespace std;

int LCS(const string &s1, const string &s2) {
    int n = s1.length();
    int m = s2.length();

    // Create a DP table with (m+1) rows and (n+1) columns
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i-1] == s2[j-1]) {
                // Characters match - extend the LCS
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                // Take the maximum of either skipping a character from text1 or text2
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

int main() {
    string s1, s2; cin >> s1 >> s2;

    cout << "Length of Longest Common Subsequence: " << LCS(s1, s2) << endl;

    return 0;
}

**/





/**
#include<bits/stdc++.h>
using namespace std;

int lcs( const string &s1, const string &s2 )
{
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= m; j++ )
        {
            if( s1[i-1] == s2[j-1] )
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max( dp[i][j-1], dp[i-1][j] );
            }
        }
    }
    int i = n, j = m;
    string res = "";
    while(i > 0 && j > 0)
    {
        if(s1[i-1] == s2[j-1])
        {
            res += s1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] >= dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    reverse(res.begin(), res.end());
    cout << "LCS String: " << res << endl;

    return dp[n][m];
}


int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << lcs(s1,s2) << endl;
}
**/








/**
#include<bits/stdc++.h>
using namespace std;

int lcs( const string &s1, const string &s2 )
{
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n+1, vector<int> ( m+1, 0 ));
    for( int i = 1; i <= n; i++ ) {
        for( int j = 1; j <= m; j++ ) {
            if( s1[i-1] == s2[j-1] ) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max( dp[i-1][j],dp[i][j-1] );
        }
    }
    int i = n, j = m;
    string res;

    while( i > 0 && j > 0 ) {
        if( s1[i-1] == s2[j-1] ) {
            res += s1[i-1];
            i--, j--;
        }
        else if( dp[i-1][j] >= dp[i][j-1] ) i--;
        else j--;
    }
    reverse( res.begin(), res.end() );
    cout << res << endl;
    return dp[n][m];
}

int main()
{
    string s1, s2; cin >> s1 >> s2;
    cout << lcs(s1, s2) << endl;
}

**/









#include<bits/stdc++.h>
using namespace std;

int lcs( const string &s1, const string &s2 )
{
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n+1, vector<int> (m+1,0));

    for( int i = 1; i <= n; i++ ) {
        for( int j = 1; j <= m; j++ ) {
            if( s1[i-1] == s2[j-1] ) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] += max( dp[i-1][j], dp[i][j-1] );
        }
    }
    int i = n, j = m;
    string res;
    while( i > 0 && j > 0 ) {
        if( s1[i-1] == s2[j-1] ) {
            res += s1[i-1];
            i--, j--;
        }
        else if( dp[i-1][j] >= dp[i][j-1] ) i--;
        else j--;
    }
    reverse( res.begin(), res.end() );
    cout << res << endl;
    return dp[n][m];
}

int main()
{
    string s1, s2; cin >> s1 >> s2;

    cout << lcs( s1, s2 ) << endl;
}

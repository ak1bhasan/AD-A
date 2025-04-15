#include <bits/stdc++.h>

using namespace std;

int lcs(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    int dp[n+1][m+1];

    for (int i=0; i<=n; i++)
    {
        for (int j=0; j<=m; j++)
        {
            if (i==0 || j==0)
            {
                dp[i][j] = 0;
            }
            else
            {
                if (s1[i] == s2[j])
                {
                    // the two characters are the same
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    // not same
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
    }

    int i=n, j=m;
    string res = "";
    while (i>=0 && j>=0)
    {
        if (s1[i] == s2[j])
        {
            res += s1[i];
            i--;
            j--;
        }
        else
        {
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

int main()
{
    string s1 = "CANADA";
    string s2 = "CAMBODIA";
    cout << lcs(s1, s2) << endl;
}

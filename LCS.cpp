//#include<bits/stdc++.h>
//using namespace std;
//int lcs(string s1, string s2)
//{
//    int n = s1.length();
//    int m = s2.length();
//
//    int dp[n + 1][m + 1];
//
//    for(int i = 0; i <= n; i++)
//    {
//        for(int j = 0; j <= m; j++)
//        {
//            if(i == 0 || j == 0)
//            {
//                dp[i][j] = 0;
//            }
//
//            else
//            {
//                if(s1[i] == s2[j])
//                {
//                    dp[i][j] = dp[i - 1][j - 1] + 1;
//                }
//                else
//                {
//                    dp[i][j] = max(dp[i][j - 1],dp[i - 1][j]);
//                }
//            }
//        }
//    }
//    return dp[n][m];
//}
//
//int main()
//{
//    string s1;
//    cin >> s1;
//    string s2;
//    cin >> s2;
//    cout << lcs(s1, s2) << endl;
//}


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    cout << n * m / 2 << endl;

    return 0;
}

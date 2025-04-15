//#include <bits/stdc++.h>
//
//using namespace std;
//
//int knap (int weight[], int value[], int n, int capacity)
//{
//    int dp[n+1][capacity+1];
//    for (int i=0; i<=n; i++)
//    {
//        for (int w=0; w<=capacity; w++)
//        {
//            if(i == 0 || w == 0)
//            {
//                dp[i][w] = 0;
//            }
//            else
//            {
//                if (w < weight[i-1])
//                {
//                    dp[i][w] = dp[i-1][w];
//                }
//                else
//                {
//                    dp[i][w] = max(value[i-1] + dp[i-1][w-weight[i-1]],
//                                   dp[i-1][w]);
//                }
//            }
//        }
//    }
//    return dp[n][capacity];
//}
//
//int main()
//{
//    int weight[] = {2, 3, 4, 5};
//    int value[] = {1, 2, 5, 6};
//    int n = 4, capacity = 8;
//    cout << knap(weight, value, n, capacity);
//}





/**
#include <bits/stdc++.h>
using namespace std;

int knap (int weight[], int value[], int n, int capacity)
{
    int dp[n+1][capacity+1];
    for (int i=0; i<=n; i++)
    {
        for (int w=0; w<=capacity; w++)
        {
            if(i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else
            {
                if (w < weight[i-1])
                {
                    dp[i][w] = dp[i-1][w];
                }
                else
                {
                    dp[i][w] = max(value[i-1] + dp[i-1][w-weight[i-1]],
                                   dp[i-1][w]);
                }
            }
        }
    }
    return dp[n][capacity];
}

int main()
{
    int n,capacity;
    cin >> n >> capacity;
    int weight[n], value[n];

    for(int i = 0; i < n; i++)
    {
        cin >> weight[i];
        cin >> value[i];
    }

    cout << knap(weight, value, n, capacity);
}
**/












/**

#include <bits/stdc++.h>
using namespace std;

int knap(int weight[], int value[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (w < weight[i - 1]) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(
                    value[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            }
        }
    }
    return dp[n][capacity];
}

int main() {
    int n, capacity;
    cin >> n >> capacity;
    int weight[n], value[n];

    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }

    cout << knap(weight, value, n, capacity);
    return 0;
}


*/













/**


#include <bits/stdc++.h>
using namespace std;

int knap(int weight[], int value[], int n, int capacity) {
    vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (w < weight[i - 1]) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(
                    value[i - 1] + dp[i - 1]
                    [w - weight[i - 1]],
                    dp[i - 1][w] );
            }
        }
    }
    return dp[n][capacity];
}

int main() {
    int n, capacity;
    cin >> n >> capacity;
    int weight[n], value[n];

    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }

    cout << knap(weight, value, n, capacity) << endl;
    return 0;
}
/**
4 8
2 1
3 2
4 5
5 6
*/















#include<bits/stdc++.h>
using namespace std;

int knap( int weight[], int value[], int n, int capacity )
{
    vector<vector<int>> dp(n+1, vector<int> (capacity+1, 0));
    for( int i = 1; i <= n; i++ ) {
        for( int w = 1; w <= capacity; w++ ) {
            if( w < weight[i-1] ) {
                dp[i][w] = dp[i-1][w];
            }
            else dp[i][w] = ( value[i-1]+dp[i-1][w-weight[i-1]] );
        }
    }
    return dp[n][capacity];
}

int main()
{
    int n, capacity;
    cin >> n >> capacity;
    int weight[n], value[n];

    for( int i = 0; i < n; i++ ) cin >> weight[i] >> value[i];

    cout << knap( weight, value, n, capacity ) << endl;
    return 0;
}

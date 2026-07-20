#include <bits/stdc++.h>

using namespace std;

/*

taking input

for ()
    for () 

    dp[i][j] = max( dp[i-1][j] , dp[i][j-1]) - 1);

    more like dp[i][j] = max( dp[i][j] , dp[i-1][j-1] + 2);


*/

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string A, B;
    cin >> A >> B;

    vector<vector<int>> dp(n, vector<int>(m, 0));

    int ans = 0;

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {

            dp[i][j] = 0;

    
            if (i > 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j] - 1);

            if (j > 0)
                dp[i][j] = max(dp[i][j], dp[i][j - 1] - 1);

            if (A[i] == B[j]) 
            {
                if (i > 0 && j > 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
                else
                    dp[i][j] = max(dp[i][j], 2);
            }

            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << "\n";

    return 0;
}
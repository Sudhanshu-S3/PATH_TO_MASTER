#include <bits/stdc++.h>
using namespace std;

void solve() 
{
    int n;
    cin >> n;
    
    vector<int> store(n);

    for (int i = 0; i < n; i++) 
    {
        cin >> store[i];
    }
    
    sort(store.begin(), store.end());
    
    int maxTime = 400; 
    
    vector<vector<int>> dp(n + 1, vector<int>(maxTime + 1, 1e9));
    
    for (int j = 0; j <= maxTime; j++) 
    {
        dp[0][j] = 0;
    }
    
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= maxTime; j++) 
        {
            dp[i][j] = dp[i][j - 1];
            
            int costNow = dp[i - 1][j - 1] + abs(j - store[i - 1]);
            
            dp[i][j] = min(dp[i][j], costNow);
        }
    }
    
    cout << dp[n][maxTime] << "\n";
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tt;
    cin >> tt;
    while (tt--) 
    {
        solve();
    }
    
    return 0;
}
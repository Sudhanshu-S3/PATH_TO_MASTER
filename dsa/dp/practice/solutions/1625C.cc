#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, k;
    cin>>n>>l>>k;

    vector<int> d(n + 1);

    for (int i = 0; i < n; i++) 
    {
        cin >> d[i];
    }

    d[n] = l;

    vector<ll> a(n + 1);
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }

    a[n] = 0;

    ll INF = 1e18;
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, INF));

    dp[0][0] = 0;

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j <= k; j++) 
        {
            if (dp[i][j] == INF) continue;

            for (int p = i + 1; p <= n; p++) 
            {
                int r = p - i - 1;
                if (j + r <= k) 
                {
                    ll cost = 1LL * (d[p] - d[i]) * a[i];
                    dp[p][j + r] = min(dp[p][j + r], dp[i][j] + cost);
                }
            }
        }
    }

    ll ans = INF;
    for (int j = 0; j <= k; j++) 
    {
        ans = min(ans, dp[n][j]);
    }

    cout << ans << "\n";

    return 0;
}
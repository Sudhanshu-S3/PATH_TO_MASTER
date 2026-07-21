#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<ll> s(n);
    for (int i = 0; i < n; ++i) 
    {
        cin >> s[i];
    }

    sort(s.begin(), s.end());

    vector<vector<ll>> d(n, vector<ll>(n, 0));

    for (int k = 2; k <= n; ++k) 
    {
        for (int i = 0; i <= n - k; ++i) 
        {
            int j = i + k - 1;
            d[i][j] = s[j] - s[i] + min(d[i + 1][j], d[i][j - 1]);
        }
    }

    cout << d[0][n - 1] << "\n";
    
    return 0;
}
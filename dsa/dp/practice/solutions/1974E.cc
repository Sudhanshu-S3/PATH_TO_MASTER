#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() 
{
    ll m,x;
    cin >> m >> x;

    vector<ll> c(m);
    vector<ll> h(m);

    ll s = 0;

    for (int i = 0; i < m; ++i) 
    {
        cin >> c[i] >> h[i];
        s += h[i];
    }

    vector<ll> d(s + 1, 1e18);
    d[0] = 0;
    ll k = 0;

    for (int i = 0; i < m; ++i) 
    {
        k += h[i];
        for (int j = k; j >= h[i]; --j) 
        {
            if (d[j - h[i]] + c[i] <= i * x) 
            {
                d[j] = min(d[j], d[j - h[i]] + c[i]);
            }
        }
    }

    int mmax = 0;
    for (int j = 0; j <= s; ++j) 
    {
        if (d[j] < 1e18) mmax = j;
    }
    cout << mmax << "\n";
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) solve();
    return 0;
}
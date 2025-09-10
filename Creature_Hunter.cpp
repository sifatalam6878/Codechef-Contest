#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool ok(ll h, vector<ll>& s, vector<ll>& d, ll t)
{
    ll dmg = 0;
    ll mx1 = 0, mx2 = 0;
    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        dmg = max(dmg, (t / s[i]) * d[i]);
        if (s[i] == 1) mx1 = max(mx1, d[i]);
        else mx2 = max(mx2, d[i]);
    }
    for(ll x = 0; x * 2 <= t; x++)
    {
        ll y = t - x * 2;
        ll now = x * mx2 + y * mx1;
        dmg = max(dmg, now);
    }
    return dmg >= h;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        ll h;
        cin >> n >> h;
        vector<ll> s(n), d(n);
        ll mx = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> s[i] >> d[i];
            mx = max(mx, d[i]);
        }
        ll l = 1, r = ((h + mx - 1) / mx) * 2, ans = r;
        while(l <= r)
        {
            ll m = (l + r) / 2;
            if(ok(h, s, d, m))
            {
                ans = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

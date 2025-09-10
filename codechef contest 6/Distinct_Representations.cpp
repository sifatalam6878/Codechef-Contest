#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int MX = 200005;

long long fact[MX], invFact[MX];

// Binary exponentiation
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// Precompute factorial and inverse factorial
void precompute() {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < MX; i++) {
        fact[i] = fact[i - 1] * i % mod;
        invFact[i] = binpow(fact[i], mod - 2);
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % mod * invFact[n - r] % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    precompute();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int a = 0, b = 0;
        for (int i = 0; i < n;) {
            if (i + 1 < n && s[i] == '1' && s[i + 1] == '0') {
                b++;
                i += 2;
            } else if (s[i] == '1') {
                i++;
            } else {
                int cnt = 0;
                while (i < n && s[i] == '0') {
                    cnt++;
                    i++;
                }
                a += cnt / 2;
            }
        }

        cout << nCr(a + b, a) << '\n';
    }

    return 0;
}

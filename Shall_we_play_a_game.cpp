#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAX_N = 1000;
int pow2[MAX_N + 1];
void precom()
{
    pow2[0] = 1;
    for(int i = 1; i <= MAX_N; ++i)
    {
        pow2[i] = (pow2[i-1] * 2) % MOD;
    }
}

int solve(int N)
{
    if(N % 2 == 1)
    {
        return pow2[N-1];
    }
    else
    {
        return (3LL * pow2[N-2]) % MOD;
    }
}

int main()
{
    precom();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // dp[i][k][x] = max sum after processing i elements, using k coins, with x actions
    vector<vector<vector<long long>>> dp(2, vector<vector<long long>>(2 * N + 1, vector<long long>(N + 1, -INF)));
    dp[0][0][0] = 0;

    for (int i = 0; i < N; i++) {
        // Clear the next layer
        for (int k = 0; k <= 2 * N; k++) {
            for (int x = 0; x <= N; x++) {
                dp[(i + 1) % 2][k][x] = -INF;
            }
        }

        // Transitions
        for (int k = 0; k <= 2 * N; k++) {
            for (int x = 0; x <= N; x++) {
                if (dp[i % 2][k][x] == -INF) continue;

                // Option 1: Do nothing
                dp[(i + 1) % 2][k][x] = max(dp[(i + 1) % 2][k][x], dp[i % 2][k][x]);

                // Option 2: Pay 1 coin to add A[i]
                if (k + 1 <= 2 * N && x + 1 <= N) {
                    dp[(i + 1) % 2][k + 1][x + 1] = max(dp[(i + 1) % 2][k + 1][x + 1], dp[i % 2][k][x] + A[i]);
                }

                // Option 3: Pay 2 coins to add A[i] + x
                if (k + 2 <= 2 * N && x + 1 <= N) {
                    dp[(i + 1) % 2][k + 2][x + 1] = max(dp[(i + 1) % 2][k + 2][x + 1], dp[i % 2][k][x] + A[i] + x);
                }
            }
        }
    }

    // Compute max sum for each K from 1 to 2*N
    for (int k = 1; k <= 2 * N; k++) {
        long long ans = -INF;
        for (int x = 0; x <= N; x++) {
            ans = max(ans, dp[N % 2][k][x]);
        }
        cout << ans << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, X;
    cin >> N >> X;
    vector<int> P(N + 1, 0); // 1-based indexing
    vector<bool> used(N + 1, false);
    int count = 0;

    for (int i = 1; i <= N; ++i) {
        int Pi = X & (~i);
        if (Pi >= 1 && Pi <= N && !used[Pi]) {
            P[i] = Pi;
            used[Pi] = true;
            count++;
        }
    }

    // Fill the remaining positions with unused numbers
    int current = 1;
    for (int i = 1; i <= N; ++i) {
        if (P[i] == 0) {
            while (used[current]) {
                current++;
            }
            P[i] = current;
            used[current] = true;
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << P[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
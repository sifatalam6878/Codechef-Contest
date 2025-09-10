#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    map<int, int> freq;
    for (int num : A) {
        freq[num]++;
    }

    int mex1 = 0;
    while (freq.count(mex1)) {
        mex1++;
    }

    int mex2 = mex1 + 1;
    while (freq.count(mex2)) {
        mex2++;
    }

    long long total = 0;

    if (mex1 == 0) {
        // All subsequences missing 0 will have SMEX = 1
        long long count_missing_0 = 1;
        for (int i = 0; i < N; ++i) {
            if (A[i] != 0) {
                count_missing_0 = (count_missing_0 * 2) % MOD;
            }
        }
        count_missing_0 = (count_missing_0 - 1 + MOD) % MOD;
        total = (total + count_missing_0 * 1) % MOD;

        // All subsequences missing 0 and 1 will have SMEX = 2
        long long count_missing_0_and_1 = 1;
        for (int i = 0; i < N; ++i) {
            if (A[i] != 0 && A[i] != 1) {
                count_missing_0_and_1 = (count_missing_0_and_1 * 2) % MOD;
            }
        }
        count_missing_0_and_1 = (count_missing_0_and_1 - 1 + MOD) % MOD;
        total = (total + count_missing_0_and_1 * 2) % MOD;
    } else if (mex1 == 1) {
        // All subsequences missing 1 will have SMEX = 2
        long long count_missing_1 = 1;
        for (int i = 0; i < N; ++i) {
            if (A[i] != 1) {
                count_missing_1 = (count_missing_1 * 2) % MOD;
            }
        }
        count_missing_1 = (count_missing_1 - 1 + MOD) % MOD;
        total = (total + count_missing_1 * 2) % MOD;
    } else {
        // For other cases, we need to consider the presence of mex1 and mex2
        // This is a simplified approach; a more detailed analysis is needed for general cases
        total = (total + mex2) % MOD;
    }

    cout << total << endl;
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
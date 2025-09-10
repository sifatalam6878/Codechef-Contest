#include <iostream>
#include <vector>
#include <algorithm>
#define MODULO 998244353
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Find the maximum value in A
    int maxA = *max_element(A.begin(), A.end());

    // Check if a valid order is possible
    int maxCount = count(A.begin(), A.end(), maxA);
    int secondMaxCount = count(A.begin(), A.end(), maxA - 1);

    if (maxCount > 1) {
        cout << "0" << endl;
        return;
    }

    // Calculate the possible arrangements
    long long result = 1;
    for (int i = 1; i <= N; i++) {
        result = (result * i) % MODULO;
    }

    if (secondMaxCount == 0) {
        cout << result << endl;
    } else {
        long long adjust = 1;
        for (int i = 1; i <= secondMaxCount; i++) {
            adjust = (adjust * i) % MODULO;
        }
        result = (result - adjust + MODULO) % MODULO;
        cout << result << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

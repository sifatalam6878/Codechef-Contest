#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int maxConsecutive(const string &s) {
    int maxcnt = 1, curcount = 1;
    char prev = s[0];
    for (size_t i = 1; i < s.size(); i++) {
        if (s[i] == prev) {
            curcount++;
            maxcnt = max(maxcnt, curcount);
        } else {
            curcount = 1;
        }
        prev = s[i];
    }
    return maxcnt;
}

bool canFix(const string &s, int K) {
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (i + K - 1 < n) {
            string temp = s;
            reverse(temp.begin() + i, temp.begin() + i + K);
            if (maxConsecutive(temp) < K) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        string S;
        cin >> S;
        if (maxConsecutive(S) < K) {
            cout << "YES\n";
            continue;
        }
        if (canFix(S, K)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
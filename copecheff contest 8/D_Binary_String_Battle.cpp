#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    
    int ones = 0;
    for (char c : s) {
        if (c == '1') {
            ones++;
        }
    }
    
    if (ones == 0) {
        cout << "Alice\n";
        return;
    }
    
    if (k == 1) {
        cout << "Alice\n";
        return;
    }
    
    if (ones <= k) {
        cout << "Alice\n";
        return;
    }
    
    cout << "Bob\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
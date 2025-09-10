#include <iostream>
#include <string>
using namespace std;

void solve() { 
    int n, k; 
    cin >> n >> k;
    
    if (k > n) {
        cout << "-1\n";
        return;
    }

    string base = "ABC";
    string S = "", T = "";
    
    for (int i = 0; i < k; i++) {
        S += base[i % 3];
        T += base[i % 3];
    }
    
    for (int i = k; i < n; i++) {
        S += base[i % 3];
        T += base[(i + 1) % 3];
    }
    
    cout << S << "\n" << T << "\n";
}

int main() { 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
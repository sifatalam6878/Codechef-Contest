#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int N;
    cin >> N;
    
    if (N == 1) {
        cout << -1 << endl;
        return;
    }
    
    vector<int> arr;
    
    if (N % 2 == 0) {
        for (int i = 0; i < N / 2; ++i) {
            arr.push_back(1);
            arr.push_back(-1);
        }
    } else {
        arr.push_back(1);
        arr.push_back(2);
        arr.push_back(-3);
        for (int i = 3; i < N; i += 2) {
            arr.push_back(1);
            arr.push_back(-1);
        }
    }
    
    for (int num : arr) {
        cout << num << " ";
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
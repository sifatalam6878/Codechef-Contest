#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, K, D;
        cin >> N >> K >> D;
        vector<int> T(N);
        for (int i = 0; i < N; ++i) {
            cin >> T[i];
        }
        
        vector<int> next_available(N, 1);
        int total_plucks = 0;
        
        for (int day = 1; day <= D; ++day) {
            vector<int> available;
            for (int i = 0; i < N; ++i) {
                if (next_available[i] <= day) {
                    available.push_back(i);
                }
            }
            int can_pluck = max(0, (int)available.size() - K);
            if (can_pluck > 0) {
                sort(available.begin(), available.end(), [&](int a, int b) {
                    return T[a] < T[b];
                });
                for (int i = 0; i < can_pluck; ++i) {
                    int flower = available[i];
                    next_available[flower] = day + T[flower];
                    total_plucks++;
                }
            }
        }
        cout << total_plucks << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int zz;
        cin >> zz;
        vector<int> pp(zz);
        for (int xx = 0; xx < zz; ++xx) {
            cin >> pp[xx];
        }

        int min_time = 1e9; // arbitrarily large number
        for (int i = 0; i < zz; ++i) {
            int move_time = abs(i - 0); // move from queue 1 (index 0) to i
            int remaining = max(0, pp[i] - move_time);
            int total = move_time + remaining;
            min_time = min(min_time, total);
        }

        cout << min_time << '\n';
    }
    return 0;
}

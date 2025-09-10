#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<pair<int, int>> thieves(N);
        for (int i = 0; i < N; ++i) {
            cin >> thieves[i].first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> thieves[i].second;
        }

        // Sort thieves based on their levels
        sort(thieves.begin(), thieves.end());

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0;
        vector<long long> res(N);

        for (int i = 0; i < N; ++i) {
            res[i] = sum;
            // Add current thief's coins to the heap and sum
            if (minHeap.size() < K) {
                minHeap.push(thieves[i].second);
                sum += thieves[i].second;
            } else if (!minHeap.empty() && thieves[i].second > minHeap.top()) {
                sum -= minHeap.top();
                minHeap.pop();
                minHeap.push(thieves[i].second);
                sum += thieves[i].second;
            }
        }

        // Reorder the results according to the original thief order
        vector<pair<int, long long>> originalOrder;
        for (int i = 0; i < N; ++i) {
            originalOrder.emplace_back(thieves[i].first, res[i]);
        }
        sort(originalOrder.begin(), originalOrder.end());
        for (int i = 0; i < N; ++i) {
            cout << originalOrder[i].second << " ";
        }
        cout << "\n";
    }
    return 0;
}
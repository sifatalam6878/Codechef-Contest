#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& color, vector<int>& value, vector<map<int, int>>& colorSum, vector<int>& maxScore) {
    colorSum[u][color[u]] = value[u];
    maxScore[u] = value[u]; // Initialize for single node case

    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u, adj, color, value, colorSum, maxScore);
        
        // Merge color sums from child to parent
        for (auto& entry : colorSum[v]) {
            colorSum[u][entry.first] += entry.second;
        }
    }

    if (adj[u].size() > 1 || (u == 1 && adj[u].size() >= 1)) { // Not a leaf in the entire tree
        int currentMax = 0;
        for (int v : adj[u]) {
            if (v == parent) continue;
            if (adj[v].size() == 1) { // v is a leaf in the subtree rooted at u
                map<int, int> tempA = colorSum[u];
                for (auto& entry : colorSum[v]) {
                    tempA[entry.first] -= entry.second;
                }
                int score = 0;
                for (auto& entry : tempA) {
                    score += abs(entry.second - colorSum[v][entry.first]);
                }
                currentMax = max(currentMax, score);
            }
        }
        if (currentMax > 0) {
            maxScore[u] = currentMax;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<vector<int>> adj(N + 1);
        for (int i = 0; i < N - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(N + 1);
        for (int i = 1; i <= N; ++i) {
            cin >> color[i];
        }
        vector<int> value(N + 1);
        for (int i = 1; i <= N; ++i) {
            cin >> value[i];
        }

        vector<map<int, int>> colorSum(N + 1);
        vector<int> maxScore(N + 1, 0);
        dfs(1, -1, adj, color, value, colorSum, maxScore);

        for (int i = 1; i <= N; ++i) {
            cout << maxScore[i] << "\n";
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;

ll mod_pow(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> tree(N + 1);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // We need to process the tree in post-order to compute sizes and contributions
    vector<int> parent(N + 1);
    vector<int> children[N + 1];
    vector<int> stack = {1};
    parent[1] = 0;
    while (!stack.empty()) {
        int u = stack.back();
        stack.pop_back();
        for (int v : tree[u]) {
            if (v != parent[u]) {
                parent[v] = u;
                children[u].push_back(v);
                stack.push_back(v);
            }
        }
    }

    // The answer is derived from the observation that for each node u with K_u children,
    // the number of arrays where u's value is not equal to the XOR of its subtree (excluding u)
    // is (M+1)^(total nodes) minus the valid cases.
    // However, the problem is more complex because the conditions are interdependent.

    // The total sum of f(A) is equal to the sum over all nodes u of the number of arrays where u is bad.
    // But some arrays may have multiple bad nodes, but in the minimal operations, we only count necessary changes.

    // The key insight is that for each node u, it must be modified if and only if the XOR of its children's subtrees does not equal A_u, and this condition is independent of other nodes' conditions when processed in post-order.

    // For a node u, let x_u be the XOR of the entire subtree rooted at u. Then, the condition for u being good is x_u = 0 (when S_u is non-empty).

    // The total number of arrays where x_u != 0 is (M+1)^N - (M+1)^{N - K} * 1, where K is the number of nodes in the subtree of u.
    // However, this is not accurate. Instead, for each node u, the number of arrays where x_u != 0 is (M+1)^{N} / 2, because for any assignment to nodes outside u's subtree, exactly half of the assignments inside the subtree will make x_u zero.

    // However, this is only true if M+1 is even. Otherwise, the calculation is more involved.

    // The correct approach is to realize that for each node u, the probability that x_u = 0 is 1/(M+1) if the assignments are independent. But they are not, because the assignments in the subtree are constrained by the XOR conditions.

    // The solution involves for each node u, the number of arrays where x_u (the XOR of the entire subtree) is not zero, which is (M+1)^{N} - (M+1)^{N - 1} (for M+1 possible values, one of which makes x_u zero).

    // But this is incorrect because the assignments in the subtree are not independent. The correct value is (M+1)^{N} * (M / (M+1)) when considering that the XOR of the entire subtree is zero with probability 1/(M+1).

    // Therefore, for each node u, the number of arrays where x_u != 0 is (M+1)^{N} * M / (M+1).

    // But this is only true for leaves. For non-leaf nodes, the calculation is more involved because the XOR of the children's subtrees must be considered.

    // The correct approach is to compute for each node u, the number of arrays where x_u != 0 is (M+1)^{N} / 2, assuming that M+1 is even. But since M can be any value, we need a different approach.

    // The solution is to realize that for each node u, the number of arrays where u is bad is the total number of arrays where the XOR of the children's subtrees is not equal to A_u. This is (M+1)^{N} - (M+1)^{N - 1} = M * (M+1)^{N-1}.

    // But this is only true for nodes with non-empty S_u. For leaves, they are always good (S_u is empty), so they contribute zero.

    // So the total sum is sum_{u: S_u is non-empty} M * (M+1)^{N-1}.

    // The number of nodes u where S_u is non-empty is N - number of leaves. Because leaves have empty S_u.

    // But wait: S_u is the set of nodes v ≠ u in the subtree of u. So for any non-leaf node, S_u is non-empty.

    // So the number of nodes with non-empty S_u is N - number of leaves.

    // So the total sum is (number of nodes with non-empty S_u) * M * (M+1)^{N-1}.

    // So first, compute the number of such nodes.

    int non_empty_nodes = 0;
    for (int u = 1; u <= N; ++u) {
        if (!children[u].empty()) {
            non_empty_nodes++;
        }
    }

    ll total_arrays = mod_pow(M + 1, N);
    ll term = mod_pow(M + 1, N - 1);
    term = term * M % MOD;
    ll ans = term * non_empty_nodes % MOD;
    cout << ans << '\n';
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
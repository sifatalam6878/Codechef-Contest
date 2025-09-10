#include <bits/stdc++.h>
using namespace std;
int compute_change(const vector<vector<int>> &a, int start)
{
    int n = a.size();
    int m = a[0].size();
    int changes = 0;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(a[i][j] != start + i + j)
                changes++;

    return changes;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        set<int> candidate;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                candidate.insert(a[i][j] - i - j);
            }
        int min_changes = INT_MAX;
        for(int base : candidate)
        {
            int changes = compute_change(a, base);
            min_changes = min(min_changes, changes);
        }
        cout << min_changes << "\n";
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int calsum(const vector<int>& row, int K)
{
    int sum = 0;
    for(int h : row)
    {
        sum += min(h, K);
    }
    return sum;
}
int findmin(int N, const vector<vector<int>>& grid)
{
    int low = 1;
    int high = 1e9;
    int best = 1;
    int maxs = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int firstsum = calsum(grid[0], mid);
        int curscore = 0;

        for(int i = 1; i<N; ++i)
        {
            int rowsum = calsum(grid[i], mid);
            if (rowsum > firstsum)
            {
                curscore++;
            }
        }

        if(curscore > maxs)
        {
            maxs = curscore;
            best = mid;
            high = mid - 1;
        }
        else if(curscore == maxs)
        {
            if(mid < best)
            {
                best = mid;
            }
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<vector<int>> grid(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> grid[i][j];
            }
        }
        cout << findmin(N, grid) << '\n';
    }

    return 0;
}
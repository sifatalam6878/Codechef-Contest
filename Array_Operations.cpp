#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for(int i = 0; i < N; ++i)
        {
            cin >> A[i];
        }
        
        if(N == 1)
        {
            cout << A[0] << '\n';
            continue;
        }
        if(N == 3)
        {
            int res = max({A[0] + 1, A[1], A[2] + 1});
            cout << res << '\n';
            continue;
        }
        int max_val = *max_element(A.begin(), A.end());
        int max_middle = 0;
        for(int i = 1; i < N - 1; ++i)
        {
            if (A[i] > max_middle)
            {
                max_middle = A[i];
            }
        }
        int res = max(max_val, max_middle);
        cout << res << '\n';
    }
    
    return 0;
}
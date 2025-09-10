#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int n, K, D;
        cin >> n >> K >> D;
        vector<int> t(n);
        for(int i = 0; i < n; i++)
        {
            cin >> t[i];
        }
        
        vector<int> nx_ava(n, 1);
        int ttl_pl = 0;
        for(int day = 1; day <= D; day++)
        {
            vector<int> ava;
            for(int i = 0; i < n; i++)
        {
                if(nx_ava[i] <= day)
                {
                    ava.push_back(i);
                }
            }
            int plu = max(0, (int)ava.size() - K);
            if(plu > 0)
            {
                sort(ava.begin(), ava.end(), [&](int a, int b)
                {
                    return t[a] < t[b];
                });
                for(int i = 0; i < plu; i++)
                {
                    int flower = ava[i];
                    nx_ava[flower] = day + t[flower];
                    ttl_pl++;
                }
            }
        }
        cout << ttl_pl << endl;
    }
    return 0;
}
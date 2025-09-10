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
        int p,q;
        cin >> p >> q;
        string s;
        cin >> s;

        int one = 0;
        for(char c : s)
        {
            if(c == '1')
              one++;
        }
        if(one == 0)
        {
            cout << 0 << '\n';
            continue;
        }

        vector<int>poss;
        for(int i=0;i<p;i++)
        {
            if(s[i] == '1')
              poss.push_back(i);
        }

        int total = one;
        int prev_pos = -1;
        for(int pos : poss)
        {
            int start = prev_pos + 1;
            int dis = pos - start;
            int us = min(dis,q);
            total += us;
            q -= us;
            prev_pos = pos;
            if(p == 0)
              break;
        }
        cout << total << '\n';
    }
    return 0;
}
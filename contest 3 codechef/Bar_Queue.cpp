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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt_a = 0, cnt_b = 0;
        int mx = 0;
        for(int i=0; i<n; i++)
        {
            if(s[i] == 'B')
            {
                cnt_a++;
            }
            else
            {
                cnt_b++;
            }
            mx++;
            if(cnt_a > 2 * cnt_b)
            {
                break;
            }
        }
        cout << mx << endl;
    }
    return 0;
}
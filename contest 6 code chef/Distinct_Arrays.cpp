#include<bits/stdc++.h>
using namespace std;
const int m = 998244353;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i< n;i++)
        {
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        bool k=true;
        long long r=1;
        for(int i=0;i<n;i++)
        {
            if(a[i]<i+1)
            {
                k=false;
                break;
            }
            r=(r*(a[i]-i))%m;
        }
        if(!k)
        {
            cout << "0\n";
        }
        else
        {
            cout << r << "\n";
        }
    }
    return 0;
}

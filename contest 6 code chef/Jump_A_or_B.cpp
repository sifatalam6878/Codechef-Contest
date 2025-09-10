#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while(q--)
    {
        int n,m,x,y;
        cin >> n >> m >> x >> y;
        if(m<n*x || m>n*y)
        {
            cout << "No" << endl;
            continue;
        }
        int f=n*y-m;
        int k=y-x;
        if(k==0)
        {
            cout << "No" << endl;
            continue;
        }
        if(f%k!=0)
        {
            cout << "No" << endl;
            continue;
        }
        int p=f/k;
        if(p>=0 && p<=n)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
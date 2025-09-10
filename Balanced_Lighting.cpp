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
        int n,r=0,b=0,x;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> x;
            if(x==1)
              r++;
            else if(x==2)
              b++;
        }
        int u=n-r-b;
        if(n%2==0 && r<=n/2 && b<=n/2 && r+b+u==n && (n/2-r)+(n/2-b)==u)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
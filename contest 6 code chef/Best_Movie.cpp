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
        int n;
        cin >> n;
        int m=INT_MAX;
        bool fk=false;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin >> x >> y;
            if(x>=7)
            {
                if(y<m)
                {
                    m=y;
                    fk=true;
                }
            }
        }
        if(fk)
        {
            cout << m << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
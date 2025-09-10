#include<bits/stdc++.h>
using namespace std;
/*
i am sifat alam
*/
bool a[21][21][41][2],b[21][21][41][2];
bool c(int d, int e, int f, int g)
{
    /*
      never give up
    */
    if (a[d][e][f][g]) return b[d][e][f][g];
    a[d][e][f][g] = 1;
    for(int h=f+1;h<=max(d,e);h++)
    {
        if(d>=h)
        {
            if(!c(d-h,e,h,1-g))
             return b[d][e][f][g]=1;
        }
        if(e>=h)
        {
            if(!c(d,e-h,h,1-g))
              return b[d][e][f][g]=1;
        }
    }
    return b[d][e][f][g]=0;
}
///////
//
/*
  never give up
*/
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i;
    cin >> i;
    while(i--)
    {
        int j,k,l;
        cin >> j >> k >> l;
        bool m = 0;
        for(int n=1;n<=l;n++)
        {
            if(j>=n)
            {
                if(!c(j-n,k,n,1))
                {
                    m=1;
                    break;
                }
            }
            if(k>=n)
            {
                if(!c(j,k-n,n,1))
                {
                    m=1;
                    break;
                }
            }
        }
        cout << (m?"Alice" : "Bob") << '\n';
    }
    /*
    alhamdulillah solved
    */
    return 0;
}

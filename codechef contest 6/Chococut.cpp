#include<bits/stdc++.h>
using namespace std;
/*
i am sifat alam
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    /*
    sifat alam
    */
    int ss;
    cin >> ss;
    while(ss--)
    {
        int ff, ll, kk;
        cin >> ff >> ll >> kk;
        int vv = ff * ll;
        int mm = 0;
        if (kk == 0)
        {
            mm = vv;
        }
        for(int x=1;x<ff;x++)
        {
            int ppa=x*ll;
            int ppb=(ff-x)*ll;
            if(ppa>=kk)
               mm=max(mm,ppb);
            if(ppb>=kk)
              mm=max(mm,ppa);
        }
        for(int y=1;y<ll;y++)
        {
            int ppa=ff*y;
            int ppb=ff*(ll-y);
            if(ppa>=kk)
               mm=max(mm,ppb);
            if(ppb>=kk)
               mm=max(mm,ppa);
        }
        if(vv>=kk)
          mm=max(mm,0);
        cout << mm << endl;
    }
    /*
    allahu akber
    */
    return 0;
}

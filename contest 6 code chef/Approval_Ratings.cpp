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
        vector<int> a(5);
        int fk=0;
        for(int i=0;i<5;i++)
        {
            cin >> a[i];
            fk += a[i];
        }
        double avg = fk/5.0;
        if(avg>=7.0)
        {
            cout << 0 << endl;
            continue;
        }
        sort(a.begin(),a.end());
        int xd = 0;
        for(int i=0;i<5;i++)
        {
            fk+=(10 - a[i]);
            xd+=100;
            avg=fk/5.0;
            if(avg>=7.0)
            {
                break;
            }
        }
        cout << xd << endl;
    }
    return 0;
}
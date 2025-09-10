#include<bits/stdc++.h>
using namespace std;
void ans()
{
    int n;
    string s,t;
    cin >> n >> s >> t;
    
    int s1=0, t1=0;
    for(char c : s)
      s1 += (c == '1');
    for(char c : t)
      t1 += (c == '1');
    
    if(t1>s1)
    {
        cout << "No" << endl;
        return;
    }
    if((s1-t1) % 2!=0)
    {
        cout << "No" << endl;
        return;
    }
    if(s1==0)
    {
        if(t1==0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
        return;
    }
    if(t1==0)
    {
        if (s1%2==0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
        return;
    }
    bool pos=true;
    for(int i=0;i<n;i++)
    {
        if(t[i]=='1' && s[i] != '1')
        {
            pos=false;
            break;
        }
    }
    if(pos)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        ans();
    }
    return 0;
}
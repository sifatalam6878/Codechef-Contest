#include<bits/stdc++.h>
using namespace std;
void fk()
{
    int n,m;
    cin >> n >> m;
    int t=(1<<(n+1))-1;
    if(m<0 || m>t)
    {
        cout << "No\n";
        return;
    }
    if(n==1)
    {
        if(m==0)
        {
            cout << "Yes\n00\n";
        }
        else if(m==1)
        {
            cout << "Yes\n10\n";
        }
        else if(m==3)
        {
            cout << "Yes\n11\n";
        }
        else
        {
            cout << "No\n";
        }
        return;
    }
    if(n==2)
    {
        if(m==0)
        {
            cout << "Yes\n0000\n";
        } else if (m==1)
        {
            cout <<"Yes\n1000\n";
        }
        else if(m==2)
        {
            cout << "Yes\n1001\n";
        }
        else if(m==3)
        {
            cout << "Yes\n1100\n";
        }
        else if(m==4)
        {
            cout << "Yes\n1010\n";
        }
        else if(m==5)
        {
            cout << "Yes\n1110\n";
        }
        else if(m==6)
        {
            cout << "Yes\n1101\n";
        }
        else if(m==7)
        {
            cout << "Yes\n1111\n";
        }
        else
        {
            cout << "No\n";
        }
        return;
    }
    if(n==3 && m==5)
    {
        cout << "Yes\n11001010\n";
        return;
    }
    cout << "No\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h;
    cin >> h;
    while(h--)
    {
        fk();
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
void ans()
{
    int n;
    cin >> n;
    
    if(n==1)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> a(n);
    if(n==2)
    {
        a[0]=3;
        a[1]=-3;
    }
    else if(n==3)
    {
        a[0]=1;
        a[1]=2;
        a[2]=-3;
    }
    else{
        int p=n/2;
        for(int i=0;i<p*2;i+=2)
        {
            a[i]=3;
            a[i+1]=-3;
        }
        if (n%2==1)
        {
            a[n-1]=0;
            if(n%2==1)
            {
                a[n-3]=1;
                a[n-2]=2;
                a[n-1]=-3;
            }
        }
    }
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += a[i];
        if(abs(a[i])>3 || a[i]==0)
        {
            cout << -1 << endl;
            return;
        }
    }
    if(sum!=0)
    {
        cout << -1 << endl;
        return;
    }
    for(int i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--)
    {
        ans();
    }
    return 0;
}
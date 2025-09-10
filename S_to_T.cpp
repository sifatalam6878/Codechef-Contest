#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    string s,t;
    cin >> n >> s >> t;
    
    if(s == t)
    {
        cout << "0\n";
        return;
    }
    if(s[0] != t[0])
    {
        cout << "-1\n";
        return;
    }
    vector<int> os;
    string cur = s;
    for (int i = 0; i < n - 1; i++) {
        if (cur[i] == '1' && cur[i+1] != t[i+1])
        {
            os.push_back(i + 1);
            cur[i+1] = (cur[i+1] == '0' ? '1' : '0');
        }
    }
    if (cur == t)
    {
        cout << os.size() << "\n";
        for(int op : os)
        {
            cout << op << " ";
        }
        if(!s.empty())
        {
            cout << "\n";
        }
        return;
    }
    os.clear();
    cur = s;
    for(int i = n - 2; i >= 0; i--)
    {
        if(cur[i] == '1' && cur[i+1] != t[i+1])
        {
            os.push_back(i + 1);
            cur[i+1] = (cur[i+1] == '0' ? '1' : '0');
        }
    }
    
    if(cur == t)
    {
        cout << os.size() << "\n";
        for(int op : os)
        {
            cout << op << " ";
        }
        if(!os.empty())
        {
            cout << "\n";
        }
    }
    else
    {
        cout << "-1\n";
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
        solve();
    }
    return 0;
}
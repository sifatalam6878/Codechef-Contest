#include <iostream>
#include <string>
#include <vector>
using namespace std;
int cnt_string(int n, string s)
{
    vector<int>flp_pos;
    int zero = 0, one = 0;
    for(int i=0; i<n;i++)
    {
        if(s[i] == '0')
            zero++;
        else
            one++;
        if(zero == one)
        {
            flp_pos.push_back(i);
        }
    }
    return 1 << flp_pos.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string s;
        cin >> n >> s;
        cout << cnt_string(n, s) << endl;
    }
    return 0;
}
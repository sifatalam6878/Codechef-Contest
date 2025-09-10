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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int min_val = a[0];
    int max_val = a[n - 1];
    int count = 0;
    for(int m = min_val + 1; m < max_val; m++)
    {
        bool small = false;
        bool large = false;
        for(int num : a)
        {
            if (num < m)
            {
              small = true;
            }
            else if (num > m)
            {
                large = true;
            }
            if(small && large)
            {
                break;
            }
        }
        if(small && large)
        {
            count++;
        }
    }
    cout << count << endl;
}
    return 0;
}
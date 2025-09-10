#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int r = n%3;
    if(r==0)
      cout << n << endl;
    else if(r == 1)
      cout << n-1 << endl;
    else
      cout << n+1 << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int pizz = 1;
    while((pizz*n)%2!=0)
    {
        pizz++;
    }
    cout << pizz << endl;
    return 0;
}
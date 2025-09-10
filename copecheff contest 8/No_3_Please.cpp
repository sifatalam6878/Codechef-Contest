/// ------------------------- بسم الله الرحمن الرحيم ------------------------- ///
/*
||-------------------------------------------||
||                 Author :                  ||
||              Sifat Alam                   ||
|| Dept. of Computer Science and Engineering ||
||     Southeast University (SEU), Dhaka     ||
||     Email : sifaterabbi20@gmail.com       ||
||     ID    : 2024200000174                 ||
||-------------------------------------------||
*/

#include<bits/stdc++.h>
using namespace std;
bool oodd(vector<int>& a)
{
    int sum = 0;
    for(int x : a)
    {
        //sifat alam
        sum += x;
        if(sum%3==0)
         return false;
    }
    //allahu
    return true;
}
string xxx()
{
    //subhanallah
    int nnn;
    cin >> nnn;
    vector<int> a(nnn);
    for(auto& x : a)
      cin >> x;
    if(oodd(a))
      return "Yes";
    for(int i=1;i<nnn;i++)
    {
        //la ilaha illah
        reverse(a.begin(),a.begin()+i);
        if (oodd(a))
          return "Yes";
        reverse(a.begin(), a.begin()+i);
    }
    //masallah
    return "No";
}
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define loop(i,a,b) for(int i=a;i<b;i++)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define read(arr,n) for(int i=0;i<n;i++) cin >> arr[i];
#define print(arr,n) for(int i=0;i<n;i++) cout << arr[i] << ' '; cout << endl;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

template<typename T>
void debug_vec(const vector<T>& v) {
    cerr << "[ ";
    for(const T& val : v) cerr << val << " ";
    cerr << "]\n";
}

int main() {
    FAST;
    
    int ttt;
    cin >> ttt;
    while(ttt--)
    {
        cout << xxx() << endl;
    }
    // sifat bro
    return 0;
}
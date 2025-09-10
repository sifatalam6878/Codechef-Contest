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
    
    int aa;
    cin >> aa;
    while(aa--)
    {
        //sifat bro
        int kk;
        cin >> kk;
        vector<int> ll(kk);
        int pp=0,qq=0,rr=0;
        for(int ii=0;ii<kk;ii++)
        {
            //la ilaha illlah
            cin >> ll[ii];
            int oo = ll[ii]%3;
            if(oo==0)
               pp++;
            else if(oo==1)
               qq++;
            else
               rr++;
        }
        //masallah
        bool zz=false;
        if(pp>0)
        {
            zz = true;
        }
        //subhanallah
        else if(qq>=1 && rr>=1)
        {
            zz = true;
        }
        else if(qq>=3 || rr>=3)
        {
            zz = true;
        }
        // allahuakber
        cout << (zz ? "Yes" : "No") << endl;
    }
    return 0;
}
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
    
    int xx;
    cin >> xx;
    while(xx--)
    {
        int yy,zz;
        cin >> yy >> zz;
        //subhanallah
        vector<long long> pp(yy);
        for(int aa=0;aa<yy;aa++)
        {
            //ostagfirullah
            cin >> pp[aa];
        }
        sort(pp.begin(),pp.end());
        long long bb = pp[0];
        //masallah alhamdulillah
        long long cc = pp[1];
        // la ilaha illah
        long long dd = 0;
        for(long long ee:pp)
        {
            // amr sunar bangla ami tmy valobasi
            dd += ee;
        }
        long long ff=(bb+cc+1)/2;// la ilahaillah
        dd+= ff;
        //wastagfirullah
        dd+= (zz-1) * bb;
        //sifatalam
        cout << dd << endl;
        // amr sunar  bangla ami tmy valobasi
    }
    return 0;
}
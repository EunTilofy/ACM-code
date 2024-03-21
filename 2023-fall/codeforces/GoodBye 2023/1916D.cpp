#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define mod 998244353
#define dbg1(x) cerr << #x << '=' << (x) << ' '
#define dbg2(x) cerr << #x << '=' << (x) << '\n'
#define dbg3(x) cerr << #x << '\n'
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
#define cerr std::cerr
#define cout std::cout
#define cin std::cin
const int MN = 4e5 + 5;
int a[MN], b[MN], c[MN];

map<long long, vector<int>> mp;

long long func(int i) {
    long long val = 1ll * i * i;
    long long _ = 1;
    while(i >= 10) {
        _ *= i % 10;
        i /= 10;
    }
    _ *= i;
    return _;
}

void solve(){
    int n;
    cin >> n;
	if(n == 1) {
        cout << "1\n";
        return ;
    }
    // if(n == 3) {
    //     cout << "169\n196\n961\n";
    //     return ;
    // }
    for(int i = 1; i ; ++i) {
        if(3 + (i - 1) * 2 > n) break;
        cout << "1";
        for(int j = 1; j < i; ++j) cout << "0";
        cout << "6";
        for(int j = 1; j < i; ++j) cout << "0";
        cout << "9";
        for(int j = 3+(i-1)*2; j < n; ++j) cout << "0";
        cout << "\n";
    }
    for(int i = 1; i ; ++i) {
        if(3 + (i - 1) * 2 > n) break;
        cout << "9";
        for(int j = 1; j < i; ++j) cout << "0";
        cout << "6";
        for(int j = 1; j < i; ++j) cout << "0";
        cout << "1";
        for(int j = 3+(i-1)*2; j < n; ++j) cout << "0";
        cout << "\n";
    }
    cout << "196";
    for(int i = 4; i <= n; ++i) cout << "0";
    cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}
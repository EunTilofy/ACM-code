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
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
const int MN = 3e5 + 5;
int a[MN], b[MN], c[MN];
int f[MN], siz[MN];
int getf(int x) {return f[x] == x ? x : f[x] = getf(f[x]);}
int cnt;
// 1 Alice
// 2 Bob

int n, l, r;

void solve(){
    cin >> n >> l >> r;
    cnt = n;
    for(int i = 1; i <= n; ++i) f[i] = i, siz[i] = 1;
    for(int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        x = getf(x); y = getf(y);
        if(x != y) --cnt, f[x] = y, siz[y] += siz[x]; 
    }
    vector<int> a;
    for(int i = 1; i <= n; ++i) if(getf(i) == i) {
        // cerr << siz[i] << endl;
        if(siz[i] < l + r && siz[i] >= l) a.push_back(siz[i]);
    }
    int ret = 0;
    for(auto x : a) {
        ret ^= (x / l);
    }
    if(ret) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T = 1;
	while(T--) 
		solve();
}
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
const int inv2 = (mod + 1)/2, inv3 = (mod + 1)/3, inv4 = (mod * 2 + 1) / 4;

void solve(){
	int n, m;
	cin >> n >> m;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i], b[a[i]] = i;
    for(int i = 1; i <= n; ++i) {
        if(b[i] < b[i - 1]) {
            cout << (n - i + m) / m << endl;
            return ;
        } 
    }
    cout << 0 << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
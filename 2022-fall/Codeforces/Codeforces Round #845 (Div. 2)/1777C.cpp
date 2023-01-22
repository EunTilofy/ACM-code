#include"bits/stdc++.h"
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
vector<int> G[MN];

void solve(){
	int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a+1,a+n+1);
    n = unique(a+1,a+n+1) - a - 1;
    vector<vector<int>> B(n+1), C(m+1);
    for(int i = 1; i <= m; ++i) b[i] = 0, c[i]=100005;
    for(int i = 1; i <= n; ++i) {
        for(auto y : G[a[i]]) if(y <= m) {
            B[i].pb(y);
            c[y]=min(c[y], i);
        }
    }
    int r=0, l;
    for(int i=1;i<=m;++i) r=max(r,c[i]);
    if(r==100005) {cout<<-1<<endl;return;}
    for(int i = 1; i <= r; ++i) for(auto y : B[i]) ++b[y];
    int ans = a[r] - a[1];
    for(l=1; l<=n; ++l) {
        bool fl = 1;
        for(auto y : B[l]) {
            --b[y];
            if(b[y] == 0) {
                while(r<n) {
                    ++r;
                    for(auto z : B[r]) ++b[z];
                    if(b[y]) break;
                }
                if(!b[y]) {fl = 0; break;}
            }
        }
        if(!fl) break;
        ans = min(ans, a[r] - a[l+1]);
    }
    cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
    for(int i = 1; i <= 100000; ++i) for(int j = i; j <= 100000; j += i)
        G[j].pb(i);
	while(T--) 
		solve();
}
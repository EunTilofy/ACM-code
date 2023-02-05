#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()
#define int long long
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define mod 998244353
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
const int MN = 3e5 + 5;
int a[MN], b[MN][33], c[33];
int n, m, k;
void solve(){
	cin >> n >> m >> k;
    long long _ = 0;
    for(int i = 1; i <= n; ++i) _ ^= i;
    for(int i = 1; i <= m; ++i) _ ^= k;
    if(_) {
        cout << "NO" << endl;
        return;
    }
    for(int i = 31; ~i; --i) c[i] = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 31; ~j; --j) {
            c[j] += (i>>j)&1;
        }
    }
    for(int i = 31; ~i; --i) {
        if(k>>i&1) {
            if(c[i] < m || (c[i]-m)%2!=0) {
                cout << "NO" << endl;
                return;
            }
        } else {
            if(c[i]&1) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    if(m == 1) {
        cout << n << " ";
        for(int i = 1; i <= n; ++i) cout << i << " ";
        cout << endl;
        return;
    }
    int M = m;
    vector<vector<int>> ans(M);
    vector<int> num(M);
    set<int> S, nS;
    for(int i = 1; i <= n; ++i) {
        nS.insert(i);
        memset(b[i], 0, sizeof b[i]);
    }
    // cout <<"m="<< m << endl;
    for(int i = 0; i < m; ++i) {
        for(auto y : nS) {
            // cout << y << endl;
            if(nS.count(k ^ num[i])) {
                S.insert(k ^ num[i]);
                ans[i].pb(k ^ num[i]);
                num[i] = k;
                break;
            }
            ans[i].pb(y);
            S.insert(y);
            num[i]^=y;
        }
        for(auto y : ans[i]) nS.erase(y);
    }
    for(int i = 1; i <= n; ++i) if(!S.count(i)) ans[0].pb(i);
    for(auto x : ans) {
        cout << x.size() << " ";
        for(auto y : x) cout << y << " ";
        cout << endl;
    }
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}
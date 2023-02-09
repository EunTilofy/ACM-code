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
int a[MN], c[MN];
vector<pii> G[MN];
set<int> S[MN], T[MN];
void solve(){
	int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i], G[i].clear(), S[i].clear(), T[i].clear();
        c[i] = 0;
    }
    for(int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].pb({a[y],y}); G[y].pb({a[x],x});
    }
    for(int i = 1; i <= n; ++i) sort(all(G[i]));
    for(int i = 1; i <= n; ++i) if(!c[i] && a[i] == 0) {
        set<pii> Q;
        Q.insert({0,i});
        while(!Q.empty()){
            pii _ = *Q.begin();
            if(_.fi > S[i].size()) break;
            int x = _.se;
            // if(!c[x]) {
                c[x] = i;
                S[i].insert(x);
                for(auto y : G[x]) if(!S[i].count(y.se)){
                    Q.insert(y);
                }
            // } else {
            //     int j = c[x];
            //     for(auto y : S[j]) S[i].insert(y), c[y] = i;
            //     for(auto y : T[j]) {
            //         if(!S[i].count(y)) Q.insert({a[y],y});
            //     }
            //     S[j].clear();
            //     T[j].clear();
            // }
            Q.erase(_);
        }
        if(S[i].size() >= n) {
            cout << "YES" << endl;
            return ;
        }
        // for(auto X : Q){
        //     if(!S[i].count(X.se)) T[i].insert(X.se);
        // }
    }
    cout << "NO" << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}
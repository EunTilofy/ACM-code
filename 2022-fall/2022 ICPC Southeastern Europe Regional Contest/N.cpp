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
bool cmp(int x, int y){return a[x]<a[y];}
void solve(){
	int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    // for(int i = 1; i <= n; ++i) b[i] = i;
    // sort(b+1,b+n+1,cmp);
    priority_queue<pair<int,int>> q;
    for(int i = 1; i <= n; ++i) q.push({a[i], i});
    while(!q.empty()) {
        pii o=q.top();q.pop();
        if(c[o.se]) continue;
        c[o.se]=1;
        if(o.se>1&&!c[o.se-1]) {
            a[o.se-1]=max(o.fi-m,a[o.se-1]);
            q.push({a[o.se-1], o.se-1});
        }
        if(o.se<n&&!c[o.se+1]) {
            a[o.se+1]=max(o.fi-m,a[o.se+1]);
            q.push({a[o.se+1],o.se+1});
        }
    }
    for(int i = 1; i <= n; ++i) cout << a[i] << " ";
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	solve();
}
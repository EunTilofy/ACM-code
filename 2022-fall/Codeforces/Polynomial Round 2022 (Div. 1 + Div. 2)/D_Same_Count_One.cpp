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

void solve(){
	int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n+1);
    vector<int> b(n + 1);
    int nm = 0, st = 0;
    for(int i = 1; i <= n; ++i) {
        a[i].resize(m+1);
        for(int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            nm += a[i][j] == 1;
            b[i] += a[i][j] == 1;
        }
    }
    if(nm % n != 0) {cout << "-1" << endl; return ;}
    for(int i = 1; i <= n; ++i) {
        if(nm / n > b[i]) st += nm/n - b[i];
    } 
    cout << st << endl;
    nm /= n;
    for(int i = 1; i <= m; ++i) {
        vector<pair<int, int>> v1, v2;
        for(int j = 1; j <= n; ++j) {
            if(b[j] < nm && a[j][i] == 0) v1.pb({b[j] - nm, j});
            else if(b[j] > nm && a[j][i] == 1) v2.pb({nm - b[j], j});
        }
        std::sort(all(v1));sort(all(v2));
        for(int j = 0; j < min(v1.size(), v2.size()); ++j) {
            ++b[v1[j].se]; --b[v2[j].se];
            cout << v1[j].se <<" " << v2[j].se << " " << i << endl;
        }
    }
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
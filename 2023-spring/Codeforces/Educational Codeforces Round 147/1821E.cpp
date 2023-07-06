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
#define int long long

void solve(){
	int n, m;
    cin >> m;
    string s;
    cin >> s;
    n = s.size();
    for(int i = 1; i <= m; ++i) {
        a[0] = 1;
        for(int j = 1; j < n; ++j) {
            a[j] = a[j - 1] + (s[j] == '(' ? 1 : -1);
            // if(s[i] == ')') ans += a[i];
        }
        int posr = -1, posl = -1;
        for(int l = 0; l < n; ++l) {
            int r = l;
            while(a[r] != 0) {
                ++r;
                // a[r] = a[r -1] + (s[r] == '(' ? 1 : -1);
            }
            if(posl == -1 || (r - l) > (posr - posl)) {
                posl = l;
                posr = r;
            }
            l = r;
        }
        string t;
        for(int j = 0; j < posl; ++j) t+=s[j];
        t+='(';t+=')';
        for(int j = posl+1;j < posr; ++j) t+=s[j];
        for(int j = posr + 1; j < n; ++j) t+=s[j];
        s = t;
    }
    int ans = 0;
    a[0] = 1;
    for(int i = 1; i < n; ++i) {
        a[i] = a[i - 1] + (s[i] == '(' ? 1 : -1);
        if(s[i] == ')') ans += a[i];
    }
    cout << ans << endl;
}


signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}
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

int cal(int len) {
    return a[len];
}

void solve(){
	int n, m;
    string s;
    cin >> s;
    n = s.size();
    int ans = n;
    for(int i = 0; i < 26; ++i) {
        vector<int> pos;
        pos.push_back(-1);
        for(int j = 0; j < n; ++j) if(s[j]-'a'==i) pos.push_back(j);
        pos.push_back(n);
        int ret = 0;
        for(int j = 1; j < pos.size(); ++j) ret = max(ret, cal(pos[j]-pos[j-1]-1));
        ans = min(ans, ret);
    }
    cout << ans << endl;
}

int main(){
    a[0] = 0;
    for(int i = 1; i <= 200000; ++i) {
        a[i] = 1 + a[i/2];
    }
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}
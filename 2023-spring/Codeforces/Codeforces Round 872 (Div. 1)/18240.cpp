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
const int MN = 3e5 + 5;
int a[MN], b[MN], c[MN];

void solve(){
	int n, m;
	cin >> n >> m;
	int left = 0, right = 0;
	for(int i = 1; i <= m; ++i) b[i] = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		if(a[i] == -1) ++right;
		else if(a[i] == -2) ++ left;
		else ++b[a[i]];
	}
	int ans1 = 0, ans2 = 0, ans3 = 0;
	int sp = 0, now = 0;
	for(int i = 1; i <= m; ++i) if(b[i] == 0) ++sp;
	ans3 = m - sp;
	for(int i = 1; i <= m; ++i) {
		if(b[i]) {
			ans3 = max(ans3, m - sp + min(now, right) + min(sp - now, left));
		}
		else ++now;
	}
	ans1 = m - sp;
	ans2 = m - sp;
	for(int i = 1; i <= m; ++i) {
		if(!b[i] && left) --left, ++ans1;
	}
	for(int i = m; i; --i) {
		if(!b[i] && right) --right, ++ans2;
	}
	// for(int i = 1; i <= m; ++i) if(b[i]) ++ans;
	cout << max(ans1, max(ans2, ans3)) << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}
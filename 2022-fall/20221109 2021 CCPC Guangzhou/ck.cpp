#include<bits/stdc++.h>
using namespace std;

#define int long long
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"

int n, m, p, q;
#define MN 210005
#define mod 998244353
int Add(int x, int y) {return ((x+y)%mod+mod)%mod;}
int Mul(int x, int y) {return ((1ll*x*y)%mod+mod)%mod;}
int fpow(int x,int y) {int r=1;for(;y;y>>=1,x=Mul(x,x))if(y&1)r=Mul(r,x);return r;}
std::vector<int> d[MN], pos[MN], sum[MN], sum1[MN], sum2[MN];
int sum3[MN], sum4[MN];

int mu[MN], pr[MN], tot;
bool mk[MN];
void init() {
	mu[1] = 1;
	for(int i = 2; i <= m; ++i) {
		if(!mk[i]) {pr[++tot]=i; mu[i]=-1;}
		for(int j = 1; j <= tot && 1ll * pr[j] * i <= m; ++j) {
			mk[pr[j]*i] = 1;
			if(i % pr[j] == 0) {
				mu[i * pr[j]] = 0;
				break;
			}
			else mu[i * pr[j]] = - pr[j];
		}
	}
	for(int i = 1; i <= m; ++i) mu[i] = (mu[i]%mod + mod) % mod;
}

int ans = 0, ans1 = 0, ans2 = 0;
void dfs(int dep, int gc, int lc, int v) {
//	cerr << dep << " " << gc << " " << lc << " " << v << endl;
	if(dep > n) {
		if(gc <= q && lc >= p) ans = Add(ans, v);
		if(gc > q) ans1 = Add(ans1, v);
		if(gc <= q && lc < p) ans2 = Add(ans2, v);
		return ;
	}
	for(int i = 1; i <= m; ++i) {
		int Gc = __gcd(gc, i);
		int Lc = lc * i / __gcd(lc, i);
		dfs(dep + 1, Gc, Lc, Mul(v, i));
	}
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin>>n>>m>>p>>q;
	ans = 0;
	dfs(1, 0, 1, 1);
	cout << ans << "\n";
//	cout << ans1 << "\n" << ans2 ;
	return 0;
}
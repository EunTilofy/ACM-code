#include<bits/stdc++.h>
using namespace std;
#define MN 1000005
int f[MN], g[MN];
#define mod 998244353
int Add(int x, int y) {return (x + y) % mod;}
int Mul(int x, int y) {return 1ll * x * y % mod;}
int phi[MN], pr[MN], tot, sphi[MN], mu[MN], dmu[MN];
bool mk[MN];
void init_prime() {
	mu[1] = 1;
	for(int i = 2; i < MN; ++i) {
		if(!mk[i]) {pr[++tot] = i; phi[i] = i - 1; mu[i] = -1;}
		for(int j = 1; j <= tot && 1ll * pr[j] * i < MN; ++j) {
			mk[pr[j] * i] = 1;
			phi[pr[j] * i] = phi[i] * (pr[j] - 1);
			mu[pr[j] * i] = mu[i] * (-1);
			if(i % pr[j] == 0) {
				phi[pr[j] * i] = phi[i] * pr[j];
				mu[pr[j] * i] = 0;
				break;
			}
		}
	}
	for(int i = 1; i < MN; ++i) sphi[i] = Add(sphi[i - 1], phi[i]);
	for(int i = 1; i < MN; ++i) {
		if(mu[i] == -1) mu[i] = mod - 1;
		dmu[i] = Add(dmu[i - 1], Mul(mu[i], i));
	}
}
// int sqr(int x){return Mul(x,x);}
int cal(int x) {
	// cerr<<"x="<<x<<endl;
	return Mul(Mul(x,x+1),x);
}
int get(int l, int r) {
	// cerr<<
	return Add(dmu[r], mod-dmu[l-1]);
}
void solve() {
	int n;
	cin>>n;
	int ans = 5 * n - 6;
	ans = Add(ans, Mul(4 * n - 2, sphi[n - 1]));
	int res = 0;
	// cerr<<"ans="<<ans<<endl;
	for(int l = 1, r = 1; l < n; ++l) {
		r = (n-1)/((n-1)/l);
		r = min(r, n - 1);
		// cerr<<l<<" "<<r<<endl
		// cerr<<"get(l,r)"<<l<<" "<<r<<" "<<get(l,r)<<endl;
		// cerr<<(n-1)/l<<" "<<cal((n-1)/l)<<endl;
		res = Add(res, Mul(get(l,r), cal((n-1)/l)));
		// cerr<<res<<endl;
		l = r;
	}
	ans = Add(ans, mod - res + 2);
	cout<<ans<<endl;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	init_prime();
	int T;
	cin>>T;
	while(T--) {
		solve();
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define inv2 500000004
#define int long long
int Add(int x, int y) {return ((x + y) % mod + mod)%mod;}
int Mul(int x, int y) {return ((1ll * x * y % mod) + mod) % mod;}
int fpow(int x, int y) {
	int r = 1;
	for(;y;y>>=1, x=Mul(x,x)) if(y & 1) r = Mul(x, r);
	return r;
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n, m;
	cin>>n>>m;
	std::vector<int> a(n + 1), b(n + 1);
	for(int i = 1; i <= n; ++i) cin>>a[i], b[i] = a[i];
	long long _1 = 0ll;
	long long _2 = 0ll;
	
	for(int i = 1, j = n; i <= n; ++i, --j) {
		_1 = Add(_1, Mul(a[i], j));
		_2 = Add(_2, Mul(a[j], j));
	}
	
	for(int i = 1; i <= n; ++i) b.push_back(a[i]);	
	for(int i = 1; i + i <= n; ++i) swap(a[i], a[n - i + 1]);
	for(int i = n; i >= 1; --i) a.push_back(a[i]);
	
//	for(int i = 1; i <= n * 2; ++i) cout<<a[i]<<" ";cout<<endl;
//	for(int i = 1; i <= n * 2; ++i) cout<<b[i]<<" ";cout<<endl;
//	
	m--;
	int nm = fpow(2, m);
	n <<= 1;
	int ans1 = 0, ans2 = 0, num = Mul(Add(1, nm), Mul(nm, inv2));
	num = Mul(num, n);
	for(int i = 1; i <= n; ++i) {
		ans1 = Add(ans1, Mul(a[i], num));
		ans2 = Add(ans2, Mul(b[i], num));
		num = Add(num, mod - nm);
	}
	cout<<max(ans1, ans2);
	return 0;
}
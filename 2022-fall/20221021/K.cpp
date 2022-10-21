#include<bits/stdc++.h>
#define dbg1(x) std::cerr<<#x<<'='<<(x)<<" "
#define dbg2(x) std::cerr<<#x<<"="<<(x)<<endl
#define dbg3(x) std::cerr<<#x<<endl
#define int long long
using namespace std;
long long f[4005][2];
long long a[4005][2], b[2][4005][2], c[4005][2];
int n;
const long long inf = 3e18;

long long get(int l, int r, int _, int o) {
	if(_==0) {
//		dbg1(l);
//		dbg1(r);
//		dbg1(_);
//		dbg2(o);
//		dbg1(b[0][r][o]);
//		dbg2(b[0][l-1][o]);
//		dbg2(c[r][o]-c[l-1][o]);
//		dbg2((b[0][r][o] - b[0][l-1][o]) - (c[r][o] - c[l-1][o]) * (l - 1));
		return (b[0][r][o] - b[0][l-1][o]) - (c[r][o] - c[l-1][o]) * (l - 1);
	}
	else {
//		dbg1(l);
//		dbg1(r);
//		dbg1(_);
//		dbg2(o);
//		dbg1(b[1][l][o]-b[1][r+1][o]);
//		dbg2(c[r][o]-c[l-1][o]);
//		dbg2(n-r);
//		dbg1(n); dbg2(r);
//		dbg2((b[1][l][o] - b[1][r+1][o]) - (c[r][o] - c[l-1][o]) * (n - r));
		return (b[1][l][o] - b[1][r+1][o]) - (c[r][o] - c[l-1][o]) * (n - r);
	}
}

long long cal(int l, int r, int o) {
	if(l==1 && r==n) return inf;
	if(l==1) return get(l,r,1,o);
	if(r==n) return get(l,r,0,o);
	int mid=(l+r)>>1;
	return get(l,mid,0,o)+get(mid+1,r,1,o);
}

long long solve() {
	cin>>n;
	for(int i = 1; i <= n; ++i) cin>>a[i][0]>>a[i][1];
	memset(b, 0, sizeof b);
	for(int i = 1; i <= n; ++i) {
		b[0][i][0] = b[0][i-1][0] + i * a[i][0];
		b[0][i][1] = b[0][i-1][1] + i * a[i][1];
		c[i][0] = c[i - 1][0] + a[i][0];
		c[i][1] = c[i - 1][1] + a[i][1];
	} 
	for(int i = n; i; --i) {
		b[1][i][0] = b[1][i+1][0] + (n-i+1) * a[i][0];
		b[1][i][1] = b[1][i+1][1] + (n-i+1) * a[i][1]; 
	}
	for(int i = 1; i <= n; ++i) for(int j = 0; j < 2; ++j) {
		f[i][j] = inf;
		for(int k = 0; k < i; ++k)
			f[i][j] = min(f[k][j^1] + cal(k+1,i,j), f[i][j]);
//		cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
	}
	return min(f[n][0], f[n][1]);
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T;
	cin >> T;
	for(int o = 1; o <= T; ++o) {
		long long ans = solve();
		cout << "Case #" << o << ": " << ans << "\n";
	}
	return 0;
}
/*
1
2
10 5
4 3
*/
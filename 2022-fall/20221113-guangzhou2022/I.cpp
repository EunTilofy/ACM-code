#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int Add(int x, int y) {
	return (x + y) % mod;
}
int Mul(int x, int y) {
	return 1ll * x * y % mod;
}

int fpow(int x, int y) {
	int ans = 1;
	for(; y; y >>= 1) {
		if(y & 1) ans = Mul(ans, x);
		x = Mul(x, x);
	}
	return ans;
}
int inv(int x) {return fpow(x, mod - 2);}
int n;
#define MN 2005
vector<int> g[MN];
int a[MN], p[MN];
int f[MN][MN], siz[MN];
int ans[MN];
int h[MN][MN];

int mx[MN];
void pre_dfs(int x, int F) {
	siz[x] = 1;
	for(auto y : g[x]) if(y != F) {
		pre_dfs(y, x);
		if(siz[y]>siz[mx[x]]) mx[x] = y;
		siz[x] += siz[y];
	}
}
int dp[MN];
void dfs1(int x, int F) {
//	cout<<"x="<<x<<"F="<<F<<endl;
	f[x][1] = p[x];
	int now = 1;
	vector<int> nm(n+1);
	for(auto y : g[x]) if(y != F && y != mx[x]) {
		dfs1(y, x);
		for(int j = 1; j <= siz[y]; ++j)
			for(int i = 1; i <= now; ++i)
				nm[i+j] = Add(nm[i+j], Mul(f[x][i], f[y][j]));
		for(int i = 1; i <= now+siz[y]; i++) f[x][i] = Add(f[x][i], nm[i]), nm[i] = 0;
		now += siz[y];
	}
//	cout<<"x="<<x<<endl;
//	for(int i = 1; i <= siz[x]; ++i) cout<<"f[x]["<<i<<"]="<<f[x][i]<<endl;
	if(mx[x]) {
		dfs1(mx[x], x);
		for(int j = 1; j <= siz[mx[x]]; ++j) 
			for(int i = 1; i <= now; ++i) {
//				cout<<x<<" "<<mx[x]<<"i="<<i<<"j="<<j<<" "<<f[x][i]<<" "<<f[mx[x]][j];
				nm[i+j] = Add(nm[i+j], Mul(f[x][i], f[mx[x]][j]));
//				cout<<" "<<nm[i+j]<<endl;
			}
		for(int i = 1; i <= now+siz[mx[x]]; ++i) f[x][i] = Add(f[x][i], nm[i]), nm[i] = 0;
		now += siz[mx[x]];
	}
//	cout<<"x="<<x<<endl;
//	for(int i = 1; i <= siz[x]; ++i) cout<<"f[x]["<<i<<"]="<<f[x][i]<<endl;
}

void dfs2(int x, int F) {
	vector<int> nm(n+1);
	cout<<"x="<<x<<"F="<<F<<endl;
	for(int i = 1; i <= n; ++i) {
		cout<<f[x][i]<<" "<<a[i]<<" i= "<<i<<endl;
		ans[i] = Add(ans[i], Mul(f[x][i], a[x]));
	}
	if(mx[x])
		for(int i = 1; i <= n; ++i) h[mx[x]][i] = f[x][i];
	for(auto y : g[x]) if(y != F && y != mx[x]) {
		dp[1] = p[x];
		int now = 1;
		for(auto z : g[x]) if(z != F && z != y) {
			for(int j = 1; j <= siz[z]; ++j) 
				for(int i = 1; i <= now; ++i) 
					nm[i+j] = Add(nm[i+j], Mul(dp[i], f[z][j]));
			for(int i = 1; i <= now+siz[z]; ++i) dp[i] = Add(dp[i], nm[i]), nm[i] = 0;
			now += siz[z];
		}
		for(int i = 1; i <= siz[x]-siz[y]; ++i) h[y][i] = dp[i], dp[i] = 0;
	}
	for(auto y : g[x]) if(y != F) {
		vector<int> orix(siz[x]+1), oriy(siz[y]+1);
		for(int i = 0; i <= siz[x]; ++i) orix[i] = f[x][i];
		for(int i = 0; i <= siz[y]; ++i) oriy[i] = f[y][i];
		for(int i = 1; i <= n; ++i) {
			if(x == 2 && y == 5) {
				cout<<i<<" "<<f[y][i]<<" "<<f[x][i]<<" "<<h[y][i]<<endl;
			}
			f[y][i] = f[y][i] + f[x][i] - h[y][i];
		}
		for(int i = 0; i <= siz[x]; ++i) {
			f[x][i] = h[y][i];
		}
		siz[x] -= siz[y];
		siz[y] = n;
		dfs2(y, x);
		siz[y] = n - siz[x];
		siz[x] = n;
		for(int i = 0; i <= siz[x]; ++i) f[x][i] = orix[i];
		for(int i = 0; i <= siz[y]; ++i) f[y][i] = oriy[i];
	}
}
int main() {
//	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i = 1; i < n; ++i) {
		int x, y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int pre = 1, alla = 0, invalla = 1;
	
	for(int i = 1; i <= n; ++i) {
		int B, C;
		cin>>a[i]>>B>>C;
		p[i] = Mul(B, inv(C));
		alla = Add(alla, a[i]);
	}
	
	invalla = inv(alla);
	for(int i = 1; i <= n; ++i) {
//		cout<<a[i]<<" "<<alla<<" "<<invalla<<endl;
		a[i] = Mul(a[i], invalla);
	}
	for(int i = 1; i <= n; ++i) a[i] = Mul(a[i], inv(p[i]));
	for(int i = 1; i <= n; ++i) {
		int _ = Add(1, mod - p[i]);
		if(_==0) _ = 1;
		pre = Mul(pre, _);
		p[i] = Mul(p[i], inv(_));
	}
	
	for(int i = 1; i <= n; ++i) cout<<a[i]<<" ";
	cout<<"\n";
	for(int i = 1; i <= n; ++i) cout<<p[i]<<" ";
	cout<<"\n";
	
	pre_dfs(1, 0);
	dfs1(1, 0);
	dfs2(1, 0);
	for(int i = 1; i <= n; ++i) cout<<Mul(ans[i], pre)<<endl;
	return 0;
}
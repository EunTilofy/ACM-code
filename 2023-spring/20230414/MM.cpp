#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
vector<int> G[N];

int f[N], fa[N], dep[N];
int find(int k) {
	return f[k] == k ? f[k] : f[k] = find(f[k]);
}

int da[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, now;
	cin >> n >> m;
	for(int o = 1; o <= m; ++o) {
		vector<int> a(n + 1), b(n + 1);
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			b[a[i]] = i;
			dep[i] = a[i];
		}
		fa[b[1]] = 0;
		for(int i = 1; i < n; ++i) {
			int x = b[i], y = b[i + 1];
			fa[y] = x;
			G[x].push_back(y);
		}
		now = b[n];
	}
//	cerr << "!!!\n";
	for(int i = 1; i <= n; ++i) f[i] = i;	
//	for(int i = 1; i <= n; ++i) cerr << i << " " << fa[i] << "\n";
	for(int x = 1; x <= n; ++x) {
		for(int y : G[x]) if(dep[y] < dep[x]) {
			int fx = find(x), fy = find(y);
//			cerr << fx << " " << fy << "\n";
			for(; fx != fy; fx = find(fa[fx])) {
//				cerr << fx << " "<< fy << "\n";
				f[fx] = fy;
			}
		}
	}
	
	for(int i = 1; i <= n; ++i) da[find(i)]++;
	
	now = find(now);
	for(; now; ) {
		int res = find(fa[now]);
		da[res] += da[now];
		now = res;
	}
	
	for(int i = 1; i <= n; ++i) 
		cout << da[f[i]] - 1 << " ";
	cout << "\n";
	return 0;
}
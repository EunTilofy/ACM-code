#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

void solve(int o) {
	int n, m, k;
	cin >> n >> m >> k;
	vector f(n + 1, vector<int>(k + 2, 0));
	vector<int> sf(2010, 0);
	vector<pair<int, int> > a(m);
	for(auto&[x, y] : a) {
		cin >> x >> y;
		sf[x] = max(sf[x], y);
	}
	sort(all(a));
	for(int i = 1; i <=2000; ++i) {
		sf[i] = max(sf[i], sf[i - 1]);
	}
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= k; ++j) {
			if(i) f[i][j] = max(f[i][j], f[i - 1][j]);
			if(j) f[i][j] = max(f[i][j], f[i][j - 1]);
			int pos = sf[i + 1];
			if(pos > i) f[pos][j + 1] = max(f[pos][j + 1], f[i][j] + pos - i);
		}
	}
//	cerr << f[50][1] << "\n";
	int ans = 0;
	for(int t = 0; t <= k; ++t) ans = max(ans, f[n][t]);
	cout << "Case #"<<o<<": ";
	cout << ans << "\n";
}
int main() {
    int T;
    cin >> T;
    for(int o = 1; o <= T; ++o) {
		
		solve(o); 
	}
    return 0;
}

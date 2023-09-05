#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(m);
	vector<int> pos(n+1), H(n), ans(n+1);
	for(int i = 0; i < m; ++i) {
		a[i].resize(n);
		for(int j = 0; j < n; ++j) cin >> a[i][j];
		if(i==0) {
			for(int j=0; j<n;++j) pos[a[i][j]] = j;
			for(int j=0; j<n;++j) H[j]=j;
			// for(int j = 1; j <= n; ++j) cerr << pos[j] << " "; cerr << endl;
 
		} else {
			int minpos=n-1;
			for(int j=n-1;~j;--j) {
				H[pos[a[i][j]]]=min(H[pos[a[i][j]]], minpos);
				minpos=min(minpos, H[pos[a[i][j]]]);
			}
		}
		for(int j=n-2;~j;--j) {
			H[j] = min(H[j], H[j+1]);
		}
		for(int j=1;j<n;++j) H[j]=min(H[j], H[H[j]]);
		// for(int j = 0; j < n; ++j) cerr << H[j] << " "; cerr << endl;
	}
	for(int j=n-2;~j;--j) {
		H[j] = min(H[j], H[j+1]);
	}
	for(int i=1;i<=n;++i) ans[i]=n-1-H[pos[i]];
	for(int i=1;i<=n;++i) cout << ans[i] << " ";
	return 0;
}
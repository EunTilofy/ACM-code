#include<bits/stdc++.h>
using namespace std;

const int MN = 1000005;

int a[MN], num[MN];
vector<int> c[MN];

void solve() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i], c[i].clear();
	c[0].clear();

	vector<int> b, ans;
	for(int i = 1; i <= n; ++i) {
		if(upper_bound(b.begin(), b.end(), a[i]) == b.end()) {
			num[i] = b.size();
			b.push_back(a[i]);
		} else {
			num[i] = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
			b[num[i]] = a[i];
		}
		c[num[i]].push_back(i);
	}
	cout << b.size() << " ";
	int now = c[b.size() - 1][0];
	for(int i = b.size() - 2; ~i; --i) {
		int fd = -1;
		for(int j = 0; j < c[i].size(); ++j) 
			if(c[i][j] < now && a[c[i][j]] < a[now]) {fd = c[i][j]; break;}
		int o = a[fd];
		vector<int> aa;
		for(int k = now - 1; k > fd; --k) {
			if(a[k] > o) ans.push_back(k);
		}
		now = fd;
	}
	int o = 0;
	vector<int> aa;
	for(int k = now - 1; k > 0; --k) {
		if(a[k] > o) ans.push_back(k);
	}
	cout << ans.size() << "\n";
	reverse(ans.begin(), ans.end());
	for(auto &x : ans) {
		cout << x << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}
#include<bits/stdc++.h>
using namespace std;

const int MN = 200005;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> a(n);
	for(auto &[l,r] : a) cin >> l >> r;

	int l = a[0].first, r = a[0].second, ko = 0;
	
	for(int i = 1; i <= m; ++i) {
		int l1 = a[i].first, r1 = a[i].second;
		if(ko == 1) continue;
		else if(l1 > r || l > r1) ko = 1;
		else {
			l = max(l, l1);
			r = min(r, r1);
		}
	}

	set<pair<int,int>> S;
	if(ko == 0) S.insert({l, r});
	for(int i = m + 1; i < n; ++i) {
		S.insert(a[i]);
	}
	int ret = 0;
	int lastr = -1;
	for(auto [l,r] : S) {
		if(l <= lastr) ret += max(0, r - lastr), lastr = max(r, lastr);
		else ret += r - l + 1, lastr = r; 
	}
	cout << ret << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while(T--) solve();
}
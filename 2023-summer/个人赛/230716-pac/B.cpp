#include<bits/stdc++.h>
using namespace std;
const int MN = 5e5+5;
#define int long long
int n, m;
int a[MN], b[MN], l[MN], r[MN], id[MN];
bool cmp(int x, int y) {
	return l[x] < l[y] || (l[x] == l[y] && r[x] < r[y]);
}

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for(int i = 1; i <= m; ++i) {
		cin >> b[i] >> l[i] >> r[i];
	}
	vector<vector<long long>> in(n+1), out(n+1);
	for(int i = 1; i <= m; ++i) {
		in[l[i]].push_back(i);
		if(r[i] < n) out[r[i]+1].push_back(i);
	}
	set<pair<int,int>> S;
	long long ans = 0;
	for(int i = 1; i <= n; ++i) {
		for(auto x : in[i]) S.insert({r[x], x});
		for(auto x : out[i]) S.erase({r[x], x});
		while(a[i] > 0 && !S.empty()) {
			pair<int, int> o = *S.begin();
			int x = min(a[i], b[o.second]);
			b[o.second] -= x;
			a[i] -= x;
			ans += x;
			if(b[o.second] == 0) S.erase(o);
		}
	}
	// for(int i = 1; i <= m; ++i) id[i] = i;
	// sort(id+1,id+m+1,cmp);
	// long long ans = 0ll; int tmp = 0;
	// for(int i = 1; i <= m; ++i) {
	// 	int I = id[i];
	// 	tmp = max(tmp, l[I]);
	// 	while(tmp <= r[I] && b[I] > 0 && tmp <= n) {
	// 		int x = min(b[I], a[tmp]);
	// 		ans += x;
	// 		b[I] -= x; a[tmp] -= x;
	// 		if(a[tmp] == 0) ++tmp;
	// 	}
	// 	if(tmp > n) break;
	// }
	cout << ans << "\n";
	for(int i = 1; i <= n; ++i) a[i] = 0;
	for(int i = 1; i <= m; ++i) b[i] = l[i] = r[i] = id[i] = 0;
	n = m = 0;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while(T--) solve();

	return 0;
}
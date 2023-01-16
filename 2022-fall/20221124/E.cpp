#include<bits/stdc++.h>
using namespace std;

bool solve() {
	int n;
	cin >> n;
	vector<int> os;
	map<int, int> mp;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		if(x & 1) mp[x - 1] = 1;
		else os.push_back(x);
	}
	for(auto x : os) if(mp[x]) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	for(int o = 1; o <= T; ++o) {
		cout << (solve() ? "Yes\n" : "No\n");
	}
	return 0;
}
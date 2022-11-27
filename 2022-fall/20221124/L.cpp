#include<bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	int be = -1;
	for(int i = 1; i < s.size(); ++i) {
		if(s[i] != s[0]) {
			be = s.size() - i;
			break;
		}
	}
	cout << (int)s.size() + be << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	for(int o = 1; o <= T; ++o) {
		solve();
	}
	return 0;
}
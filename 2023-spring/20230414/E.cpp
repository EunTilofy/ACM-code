#include<bits/stdc++.h>
using namespace std;

int zh(char ch) {
	if(ch >= 'a' && ch <= 'z') return ch - 'a';
	return ch - '0' + 26;
}

void solve() {
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	int ans = 1e9, l = -1, r = -1;
	
//	cerr << "!!!\n";
	vector<vector<int> >  G(n + 1, vector<int> (40, -1));
	
	for(int i = n - 2; i >= 0; --i) {
		for(int j = 0; j < 40; ++j) G[i][j] = G[i + 1][j];
		G[i][zh(s[i + 1])] = i + 1;
	}
	
	for(int i = 0; i + m <= n; ++i) if(s[i] == t[0]) {
		int L = i;
		for(int j = 1; j < m; ++j) if(L!=-1){
			L = G[L][zh(t[j])];
		}
//		cerr << i << " " << L << "\n";
		if(L != -1) {
			int len = L - i + 1;
			if(len < ans) ans = len, l = i, r = L;
		}
	}
	for(int i = l; i <= r; ++i) {
		cout << s[i];
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for(int o = 1; o <= T; ++o) {
		solve();
	}
	
	return 0;
}
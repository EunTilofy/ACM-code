#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 26;
int cnt[2], tr[2][N][M], ed[2][N];

int Min(int x, int y) {
	if(x == -1) return y;
	else if(y == -1) return x;
	return min(x, y);
}
const int NM = 5010;
int f[NM][2];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	for(int o = 0, num; o < 2; ++o) {
		cin >> num;
//		cerr << cnt[0] << "\n";
		for(int i = 1; i <= num; ++i) {
			string s;
			cin >> s;
			int cur = 0;
			for(auto ch : s) {
				int pos = ch - 'a';
				if(!tr[o][cur][pos]) tr[o][cur][pos] = ++cnt[o];
				cur = tr[o][cur][pos];
			}
			ed[o][cur] = i;
		}
	}
	string s;
	cin >> s;
	int n = s.size();
	s = '0' + s;
//	cerr << s << "\n";
	memset(f, -1, sizeof f);
	f[0][1] = f[0][0] = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 2; ++j) {
			if(f[i][1 ^ j] == -1) continue;
			int cur = 0;
			for(int k = i + 1; k <= n; ++k) {
				int pos = s[k] - 'a';
				if(!tr[j][cur][pos]) break;
				cur = tr[j][cur][pos];
				if(ed[j][cur]) {
//					cerr << i + 1 << " " << k << "\n";
					f[k][j] = Min(f[k][j], f[i][1 ^ j] + 1);
//					cerr << "!!!" << f[k][j] << "\n";
				}
			}
		}
	}
//	cerr << f[n][0] << " " << f[n][1] << "\n";
	cout << Min(f[n][0], f[n][1]) << "\n";
	return 0;
}
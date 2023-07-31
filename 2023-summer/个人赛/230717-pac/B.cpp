#include<bits/stdc++.h>
using namespace std;

const int MN = 114518;
int f[MN], id[MN], cnt;
vector<std::bitset<MN>> bits;
unordered_set<long long> S;
unordered_set<int> s[MN];
int getf(int x) {
	if(x == f[x]) return x;
	return f[x] = getf(f[x]);
}
int n, m;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) f[i] = i;
	int UP = (int)(sqrt(n)+2);
	for(int i = 1; i <= m; ++i) {
		int opt, x, y;
		cin >> opt >> x >> y;
		if(x > y) swap(x, y);
		if(opt == 1) {
			S.insert(1ll*x*1000000+y);
			s[x].insert(y);
			s[y].insert(x);
			if(s[x].size()>UP) {
				if(id[x] == 0) {
					id[x] = cnt++;
					std::bitset<MN> _;
					for(auto z : s[x]) _.set(z-1, 1);
					bits.push_back(_);
				} else {
					bits[id[x]].set(y-1, 1);
				}
			} if(s[y].size()>UP) {
				if(id[y] == 0) {
					id[y] = cnt++;
					std::bitset<MN> _;
					for(auto z : s[y]) _.set(z-1, 1);
					bits.push_back(_);
				} else {
					bits[id[y]].set(x-1, 1);
				}
			}
			x = getf(x);
			y = getf(y);
			if(x != y) f[x] = y;
		} else {
			if(S.count(1ll*x*1000000+y)) {
				cout << "No" << "\n";
				continue;
			}
			else if(getf(x) != getf(y)) {
				cout << "No" << "\n";
				continue;
			}
			if(s[y].size()<s[x].size()) swap(x, y);
			if(s[x].size()<=UP) {
				bool fl = 0;
				for(auto z : s[x]) {
					if(s[z].count(y)) {fl = 1; break;}
				}
				if(fl) cout << "Yes" << "\n";
				else cout << "No" << "\n";
			} else {
				if((bits[id[x]]&bits[id[y]]).count()) cout << "Yes" << "\n";
				else cout << "No" << "\n";
			}
		}
	}
	return 0;
}
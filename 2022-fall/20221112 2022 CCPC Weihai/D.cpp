#include <bits/stdc++.h>
using namespace std;

const int M = 1e6 + 10;
int a[20], f[M];
struct edge {
	int x, y, z;
} e[30];
int ne;

int dfs(int zt) {
	if(f[zt] != -1) return f[zt];
	f[zt] = 0;
	vector<int> mk(20);
	for(int i = 0; i < 19; ++i) {
		if((zt >> i) & 1) {
			mk[i] = 1;
			f[zt] = max(f[zt], dfs(zt ^ (1 << i)));
		}
	}
	for(int i = 0; i < ne; ++i) {
		auto[x, y, z] = e[i];
		if(mk[y] && ((mk[x] && !mk[z]) || (!mk[x] && mk[z]))) {
			if(zt == ((1<<5) | (1<<9) | (1<<10))) {
//				cout << x << " " << y << " " << z << "\n";
			}
			f[zt] = max(f[zt], a[y] + dfs(zt ^ (1 << x) ^ (1 << y) ^ (1 << z)));
		}
	}
	return f[zt];
}

void init() {
ne = 27;
e[0] = {0,1,2},e[1] = {3,4,5},e[2] = {4,5,6},e[3] = {7,8,9},e[4] = {8,9,10},e[5] = {9,10,11},e[6] = {12,13,14},e[7] = {13,14,15},e[8] = {16,17,18},e[9] = {0,3,7},e[10] = {1,4,8},e[11] = {4,8,12},e[12] = {2,5,9},e[13] = {5,9,13},e[14] = {9,13,16},e[15] = {6,10,14},e[16] = {10,14,17},e[17] = {11,15,18},e[18] = {2,6,11},e[19] = {1,5,10},e[20] = {5,10,15},e[21] = {0,4,9},e[22] = {4,9,14},e[23] = {9,14,18},e[24] = {3,8,13},e[25] = {8,13,17},e[26] = {7,12,16};
	for(int i = 0; i < 19; ++i) cin >> a[i];
	int tot = (1 << 19) - 1;
	for(int i = 0; i <= tot; ++i) f[i] = -1;
	dfs(tot);
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	init();
	int q;
	cin >> q;	
	for(int o = 1; o <= q; ++o) {
		string s;
		int id = 0, zt = 0;
		for(int i = 1; i <= 5; ++i) {
			cin >> s;
			for(char ch : s) {
				if(ch == '#') zt |= (1 << id);
				++id;
			}
		}
//		cout << zt << " ";
		cout << f[zt] << "\n";
	}
	return 0;
}
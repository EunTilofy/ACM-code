#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 998244353;

int add(int x, int y) {
	return (x + y) % mod;
}
void Add(int &x, int y) {
	x = add(x, y);
}
int mul(int x, int y) {
	return 1ll * x * y % mod;
}
void Mul(int &x, int y) {
	x = mul(x, y);
}
int q_pow(int x, int y) {
	int ans = 1;
	for(; y; y >>= 1) {
		if(y & 1) Mul(ans, x);
		Mul(x, x);
	}
	return ans;
}

const int N = 55;
int f[N][4], a[N], p[N][N];

void cal(int st) {
	int len = 2;
	for(int i = 0; i < (1 << len); ++i) {
		vector<vector<int> > q(2);
		int np = 1;
		for(int j = 0; j < len; ++j) {
			int cur = (i >> j) & 1;
			int x = j * 2 + 1, y = j * 2 + 2;
			if(cur) {
				Mul(np, p[x][y]);
				q[0].push_back(j * 2 + 1);
				q[1].push_back(j * 2 + 2);
			} else {
				Mul(np, p[y][x]);
				q[0].push_back(j * 2 + 2);
				q[1].push_back(j * 2 + 1);
			}
		}
		for(int k = 0; k < (1 << len); ++k) {
			vector<vector<int> > nw(4);
			int nnp = np;
			for(int j = 0; j < len; ++j) {
				int cur = (k >> j) & 1;
				int x = q[j][0], y = q[j][1];
				if(cur) {
					if(!j) nw[0].push_back(x), nw[2].push_back(y);
					else nw[1].push_back(y), nw[2].push_back(x);
					Mul(nnp, p[x][y]);
				} else {
					if(!j) nw[0].push_back(y), nw[2].push_back(x);
					else nw[1].push_back(x), nw[2].push_back(y);
					Mul(nnp, p[y][x]);
				}
			}
			for(int j = 0; j <= 1; ++j) 
				for(int x : nw[j]) Add(f[st + x][j], nnp);
			int x = nw[2][0], y = nw[2][1];
			Add(f[st + x][2], mul(nnp, p[x][y]));
			Add(f[st + y][2], mul(nnp, p[y][x]));
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	// cerr << "!!!\n" << mul(54, q_pow(105, mod - 2)) << "\n";
	for(int i = 1; i <= 32; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i < 32; i += 4) {
		for(int j = 1; j <= 4; ++j)
			for(int k = 1; k <= 4; ++k) 
				p[j][k] = mul(a[i + j], q_pow(add(a[i + j], a[i + k]), mod - 2));
		cal(i);
	}
	// for(int i = 1; i <= 32; ++i) for(int j = 0; j < 3; ++j)
	// 	cerr << i << " " << j << " " << f[i][j] << "\n";
	int q;
	cin >> q;
	for(int o = 1, x; o <= q; ++o) {
		int ans = 0;
		cin >> x; Add(ans, f[x][0]);
		cin >> x; Add(ans, f[x][1]);
		for(int i = 1; i <= 7; ++i) {
			cin >> x;
			Add(ans, add(f[x][2], f[x][0]));
		}
		cout << ans << "\n";
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int tr[N];
int lower(int x) {
	return x & (-x);
}
void upd(int x, int k) {
	for(; x < N; x += lower(x)) tr[x] += k;
}
int get(int x) {
	int ans = 0;
	for(; x; x -= lower(x)) ans += tr[x];
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int o = 1, op, l, r; o <= m; ++o) {
		cin >> op >> l >> r;
		if(op == 1) {
			int x;
			cin >> x;
			upd(l, x), upd(r + 1, -x);
		} else {
			vector<int> qx(32);
			int flg = 0;
			for(int i = l; i <= r; ++i) {
				int pos = a[i] + get(i);
				for(int j = 31; j >= 0; --j) {
					if((pos >> j) & 1) {
						if(!qx[j]) {qx[j] = pos; break;}
						else pos ^= qx[j];
					}
				}
				if(!pos) {flg = 1; break;}
			}
			cout << (flg ? "Yes\n" : "No\n");
		}
	}
	return 0;
}
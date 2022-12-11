#include<bits/stdc++.h>
#define ll long long
using namespace std;

void sucess() {
	cout << "1\n";
	exit(0);
}

void fail() {
	cout << "0\n";
	exit(0);
}

bool pd(int l1, int r1, int l2, int r2) {
	return l1<=l2&&l2<=r1||l1<=r2&&r2<=r1;
}

int get(int nm, int a) {
	nm = max(nm, 0);
	return max(0, nm / a + (nm % a > 0));
}

int solve(int nm, int a, int x) {
	int ans = min(nm, 2 * a + 1);
	int l = 0, r = min(nm, 2 * a + 1);
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(get(nm - mid, a) <= x) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> d(n + 1), c(n + 1);
	for(int i = 1; i <= n; ++i) cin >> d[i];
	for(int i = 1; i <= n; ++i) cin >> c[i];
	if(!a) {
		ll sum = 0;
		for(int i = 1; i <= n; ++i) {
			if(d[i]) fail();
			sum += c[i];
		}
		if(sum > b) fail();
		else sucess();
	}
	if(!b) {
		ll sum = 0;
		for(int i = 1; i <= n; ++i) {
			if(c[i]) fail();
			sum += d[i];
		}
		if(sum > a) fail();
		else sucess();
	}
	int D = 0, C = 0;
	for(int i = 1; i <= n; ++i) {
		int nd = a + 1, nc = b + 1;
		if(d[i] && c[i]) {
			if(D <= a) {
				{// D -> nc
					int yu = a - D;
					int l = get(d[i] - yu, a), r = d[i];
					int L = get(c[i] - 1, b), R = c[i] - 1;
					if(pd(L, R, l, r)) nc = 1;
					else if(L > r) {
						nc = min(nc, 1 + solve(c[i] - 1, b, r));
					}
				}
				
				// D -> nd
				// c d c
				{
					int yu = a - D;
					int l = get(c[i], b) - 1, r = c[i] - 1;
					int L = get(d[i] - 1, a), R = d[i] - 1;
					if(pd(l, r, L, R)) nd = 1;
					else if(L > r) {
						int pos = solve(d[i] - 1, a, r);
						nd = min(nd, (pos >= yu) ? 1 + pos - yu : 1);
					}
				}
			}
			if(C <= b) {
				{// C -> nd
					int yu = b - C;
					int l = get(c[i] - yu, b), r = c[i];
					int L = get(d[i] - 1, a), R = d[i] - 1;
					if(pd(L, R, l, r)) nd = 1;
					else if(L > r) nd = min(nd, 1 + solve(d[i] - 1, a, r));
				}
				
				// C -> nc
				// d c d
				{
					int yu = b - C;
					int l = get(d[i], b) - 1, r = d[i] - 1;
					int L = get(c[i] - 1, b), R = c[i] - 1;
					if(pd(l, r, L, R)) nc = 1;
					else if(L > r) {
						int pos = solve(c[i] - 1, b, r);
						nc = min(nc, (pos >= yu) ? 1 + pos - yu : 1);
					}
				}
			}
		} else if(d[i]) {
			if(C <= b) nd = min(nd, d[i]);
			else nd = min(nd, d[i] + D);
		} else if(c[i]) {
			if(D <= a) nc = min(nc, c[i]);
			else nc = min(nc, c[i] + C);
		} else {
			nd = D, nc = C;
		}
		D = nd, C = nc;
		if(D > a && C > b) fail();
//		cerr << D << " " << C << "\n";
	}
	cout << "1\n";
	return 0;
}
/*
5 3 3
1 1 1 1 1
0 0 1 1 0
*/
#include<bits/stdc++.h>
using namespace std;
#define MN 1000005

bool vis[MN]; int n;
int a[MN], R[MN], pos[MN], f[MN];

int t[MN<<2][2];
void pushup(int k) {
	t[k][0] = min(t[k<<1][0], t[k<<1|1][0]);
	t[k][1] = max(t[k<<1][1], t[k<<1|1][1]);
}
void build(int k, int l, int r) {
	if(l == r) {
		t[k][0] = t[k][1] = a[l]; return;
	}
	int mid = (l + r) >>1;
	build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	pushup(k);
}
int qmin(int k, int l, int r, int a, int b) {
	if(l == a && r == b) return t[k][0];
	int mid = (l + r) >>1;
	if(b <= mid) return qmin(k<<1,l,mid,a,b);
	if(a > mid) return qmin(k<<1|1,mid+1,r,a,b);
	return min(qmin(k<<1,l,mid,a,mid), qmin(k<<1|1,mid+1,r,mid+1,b));
}
int qmax(int k, int l, int r, int a, int b) {
	if(l == a && r == b) return t[k][1];
	int mid = (l + r) >>1;
	if(b <= mid) return qmax(k<<1,l,mid,a,b);
	if(a > mid) return qmax(k<<1|1,mid+1,r,a,b);
	return max(qmax(k<<1,l,mid,a,mid), qmax(k<<1|1,mid+1,r,mid+1,b));
}
void C(int k, int l, int r, int a, int val = 0) {
	if(l == r) {
		t[k][1] = val;
		return;
	}
	int mid = (l + r) >>1;
	if(a <= mid) C(k<<1,l,mid,a, val);
	else C(k<<1|1,mid+1,r,a, val);
	pushup(k);
}

void solve() {
	build(1,1,n);
	for(int i = 1; i <= n; ++i) if(!vis[i]) {
		int p = a[i], r = a[i];
		vis[i] = vis[a[i]] = 1;
		while(p != i) {
			vis[p] = 1;
			p = a[p], r = max(r, p);
		}
		R[i] = r;
		int num = qmax(1, 1, n, i, R[i]);
		vector<int> vv;
		while(num > R[i]) {
			int j = pos[num];
			int pj = a[j], rj = a[j];
			vis[pj] = vis[j] = 1;
			vv.push_back(j);
			// cerr<<pos[num]<< "s " << num << endl;
			C(1, 1, n, j);
			while(pj != j) {
				vis[pj] = 1;
				pj = a[pj];
				rj = max(rj, pj);
			}
			R[i] = max(R[i], rj);
			num = qmax(1, 1, n, i, R[i]);
			// cerr << "num = " << num << endl;
		}
		for(auto &xx : vv) C(1, 1, n, xx, a[xx]);
		// cerr << a[xx] << endl;;
		if(qmin(1, 1, n, i, R[i]) < i) R[i] = 0;
		// cerr << i << " " << R[i] << endl;
	}

	f[n + 1] = 0;
	for(int i = n; i; --i) {
		if(R[i] != 0) {
			f[i] = 1;
			if(R[R[i] + 1] != 0) {
				f[i] += f[R[i] +1];
			}
		}
	}
	long long sum = 0;
	for(int i = 1; i <= n; ++i) sum += f[i];
	cout << sum << "\n";

	// int sum2 = 0;
	// for(int i = 1; i <= n; ++i) {
	// 	for(int j = i; j <= n; ++j) {
	// 		int mx = a[i], mi = a[i];
	// 		for(int k = i; k <= j; ++k) {
	// 			mx = max(mx, a[k]);
	// 			mi = min(mi, a[k]);
	// 		}
	// 		if(mx == j && mi == i) ++sum2;
	// 	}
	// }

	// if(sum != sum2) {
	// 	for(int i = 1; i <= 100; ++i) cout << a[i] << " ";
	// 	cout << "\n";
	// 	cout << sum << " " << sum2 << "\n";
	// 	exit(0);
	// }
	// cout << "pass"  << "\n";

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// int n;
	// cin >> n;
	// for(int i = 1; i <= n; ++i) {
	// 	cin >> a[i];
	// 	pos[a[i]] = i;
	// }

	// int n = 1000000;
	// for(int i = 1; i <= n; ++i) {
	// 	a[i] = n - i + 1;
	// }
	// for(int i = 1; i <= n; ++i) pos[a[i]] = i;

	// while(1) {
	// 	n = 100;
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			pos[a[i]] =i;
		}
		// for(int i = 1; i <= n; ++i) {
		// 	a[i] = n - i + 1;
		// }
		// random_shuffle(a+1,a+n+1);
		// for(int i = 1; i <= n; ++i) {
		// 	pos[a[i]] = i;
		// 	R[i] = 0;f[i] = 0;
		// 	vis[i] = 0;
		// }
		solve();
	// }
}
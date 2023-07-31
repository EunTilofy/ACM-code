#include<bits/stdc++.h>
using namespace std;

int a[100];
map<int, int> num;
int all;
void dfs(int now, int id, int n, int m) {
	if(id == n) {
		++all;
		set<int> s;
		// for(int i = 1; i <= n; ++i) cerr << a[i] << " "; cerr << "\n";
		for(int i = 1; i <= n; ++i) {
			int sum = 0;
			for(int j = i; j <= n; ++j) {
				sum += a[j];
				s.insert(sum);
			}
		}
		for(auto x : s) {
			if(x != m) num[x] ++;
		}
		return;
	}
	++id;
	if(id == n) a[id] = m - now, dfs(m, id, n, m);
	else {
		for(int i = 1; i <= m-now-(n-id); ++i) {
			a[id]=i;
			dfs(now+i,id,n,m);
		}
	}
}

int n, m;
int solve() {
	if(n == 1) return -1;
	if(n == m) return n - 1;
	if(2 * n > m) return n;
	return -1;
	// num.clear(); all = 0;
	// dfs(0, 0, n, m);
	// int ans = -1;
	// for(auto &[x, y] : num) if(y == all) ans = x;
	// return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while(T--) {
		cin >> n >> m;
		cout << solve() << "\n";
	}

	// for(int i = 1; i <= 15; ++i) {
	// 	for(int j = i; j <= 15; ++j) {
	// 		n = i, m = j; cout << solve() << " ";
	// 	}
	// 	cout << "\n";
	// }

	// n=4,m=5;cout << solve() << endl;

}
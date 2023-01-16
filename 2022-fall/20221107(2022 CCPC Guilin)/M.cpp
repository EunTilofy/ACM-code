#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3e5 + 10;
int tr[N];
void upd(int x, int k) {
	for(; x < N; x += (x & (-x))) tr[x] += k;
}
int get(int x) {
	int ans = 0;
	for(; x; x -= (x & (-x))) ans += tr[x];
	return ans;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	ll ans = 0;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		ans += i - get(a[i]);
		upd(a[i], 1);
	}
	cout << ans << "\n";
	string s;
	cin >> s;
	ll tot = 1ll * n * (n - 1) / 2;
	int now = 0;
	deque<int> q;
	for(int i = 0; i < n; ++i) q.push_back(a[i]);
	for(int i = 0; i < m; ++i) {
		if(s[i] == 'R') {
			ans = tot - ans;
			now ^= 1;
		} else {
			if(now) {
				int x = q.back();
				q.pop_back();
				q.push_front(x);
				ans = ans + n + 1 - 2 * x;
			} else {
				int x = q.front();
				q.pop_front();
				q.push_back(x);
				ans = ans + n + 1 - 2 * x;
			}
		}
		cout << ans % 10;
	}
	return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll, int> mp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	ll x;
	cin >> n;
	vector<ll> a(n);
	for(ll& y : a) cin >> y;
	cin >> x;
	sort(a.begin(), a.end());
	ll ans = 0;
	queue<ll> q;
	q.push(x), mp[x] =1;
	while(q.size()) {
		ll y = q.front(); q.pop();
		ans = max(ans, y % a[0]);
		for(int i = 1; i < n; ++i) {
			ll z = y % a[i];
			if(!mp.count(z)) {
				mp[z] = 1;
				q.push(z);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
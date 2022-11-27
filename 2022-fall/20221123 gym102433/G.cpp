#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6 + 10;
int s1[N], s2[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int> > v;
	int num = 0;
	for(int i = 1; i <= n; ++i) {
		string s;
		int t, l, a;
		cin >> s >> t >> l >> a;
		if(s[0] == 'h') {
			int L = t - 1 - a;
			int R = t + l - 2 - a;
			s1[++num] = L, s2[num] = R;
//			cerr << "hh" << L << " " << R << "\n";
		} else {
			v.push_back({t - 1 - a, t + l - 2 - a});
//			cerr << "vv" << t - 1 - a << " " << t + l - 2 - a << "\n";
		}
	}
	sort(s1 + 1, s1 + 1 + num), sort(s2 + 1, s2 + 1 + num);
//	cerr << "num = " << num << "\n";
	ll ans = 0;
	for(auto[l, r] : v) {
		int L = lower_bound(s2 + 1, s2 + 1 + num, l) - s2 - 1;
		int R = num - (lower_bound(s1 + 1, s1 + 1 + num, r + 1) - s1) + 1;
//		cerr << L << " " << R << "\n";
		ans += num - L - R;
	}
	cout << ans << "\n";
	return 0;
}
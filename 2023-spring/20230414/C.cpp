#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll s, c;
ll cal(ll res, ll R, ll pos) {
	ll ans = 0;
	pos = R;
	ans += (pos + res + 1) * (pos - res) / 2;
	pos = res;
	ll tmp = pos % (c + 1), len = pos / (c + 1);
	if(!tmp) tmp = c + 1;
	else len++;
	ans += c * (pos + tmp) * len / 2;
	return ans;
}

void solve() {
	cin >> s >> c;
	ll pos = c * (c + 1) / 2;
	
	ll Ans = 0, Ans1 = 0;
	
	if(s > pos) {
		Ans1 += (s + pos + 1) * (s - pos) / 2;
	} 
	// pos, pos - (c + 1), pos - 2 * (c + 1) ..
	pos = min(pos, s);
//	cerr << pos << " " << res << "\n";
	ll R = pos;
	// ll l = 1, r = R;
	// while(1) {
	// 	if(r - l <= 3) {
	// 		for(ll j = l; j <= r; ++j) Ans = max(Ans, cal(j, R, pos));
	// 		break;
	// 	}
	// 	ll mid1 = l + (r - l) / 3;
	// 	ll mid2 = r - (r - l) / 3;
	// 	if(cal(mid1, R, pos) > cal(mid2, R, pos)) r = mid2;
	// 	else l = mid1;
	// }
	for(int res = 1; res <= R; ++res) {
		Ans = max(Ans, cal(res, R, pos));
		// cout << cal(res, R, pos) << endl;
		// ll ans = 0;
		// pos = R;
		// ans += (pos + res + 1) * (pos - res) / 2;
		// pos = res;
		// ll tmp = pos % (c + 1), len = pos / (c + 1);
		// if(!tmp) tmp = c + 1;
		// else len++;
		// ans += c * (pos + tmp) * len / 2;
		// Ans = max(Ans, ans);
	}


	cout << Ans + Ans1 << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	for(int o = 1; o <= T; ++o) {
//		cerr << "!!!\n";
		solve();
	}
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MN = 1e6 + 4, P = 998244353;
#define int long long

long long n, m, a[MN];
int add(int x, int y) {
	return (x +y) % P;
}
int mul(int x, int y) {
	return (ll)x*y%P;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	long long mm = m;
	vector<pair<int, int>> div;
	for(int i = 2; i <= 10000000; ++i) {
		if(m % i == 0) {
			int step = 0;
			while(m%i == 0) {
				m/=i;
				++step;
			}
			div.push_back({i, step});
		}
	}
	int ans = 1;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] = __gcd(a[i], mm);
		int val = 1;
		for(int j = 0; j < div.size(); ++j){
			int x = div[j].first;
			int step1 = 0;
			long long num = x;
			while(a[i] % num == 0) {
				num = num * x;
				++step1;
			}
			val = mul(val, (1ll * (step1 + 1) * (step1 + 2) / 2 % P));
		}
		val = add(val, 1);
		ans = mul(ans, val);
	}
	ans = add(ans, P - 1);
	cout << ans << endl;
}
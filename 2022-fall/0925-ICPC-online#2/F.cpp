#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll pr[65], inf = 1e18;
int cnt = 0;
vector<ll> p1, p2;

vector<ll> go(ll k, ll x) {
	vector<ll> p; p.clear();
	int dep = 0;
	for(int i = cnt; i >= 0; --i) {
		if(pr[i] < x) {dep = i; break;}
	}
	for(; x != 1; ) {
//		printf("%lld\n", x);
		p.push_back(x);
		x -= pr[dep];
		x = (x - 1) / k + 1;
		for(int i = dep; i >= 0; --i) {
			if(pr[i] < x) {dep = i; break;}
		}
	}
	p.push_back(x);
	return p;
}

ll find(vector<ll> a, vector<ll> b) {
	for(int i = 0; i < (int)a.size(); ++i)
		for(int j = 0; j < (int)b.size(); ++j) {
			if(a[i] == b[j]) return a[i] ;
		}
}

void solve() {
	ll k, x, y;
	scanf("%lld%lld%lld", &k, &x, &y);
	memset(pr, 0, sizeof pr);
	pr[0] = 1;
	for(int i = 1; inf / pr[i - 1] >= k + 1; ++i) {
		pr[i] = pr[i - 1] * (k + 1);
		cnt = i;
//		printf("%lld\n", pr[i]);
	}	
	p1.clear(), p2.clear();
	p1 = go(k, x), p2 = go(k, y);
//	printf("%d %d\n", (int)p1.size(), (int) p2.size());
//	for(auto x : p1) printf("p1%lld\n", x);
//	for(auto x : p2) printf("p2%lld\n", x);
//	puts("???");
	printf("%lld\n", find(p1, p2));
}

int main() {
	int T; scanf("%d", &T);
	for(int o = 1; o <= T; ++o) {
		solve();
	}
	return 0;
}
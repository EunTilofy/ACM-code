#include<bits/stdc++.h>
using namespace std;

void solve() {
	int x, y, p;
	cin>>x>>y>>p;
	double ans = 0.0;
	double tmp = 1.0/(double)p, pr = 1.0;
	double ftmp = 1 - tmp;
	int num = x / y;
	double cover = (double)(x%y)/(double)y;
	for(int i = 1; i <= num; ++i) pr = pr * ftmp;
	ans = 1 - pr + cover * pr * tmp;
	cout<<fixed<<setprecision(15)<<ans<<endl;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for(int o = 1; o <= T; ++o) {
		solve();3
	}
	return 0;
}
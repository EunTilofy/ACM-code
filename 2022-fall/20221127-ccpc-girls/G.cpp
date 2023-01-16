#include<bits/stdc++.h>
using namespace std;
#define int long long
std::map<long long, bool> mp;
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int t;
	long long n;
	long long now = 0ll;
	cin>>t>>n; ++t;
	int m,k;
	cin>>m>>k;
	std::vector<pair<long long, int> > a;
	// cout<<t<<n<<m<<k<<endl;
	for(int i = 0; i < m; ++i) {
		long long ti, xi;
		// int num;
		cin>>ti>>xi; ++ti;
		// cout<<ti<<xi<<endl;
		a.push_back({ti, -xi});
		// cout<<a.back().first<<" "<<a.back().second<<endl;
		mp[ti] = 1;
	}
	// cout<<"xxxxx"<<endl;
	a.push_back({t, n});

	std::sort(a.begin(), a.end());
	// for(auto o : a) {cout<<o.first<<" "<<o.second<<endl;}
	bool awake = 0;
	int last = 0;
	std::vector<pair<long long, long long>> ans;
	for(int i = 0; i < a.size(); ++i) {
		long long ti = a[i].first;
		long long xi = -a[i].second;
		// cout<<ti-1<<" "<<xi<<" "<<now<<endl;
		if(last < ti) {
			now = max(0ll, now - 1ll * k * (ti - last));
			last = ti;
		}
		if(xi > 0) {
			now += xi;
			if(awake == 1) {
				ans.push_back({(now + k)/k, -ti});
			}
		}
		else {
			awake = 1;
			if(now != n) return 0 * puts("Wrong Record");
			if(mp[ti]) ans.push_back({(now+k)/k, -ti});
		}
	}
	sort(ans.begin(), ans.end());
	cout<<-ans[0].second-1<<" "<<ans[0].first<<endl;
	return 0;
}
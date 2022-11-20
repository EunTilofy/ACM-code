#include<bits/stdc++.h>
using namespace std;
#define INF 100000000000000000
#define inf 10000000000000000
#define se second
#define fi first
#define int long long
#define ll long long
long long cal(ll lmin, ll lmax, ll rmin, ll rmax) {
	rmin = max(rmin, lmin);
	lmax = min(lmax, rmax);
	if(rmax-rmin+1<=0 || lmax-lmin+1<=0) return 0ll;
	if(rmin > lmax) {
		return 1ll * (rmax-rmin+1) * (lmax - lmin + 1);
	}
//	cerr<<lmin<<" "<<lmax<<" "<<rmin<<" "<<rmax<<endl;
	return (rmin-lmin)*(rmax-rmin+1)+(lmax-rmin+1)*(rmax-lmax)+(lmax-rmin+1)*(lmax-rmin)/2ll+(lmax-rmin+1);
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T; cin>>T;
	while(T--) {
		int n; cin>>n;
		long long lmin = 1, lmax = INF;
		long long rmin = 1, rmax = INF;
		vector<pair<long long, long long>> t;
		for(int i = 1; i <= n; ++i) {
			int opt, k, x;
			cin>>opt>>k>>x;
			if(opt==1) {
				lmax = min(lmax, (x-1ll*k*(k-1)/2)/k);
				rmin = max(rmin, (x+1ll*k*(k-1)/2+k-1)/k);
			}
			else {
				t.push_back({(x-1ll*k*(k-1)/2)/k+1, (x+1ll*k*(k-1)/2+k-1)/k-1});
			}
		}
		long long ans = 0;
		std::sort(t.begin(), t.end());
		std::multiset<long long> rs;
		for(auto o : t) {
			rs.insert(o.se);
		}
		rs.insert(INF);
		int id = -1;
		while(id + 1 < t.size() && t[id+1].fi <= lmin) ++id;
		for(int u=0; u<=id; ++u) rs.erase(rs.find(t[u].se));
		rmax = *(rs.begin());
		if(rmax==INF&&lmax-lmin+1>0) {
			ans = -1;
		}
		else{
		long long val = INF;
		if(id+1<t.size()) val = min(val, t[id+1].fi-1);
		ans += cal(lmin, min(lmax, val), rmin, rmax);
		for(int i = id+1; i < t.size(); ++i) {
			int j = i;
			lmin = max(lmin, t[i].fi);
			while(j + 1 < t.size() && t[j+1].fi <= lmin) ++j;
			for(int u = i; u <= j; ++u) rs.erase(rs.find(t[u].se));
			rmax = *(rs.begin());
			if(rmax==INF&&lmax-lmin+1>0) {
				ans = -1;
				break;
			}
			long long val = INF;
			if(j+1<t.size()) val = min(val, t[j+1].fi-1);
			ans += cal(lmin, min(lmax, val), rmin, rmax);
			i = j;
		}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
8
2
1 1 2
2 1 4
2
1 1 4
2 1 2
2
1 1 1
2 1 1
4
2 1 15
1 5 20
1 3 8
2 2 25
2
1 1 2
2 1 4
2
1 1 4
2 1 2
2
1 1 1
2 1 1
4
2 1 15
1 5 20
1 3 8
2 2 25
*/
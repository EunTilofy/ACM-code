#include<bits/stdc++.h>
using namespace std;
#define MN 200005
#define MM 500005
#define pb push_back
#define REP(i,a,b) for(int i=(a); i<(b); ++i)
#define DREP(i,a,b) for(int i=(a); i>(b); --i)
#define fi first
#define se second
int p[MN], n, m;
std::vector<int> pre[MN], nex[MN];
int _[MN], __[MN], ind[MN];
typedef pair<int,int> pii;
pii b[MN];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T;
	cin>>T;
	while(T--) {
		cin>>n>>m;
		for(int i = 1; i <= n; ++i) cin>>p[i];
		for(int i = 1; i <= m; ++i) {
			int x, y;
			cin>>x>>y;
			pre[y].pb(x);
			nex[x].pb(y);
			++_[x];
			++__[y];
		}
		std::queue<int> q;
		REP(i, 1, n + 1) {
			b[i] = {1, n};
			if(!_[i]) q.push(i);
		}
		int dind = n;
		bool flag = 1;
		while(!q.empty()) {
			int o = q.front(); q.pop();
			ind[o] = dind--;
			for(auto oo : pre[o]) {
				if(!--_[oo]) q.push(oo);
				b[oo].r=min(b[oo].r, b[o].r);
				if(p[o]>0) b[oo].r=min(b[oo].r, p[o]-1);
			}
		}
		REP(i, 1, n + 1) if(!__[i]) q.push(i);
		while(!q.empty()) {
			int o = q.front(); q.pop();
			for(auto oo : nex[o]) {
				if(!--__[oo]) q.push(oo);
				b[oo].l = max(b[oo].l, b[o].l);
				if(p[o]>0) b[oo].l = max(b[oo].l, p[o]+1);
			}
		}
		REP(i, 1, n + 1) {
			if(p[i] == 0) flag &= b[i].r >= b[i].l;
			else flag &= (b[i].r >= p[i]) && (p[i] >= b[i].l);
		}
		if(flag) {
			set<pair<pair<int,int>, pair<int,int>>> X;
			set<int> S;
			REP(i, 1, n + 1) {
				S.insert(i);
			}
			int NUM = n;
			REP(i, 1, n + 1) {
				if(p[i] > 0) S.erase(i), --NUM;
				else X.insert({{b[i].r, b[i].l}, {ind[i],i}});
			}
			S.insert(n+1);
			while(NUM--) {
				pair<pair<int,int>, pair<int,int>> o = *S.begin();
				X.erase(o);
				int x=S.lower_bound(o.fi.se);
				if(x<=o.fi.fi) {
					p[o.se.se] = x;
					S.erase(x);
					for(auto oo : nex[o])
				}
				else {
					flag = 0;
					break;
				}
			}
			if(flag) {
				REP(i, 1, n + 1) cout<<p[i]<<" ";
				cout<<endl;
			}
		}
		if(!flag) cout<<"-1"<<endl;
	}
	return 0;
}
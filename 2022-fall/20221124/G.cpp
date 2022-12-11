#include<bits/stdc++.h>
using namespace std;
vector<int> G[2005];
int n;
int Num = 0, deg[2005];
int a[1005][1005];
int l[1005], r[1005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) {
		int x;
		cin>>x;
		a[i][j] = x;
		if(x==-1) {
			a[i][j] = 0;
			G[i].push_back(j+n), G[j+n].push_back(i);
			Num+=!deg[i]++;
			Num+=!deg[j+n]++;
		}
		else {
			l[i]^=x;
			r[j]^=x;
		}
	}
	for(int i = 1; i <= n; ++i) {
		int x;
		cin>>x;
		l[i]^=x;
//		cout<<l[i]<<" ";
	}
//	cout<<endl;
	for(int j = 1; j <= n; ++j) {
		int y;
		cin>>y;
		r[j]^=y;
//		cout<<r[j]<<" ";
	}
//	cout<<endl;
	queue<int> q;
	for(int i = 1; i <= n + n; ++i) if(deg[i]==1) q.push(i);
	int has = 0;
	while(!q.empty()) {
		++has;
		int o = q.front();
//		cout<<o<<endl;
		q.pop();
		for(auto v : G[o]) {
			if(deg[v] == 0) continue;
			int x = o, y = v;
			if(x > y) swap(x,y);
			y-=n;
			if((o<=n&&l[o])||(o>n&&r[o-n])) {
				a[x][y] = 1;
				l[x]^=1;
				r[y]^=1;
			}
			--deg[v];
			if(deg[v] == 1) q.push(v);
		}
		deg[o] = 0;
	}
	if(has != Num) cout<<"-1"<<endl;
	else {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) cout<<a[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}
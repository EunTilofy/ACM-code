#include<bits/stdc++.h>
using namespace std;
std::map<string, int> t[10005];
int val[10005], lef[10005];
int tot = 1;
int ans = 0;
void dfs(int x) {
	int son = 0;
	for(auto y : t[x]) {
		++son;
	}
	if(son == 0) {
		lef[x] = 1;
	}
	else {
		lef[x] = val[x] = 0;
	}
	for(auto y : t[x]) {
		// cerr<<"dfs"<<" "<<x<<" "<<y.first<<" "<<y.second<<endl;
		dfs(y.second);
		lef[x] = lef[x] + lef[y.second];
		val[x] = val[x] + val[y.second];
	}
}
void dfs2(int x) {
	if(val[x] == lef[x]) {++ans; return;}
	for(auto y : t[x]) {
		dfs2(y.second);
	}
}
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	string s;
	int T; cin>>T;
	while(T--) {
		int n, m;
		cin>>n>>m;
		for(int i = 1; i <= n; ++i) {
			cin>>s;
			int len = s.size();
			string now = "";
			int p = 1;
			for(int r = 0; r <= len; ++r) {
				if(s[r] == '/' || r == len) {
					// cerr<<now<<"1"<<endl;
					if(!t[p][now]) t[p][now] = ++tot;
					p = t[p][now];
					now = "";
				}
				else {now = now + s[r];}
				if(r == len) {
					val[p] = 1;
				}
			}
		}
		for(int i = 1; i <= m; ++i) {
			cin>>s;
			int len = s.size();
			string now = "";
			int p = 1;
			for(int r = 0; r <= len; ++r) {
				if(s[r] == '/' || r == len) {
					// cerr<<now<<"2"<<endl;
					if(!t[p][now]) t[p][now] = ++tot;
					p = t[p][now];
					now = "";
				}
				else {now = now + s[r];}
			}
		}
		dfs(1);++lef[1];dfs2(1);
		printf("%d\n", ans);
		ans = 0;
		for(int i = 1; i <= tot; ++i) t[i].clear(), val[i] = lef[i] = 0;
		tot = 1;
		// cerr<<"-----"<<endl;
	}
 	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int tt = 1, ch[50000*50+10][29];
int get(char c) {
	if(c=='.') return 27;
	if(c=='/') return 28;
	return c-'a'+1;
}
#define MN 50000*50+10
int pos[MN], siz[MN], has[MN], fa[MN];
void dfs(int x) {
	for(int i = 1; i <= 28; ++i) if(ch[x][i]) {
		dfs(ch[x][i]);
		siz[x] += siz[ch[x][i]];
	}
	return;
}
std::set<int> _[MN];
void delt(int x) {
	int num = x;
	while(x!=1) {
		_[x].erase(num);
		x = fa[x];
	}
	return;
}
void add(int x) {
	int num = x;
	while(x!=1) {
		_[x].insert(num);
		x = fa[x];
	}
	return;
}
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	cin>>n;
	for(int i = 1; i <= n; ++i) {
		string s;
		cin>>s;
		int len = s.size();
		int p = 1;
		for(int i = 0; i < len; ++i) {
			int x = get(s[i]);
			if(!ch[p][x]) {
				ch[p][x] = ++tt;
				fa[ch[p][x]] = p;
			}
			p = ch[p][x];
		}
		pos[i] = p;
		siz[p] = 1;
	}
	dfs(1);
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		int p = pos[i];
		while(p!=1) {
			has[p] ++;
			p = fa[p];
		}
		p = pos[i];
		while(fa[p] != 1 && has[fa[p]] == siz[fa[p]]) {
			p = fa[p];
		}
		vector<int> tmp;
		for(auto x : _[p]) tmp.push_back(x);
		for(auto x : tmp) {
			delt(x);
			--ans;
		}
		++ans;
		add(p);
		cout<<ans<<endl;
	}
	return 0;
}
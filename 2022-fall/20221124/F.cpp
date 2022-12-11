#include<bits/stdc++.h>
using namespace std;
const int MN = 5e4 + 10;
string s[MN];
int ch[MN * 101][10], tt = 1;
int siz[MN * 101], szz[MN * 101];
int n;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin>>s[i];
		int p = 1;
		for(auto x : s[i]) {
			if(!ch[p][x-'0']) ch[p][x-'0'] = ++tt;
			p = ch[p][x-'0'];
			siz[p]++; szz[p]++;
		}
	}
//	for(int i = 1; i <= tt; ++i) cout<<siz[i]<<" ";cout<<endl;
	long long ans = 0;
	for(int i = 1; i <= n; ++i) {
		int len = s[i].size();
		for(int sz = len; sz; --sz) {
			int fr = len - sz;
			int p = 1, fl = 1;
			for(int j = fr; j < len; ++j) {
				if(!ch[p][s[i][j]-'0']) {fl = 0; break;}
				else p = ch[p][s[i][j]-'0'];
			}
			if(fl) {
				ans += 1ll * szz[p] * sz;
//				cout<<i<<" "<<sz<<" "<<szz[p]<<" "<<p<<endl;
				int xxx = szz[p]; p = 1; fr = len -sz;
				for(int j = fr; j < len; ++j) {
					p = ch[p][s[i][j]-'0'];
					szz[p] -= xxx;
//					cout<<"dec"<<" "<<p<<" "<<xxx<<endl;
				}
			}
		}
		for(int sz = len; sz; --sz) {
			int fr = len - sz;
			int p = 1;
			for(int j = fr; j < len; ++j) {
				if(!ch[p][s[i][j]-'0']) {break;}
				else {
					p = ch[p][s[i][j]-'0'];
					szz[p] = siz[p];
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
3
10101
01010
11111
*/
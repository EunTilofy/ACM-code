#include<bits/stdc++.h>
using namespace std;
std::map<string, int> mp;
int nm[5], _nm[5];
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n, m;
	std::cin>>n;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= 5; ++j) {
			string x;
			cin>>x;
			mp[x] = j;
		}
	}
	std::cin>>m;
	int xx = 0;
	for(int i = 1; i <= m; ++i) {
		string x;
		int pos;
		cin>>x>>pos;
		if(mp[x]) {
			++_nm[pos];
			++xx;
		}
		else ++nm[pos];
	}
	int ans = xx;
	for(int i = 1; i <= 5; ++i) ans = min(ans, nm[i]+_nm[i]);
	cout<<ans<<endl;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n, m;
	cin>>n>>m;
	std::vector<string> s(n), t(n);
	for(int i = 0; i < n; ++i) {
		cin>>s[i];
	} 
	int nm = 0;
	for(int i = 0; i < n; ++i) {
		cin>>t[i];
		for(int j = 0; j < m; ++j) nm += s[i][j] != t[i][j];
	}
	// cout<<nm<<endl;
	if(nm * 2 > n * m) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) cout<<(s[i][j] == '.' ? 'X' : '.');
			cout<<endl;
		}
	}
	else {
		for(int i = 0; i < n; ++i) cout<<s[i]<<endl;
	}
 	return 0;
}
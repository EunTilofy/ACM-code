#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	vector<int> a(26);
	for(char ch : s) a[ch - 'a']++;
	int ans = 1;
	for(int i = 0; i < 26; ++i) {
		ans = 1ll * ans * (a[i] + 1) %  11092019;
	}
	cout << ans << "\n";
	return 0;
}
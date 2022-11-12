#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	vector<int> mk(n + 1);
	for(int i = 0; i < n; ++i) {
		if(s[i] == 'L') {
			mk[i] = 1, mk[i + 1] = 1;
			if(i) mk[i - 1] = 1;
		}
	}
	for(int i = 0; i < n; ++i) {
		if(mk[i]) cout << s[i];
		else cout << 'C';
	}
	return 0;
}
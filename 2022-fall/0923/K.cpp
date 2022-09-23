#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin>>s;
	int len = s.size();
	for(int i = 0; i < len - 2; ++i) {
		if(s[i] == 'A' && s[i + 1] == 'C' && s[i + 2] == 'M') {return 0 * puts("Fun!");}
	}
	return 0 * puts("boring...");
}
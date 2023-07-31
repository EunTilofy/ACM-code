#include<bits/stdc++.h>
using namespace std;
bool a[1000005];
int b[1000005];

int p2[21];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	p2[0] = 1;
	for(int i = 1; i <= 20; ++i) p2[i] = 2 * p2[i - 1];

	for(int i = n - 1; ~i; --i) {
		if(a[i]) continue;
		for(int j = 20; ~j; --j) {
			int y = p2[j] - 1 - (i & (p2[j] - 1));
			// cerr << y << endl;
			if(y >= n) continue;
			assert((y^i)==y+i);
			if(!a[y]) {
				a[y] = 1;
				a[i] = 1;
				b[y] = i;
				b[i] = y;
				break;
			}
		}
		if(!a[i]) {
			cout << "-1";
			return 0;
		}
	}
	for(int i = 0; i < n; ++i) cout << b[i] << " ";

}
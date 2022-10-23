#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, mod = 1e9 + 7;

int f[N][2];

int d(int x) {
	int y=sqrt(x) + 2;
	for(int i=2; i<=min(x - 1,y); i++)if(x%i==0)return i;
	return -1;
}

int add(int x, int y) {
	return (1ll * x + y) % mod;
}
void Add(int &x, int y) {
	x = add(x, y);
}

vector<int> q[N];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int a, b;
	cin >> a >> b;
	
	
	for(int i = a; i <= b; ++i) {
		int L = d(i), R = i / L;
		if(L == -1) continue;
		for(int j = L; j <= R; ++j) {
			int pos = i - j;
			if(pos >= a) q[pos - a + 1].push_back(i);
		}
	}
	
	f[1][0] = 1;
	for(int i = a; i <= b; ++i) {
		int x = i, L = d(x);
		if(L != -1) {
			int R = x / L;
//			cout << i << " " << L << " " << R << endl;
			for(int j = L; j <= min(b - i, R); ++j) Add(f[j + i - a + 1][1], f[i - a + 1][0]);
		}	
		for(auto x : q[i - a + 1]) Add(f[x - a + 1][0], f[i - a + 1][1]);
		cout << i << " " << f[i - a + 1][0] << endl;
	}
	cout << add(f[b - a + 1][0], f[b - a + 1][1]);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

void solve() {
	long long B, R, D, S;
	cin >> B >> R >> D >> S;
	if(R == 0) {
		if(D > 0) cout << "gua!" << endl;
		else cout << "ok" << endl;
		return;
	}
	if(B * ((R * S) / 60ll + 1ll) < D) cout << "gua!" << endl;
	else cout << "ok" << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for(int o = 1; o <= T; ++o) {
		solve();
	}
	
	return 0;
}
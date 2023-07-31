#include<bits/stdc++.h>
using namespace std;

int solve() {
	long long n;
	cin >> n;

	int ans = 0;
	while(n>0) {
		if(n == 1) {
			ans += 1;
			break;
		}
		int step = 0;
		while((1<<(step+1)) <= n) ++step;

		ans += n - (1<<step) + 1;

		n = (1<<(step+1)) - n - 1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while(T--) cout << solve() << "\n";
}
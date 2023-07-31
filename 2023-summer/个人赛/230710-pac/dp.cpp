#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	int n;
	cin >> n;

	vector<int> a(n+1);
	for(int i = 1; i <= n; ++i) cin >> a[i];

	int ans = 0, num = 0;
	vector<int> pr;

	for(int s = 0; s < (1<<n); ++s) {
		vector<int> b(n+1);
		int cnt = 0;
		for(int i = 1; i <= n; ++i) {
			if((s>>(i - 1)) & 1) b[i] = 0, ++cnt;
			else b[i] = a[i];
		}
		int aa = 0, now = 0;
		for(int i = 1; i <= n; ++i) {
			if(b[i] > now) ++aa, now = b[i];
		}
		if(aa > ans || (aa == ans && cnt < num)) {
			ans = aa;
			num = cnt;
			pr.clear();
			for(int i = 1; i <= n; ++i) {
				if((s>>(i - 1)) & 1) pr.push_back(i);
			}
		}
	}

	cout << ans << " " << num << endl;
	for(auto x : pr) cout << x << endl;
}
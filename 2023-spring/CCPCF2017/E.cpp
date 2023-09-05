#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0; 
    for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		ans += x;
		ans += x / 10;
		ans += (x % 10) > 0;
	} 
	cout << ans << "\n";
}
int main() {
    int T;
    cin >> T;
    for(int o = 1; o <= T; ++o) {
		cout << "Case #"<<o<<": ";
		solve(); 
	}
    return 0;
}

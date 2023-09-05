#include<bits/stdc++.h>
using namespace std;

const int MN = 1e6+5;
int a[MN<<2];
int n, m, k;

int ssolve(int l, int r) {
    int ans = (r - l + k) / k;
    // cout << l << " " << r << "ss : " << ans << endl;
    for(int i = l - 1; i; --i) {
        int j = i;
        while(j - 1 >= 1 && (a[j-1] == a[i])) --j;
        ans += (i - j + k) / k;
        // cout << i << " " << j << "ss : " << ans << endl;
        i = j;
    }
    for(int i = r + 1; i <= n; ++i) {
        int j = i;
        while(j + 1 <= n && a[j + 1] == a[i]) ++j;
        ans += (j - i + k) / k;
        // cout << i << " " << j << "ss : " << ans << endl;
        i = j;
    }
    return ans;
}

void solve() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int nn = 0;
    while(a[nn+1] == a[n+nn] && nn <= n) {
        ++nn; a[n+nn] = a[nn];
    }
    for(int i = 1; i <= n; ++i) a[i] = a[i + nn];
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        int j = i;
        while(j + 1 <= n && a[j + 1] == a[i]) ++j;
        if(j - i + 1 >= k) {
            cout << ssolve(i, j) << endl;
            return;
        }
        i = j;
    }
    cout << -1 << endl;
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
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, X, Y;
int a[200005];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> m >> X >> Y;
    for(int i = 1; i <= m; ++i) cin >> a[i];
    int l = 1;
    vector<pair<int,int>> b;
    // sort(a+1,a+m+1);
    if(a[1] > 1) b.push_back({1, a[1] - 1});
    a[m+1] = n + 1;
    for(int i = 1; i <= m; ++i) {
        if(a[i] + 1 < a[i + 1]) b.push_back({a[i] + 1, a[i + 1] - 1});
    }
    if(m == 0) b.push_back({1, n});
    int last = 0, day = -100;
    int cnt = 0;
    for(auto [l, r] : b) {
        // cerr << l << " " << r << endl;
        int len = r - l + 1;
        if(l - 2 == day) {
            int first = min(len, min(X, Y - last));
            cnt += len / (Y + 2) * 2ll;
            int ret = len % (Y + 2);
            if(ret > first) ++cnt, ret -= first + 1;
            last = ret;
            if(last == 0) day = r - 1;
            else day = r;
        } else {
            cnt += len / (Y + 2) * 2ll;
            int ret = len % (Y + 2);
            if(ret > X) ++cnt, ret -= X + 1;
            last = ret;
            if(last == 0) day = r - 1;
            else day = r;
        }
    }
    cout << cnt << endl;
	return 0;
}
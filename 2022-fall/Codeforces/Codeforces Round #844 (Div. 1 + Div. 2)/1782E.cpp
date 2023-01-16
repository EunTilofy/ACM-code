#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<long long,long long> pii;
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define pb push_back
void solve(){
	int n; cin >> n;
    vector<pair<pii, pii>> a[3];
    for(int i = 1; i <= n; ++i) {
        int u, d, l, r;
        cin >> u >> l >> d >> r;
        if(u == 1 && d == 2) a[0].pb({{l, r}, {i, 0}});
        if(u == 1 && d == 1) a[1].pb({{l, r}, {i, 0}});
        if(u == 2 && d == 2) a[2].pb({{l, r}, {i, 0}});
    }
    sort(all(a[0]));
    sort(all(a[1]));
    sort(all(a[2]));
    vector<pii> b[3];
    vector<int> type;
    
    for(int j = 0; j < 3; ++j) {
        int R = -1;
        for(auto &x : a[j]) {
            int l = x.fi.fi, r = x.fi.se;
            if(l > R) {
                b[j].pb({l, r});
                type.pb(3);
            }
            else if(r > R) {
                x.fi.fi = R + 1;
                b[j].back().se = r;
            } else {
                x.fi = {0,0};
            }
            x.se.se = b[j].size()-1;
            R = max(R, r);
        }
    }


    for(int k = 1; k <= 2; ++k) {
        for(int i = 0, j = 0; i < b[k].size(); ++i) {
            while(j < b[0].size() && b[0][j].se < b[k][i].fi) ++j;
            if(j < b[0].size() && b[0][j].se >= b[k][i].se && b[0][j].fi <= b[k][i].fi) {
                b[k][i] = {0, 0};
                continue;
            }
            if(j < b[0].size() && b[0][j].fi <= b[k][i].fi) b[k][i].fi = b[0][j].se + 1, ++j;
            while(j < b[0].size() && b[0][j].se <= b[k][i].se) type[j]-=(1<<(k-1)), ++j;
            if(j < b[0].size() && b[0][j].fi <= b[k][i].se) b[k][i].se = b[0][j].fi - 1;
            if(b[k][i].fi > b[k][i].se) b[k][i] = {0, 0};
        }
    }

    long long ans = 0;
    vector<pair<int, pair<pii, pii>>> prt;
    pii _00 = {0, 0};
    for(int i = 0; i < a[0].size(); ++i) {
        int bel = a[0][i].se.se;
        pii xx = {1, 2};
        if(type[bel] == 0) xx = {0, 0}, a[0][i].fi = {0, 0};
        else {
            if(type[bel] == 1) xx = {1, 1};
            if(type[bel] == 2) xx = {2, 2};
            if(b[0][bel] == _00) a[0][i].fi = {0, 0}; else {
                a[0][i].fi = {max(a[0][i].fi.fi, b[0][bel].fi), min(a[0][i].fi.se, b[0][bel].se)};
            }
        }
        if(a[0][i].fi.fi > a[0][i].fi.se) a[0][i].fi = {0, 0};
        if(a[0][i].fi == _00) xx = {0, 0};
        if(xx == _00) a[0][i].fi = _00;
        if(xx != _00) ans += (xx.se - xx.fi + 1) * (a[0][i].fi.se - a[0][i].fi.fi + 1);
        prt.pb({a[0][i].se.fi, {xx, a[0][i].fi}});
    }
    for(int k = 1; k <= 2; ++k) {
        for(auto &x : a[k]) {
            int bel = x.se.se;
            pii xx = {k, k};
            if(b[k][bel] == _00) x.fi = {0, 0}; else {
                x.fi = {max(x.fi.fi, b[k][bel].fi), min(x.fi.se, b[k][bel].se)};
            }
            if(x.fi.fi > x.fi.se) x.fi = {0, 0};
            if(x.fi == _00) xx = {0, 0};
            if(xx == _00) x.fi = _00;
            if(xx != _00) ans += x.fi.se - x.fi.fi + 1;
            prt.pb({x.se.fi, {xx, x.fi}});
        }
    }
    sort(all(prt));
    cout << ans << endl;
    for(auto x : prt) {
        cout << x.se.fi.fi << " " << x.se.se.fi << " " << x.se.fi.se << " " << x.se.se.se << endl;
    }
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
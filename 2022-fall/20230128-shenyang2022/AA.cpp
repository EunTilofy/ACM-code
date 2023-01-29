#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<long double, long double> pii;
int n, m;
std::vector<pii> s, t;
#define MN 100005
long double sp[MN], tp[MN];
bool crs(pii x, pii y) {
    return !(x.se<=y.fi||x.fi>=y.se);
}
long double ccal(int x, int y, int a, int b) {
    if(!crs({a,b}, {x,y})) return (double)(y-x)/3.0;
    long double mid1 = (x + y) / 2.0;
    long double mid2 = (a + b) / 2.0;
    return fabs(mid1 - mid2);
}
long double cal(pii x, pii y) {
    vector<long double> _;
    _.push_back(x.fi);
    _.push_back(x.se);
    _.push_back(y.fi);
    _.push_back(y.se);
    sort(_.begin(), _.end());
    long double ret = 0.0;
    for(int i = 0; i < 3; ++i) {
    for(int j = 0; j < 3; ++j) {
        int l1 = _[i];
        int r1 = _[i+1];
        int l2 = _[j];
        int r2 = _[j+1];
        if(r1>l1&&r2>l2){
            if(crs({l1,r1}, x) && crs({l2,r2}, y)) {
                ret += (r1-l1)*(r2-l2)*ccal(l1,r1,l2,r2);
            }
        }
    }
    }
    return ret;
}
signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        long double l, r;
        cin >> l >> r;
        if(r-l<1e-9) r = l + 1e-9;
        s.push_back({l, r});
    }
    for(int i = 1; i <= m; ++i) {
        long double l, r;
        cin >> l >> r;
        if(r-l<1e-9) r = l + 1e-9;
        t.push_back({l, r});
    }
    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());
    for(int i = 0; i < m; ++i) {
        sp[i] = (double)(t[i].se - t[i].fi);
        tp[i] = (double)(t[i].se - t[i].fi) * (t[i].se + t[i].fi) / 2.0;
    }
    for(int i = 1; i < m; ++i) {
        sp[i] = sp[i - 1] + sp[i];
        tp[i] = tp[i - 1] + tp[i];
    }
    int j = 0;
    long double ans = 0, sums = 0;
    for(pii x : s) {
        sums += x.se - x.fi;
        while(j < m && (t[j].se<=x.fi)) ++j;
        double mid = (x.fi + x.se) / 2.00;
        if(j-1>=0) {
            ans += (x.se - x.fi) * (mid*sp[j-1]-tp[j-1]);
        }
        while(j < m && crs(t[j], x)) {
            ans += cal(t[j], x);
            ++j;
        }
        if(j<m) {
            ans += (x.se - x.fi) * 
                (tp[m-1]-(j>0?tp[j-1]:0)-mid*(sp[m-1]-(j>0?sp[j-1]:0)));
        }
        if(j>0) --j;
    }
    ans/=sums;
    ans/=sp[m-1];
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
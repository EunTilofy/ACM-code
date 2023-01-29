#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
#define int long long
#define ll long long
typedef pair<long long, long long> pii;
ll n, m;
long double sums;
std::vector<pair<long long, long long>> s, t;
#define MN 100005
long double sp[MN], tp[MN];
bool crs(pii x, pii y) {
    return !(x.se<=y.fi||x.fi>=y.se);
}
long double ccal(int x, int y, int a, int b) {
    if(x == a && y == b) return (long double)(y-x)/3.0;
    long double mid1 = (x + y) / 2.0;
    long double mid2 = (a + b) / 2.0;
    return fabs(mid1 - mid2);
}
long double cal(pii x, pii y, bool type) {
    if(x.fi == x.se) return 0;
    if(type) {
        int p = y.fi;
        int l = x.fi, r = x.se;
        if(r <= p) {
            return (long double)(r-l)*(p-(r+l)/2.0)/sums;
        } else if(l>=p){
            return (long double)(r-l)*((r+l)/2.0-p)/sums;
        } else {
            return (long double)((p-l)*(p-l)+(r-p)*(r-p))/2.0/sums;
        }
    }
    if(y.fi == y.se) return 0.0;
    vector<ll> _;
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
            if(l1>=x.fi && r1 <=x.se && l2>=y.fi && r2<=y.se) {
                ret += (long double)(r1-l1)*(r2-l2)/sums*ccal(l1,r1,l2,r2);
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
    bool fl1 = 1, fl2 = 1;
    for(int i = 1; i <= n; ++i) {
        int l, r;
        cin >> l >> r;
        fl1 &= (l==r);
        s.push_back({l, r});
    }
    for(int i = 1; i <= m; ++i) {
        int l, r;
        cin >> l >> r;
        fl2 &= (l==r);
        t.push_back({l, r});
    }
    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());
    if(fl1 && fl2) {
        for(int i = 0; i < m; ++i) tp[i] = t[i].se;
        for(int i = 1; i < m; ++i) tp[i] = tp[i - 1] + tp[i];
        int j = 0;
        long double ans = 0;
        for(int i = 0; i < n; ++i) {
            while(j < m && t[j].se <= s[i].se) ++j;
            if(j-1>=0) ans += (s[i].fi * j) - tp[j-1];
            if(j<m) ans += tp[m-1] - (j>0?tp[j-1]:0) - (s[i].fi * (m-j)); 
        }
        ans /= (double)n*m;
        cout << fixed << setprecision(10) << ans << endl;
        return 0;
    }
    if(fl1 | fl2) {
        if(fl2) {
            swap(n, m);
            swap(s, t);
            swap(fl1, fl2);
        }
    }
    for(int i = 0; i < m; ++i) {
        sp[i] = (long long)(t[i].se - t[i].fi);
        tp[i] = (long long)(t[i].se - t[i].fi) * (t[i].se + t[i].fi) / 2.0;
    }
    for(int i = 1; i < m; ++i) {
        sp[i] = sp[i - 1] + sp[i];
        tp[i] = tp[i - 1] + tp[i];
    }
    int j = 0;
    long double ans = 0;
    sums = 0;
    for(pii x : s) {
        sums += x.se - x.fi;
    } if(fl1) sums = n;
    assert(sums > 0);
    sums *= sp[m-1];
    for(pii x : s) {
        while(j < m && (t[j].se<=x.fi)) ++j;
        long double mid = (x.fi + x.se) / 2.00;
        if(j-1>=0) {
            ans += (fl1?1:(x.se - x.fi)) * (mid*sp[j-1]-tp[j-1]) / sums;
        }
        while(j < m && crs(t[j], x)) {
            ans += cal(t[j], x, fl1);
            ++j;
        }
        if(j<m) {
            ans += (fl1?1:(x.se - x.fi)) * 
                (tp[m-1]-(j>0?tp[j-1]:0)-mid*(sp[m-1]-(j>0?sp[j-1]:0))) / sums;
        }
        if(j>0) --j;
        if(j>0) --j;
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
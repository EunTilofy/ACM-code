#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const double EPS = 1e-12;
struct Point {
    double x, y;
};
double Dis(const Point &p1, const Point &p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
Point Get(const Point &c, double r, const Point &p) {
    Point u, v;
    if(Dis(p, c) < EPS) return p;
    // cerr << c.x << " " << c.y << " "<< r << "\n";
    // cerr << p.x << " "<< p.y <<"\n";
    // cerr << Dis(p, c) << "\n";
    u.x = c.x + r * fabs(c.x - p.x) / Dis(c, p);
    u.y = c.y + r * fabs(c.y - p.y) / Dis(c, p) * ((c.x - p.x) * (c.y - p.y) < 0 ? -1 : 1);
    v.x = c.x - r * fabs(c.x - p.x) / Dis(c, p);
    v.y = c.y - r * fabs(c.y - p.y) / Dis(c, p) * ((c.x - p.x) * (c.y - p.y) < 0 ? -1 : 1);
    // cerr << u.x << " " << u.y << " " << v.x << " " << v.y << "\n";
    return Dis(u, p) < Dis(v, p) ? u : v;
}

pair<double, double> get(double x, double y, double r2, double X) {
    double delta = r2 - (X - x) * (X - x);
    if(delta < 0) return {0, -1};
    delta = sqrt(delta);
    return {y - delta, y + delta};
}

pair<double, double> in(pair<double, double> x, pair<double, double> y) {
    if(x.first == 0 && x.second == -1) return {0, -1};
    if(y.first == 0 && y.second == -1) return {0, -1};
    if((x.first - y.first) > -EPS) swap(x, y);
    if(y.second <= x.second) return y;
    if((y.first - x.second) > -EPS) return {0, -1};
    return {y.first, x.second};
}

void solve() {
    ll xc, yc, R, x, y;
    cin >> xc >> yc >> R >> x >> y;
    x -= xc, y -= yc;
    if(!x && !y) {
        cout << "0\n" << xc << " " << yc << "\n";
        return ;
    }
    // (0, 0) r, x, y;
    int flg = 0;
    ll ans = 9e18;
    ll sx = 0, sy = 0;
    if(x * x + y * y <= R * R) {
        cout << "0\n" << x + xc << " " << y + yc << "\n";
        return ;
    }
    if(R * R <= 10000) {
        for(ll i = -R; i <= R; ++i) for(ll j = -R; j <= R; ++j) {
            if(i * i + j * j <= R * R) {
                if((i - x) * (i - x) + (j - y) * (j - y) <= ans) {
                    ans = (i - x) * (i - x) + (j - y) * (j - y);
                    sx = i, sy = j;
                }
            }
        }
        cout << 1 << "\n" << x + xc << " " << y + yc << " " << sx + xc << " " << sy + yc << "\n";
        return ;
    }
    double dis = sqrt(x * x + y * y) - R;
    // cerr << dis << "\n";
    // return ;
    double mx = (dis + 5) * (dis + 5);
    // cerr << mx << "\n";
    ll L, RR;
    int ff = 0;
    Point st; st.x = x, st.y = y;
    double jx = Get((Point){0, 0}, R, st).x;
    // cerr << jx << "\n";
    ll l = -2e9, r = ceil(jx);
    while(l <= r) {
        ll mid = (l + r) >> 1;
        auto[ll, rr] = in(get(0, 0, R * R, mid), get(x, y, mx, mid));
        if(ll == 0 && rr == -1) {
            l = mid + 1;
        }
        else {
            ff = 1;
            // cerr << mid << " " << ll << " "<< rr << "\n";
            L = mid, r = mid - 1;
        }
    }
    assert(ff);
    l = floor(jx), r = 2e9;
    ff = 1;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        auto[ll, rr] = in(get(0, 0, R * R, mid), get(x, y, mx, mid));
        if(ll == 0 && rr == -1) r = mid - 1;
        else {
            ff = 1;
            // cerr << "!" << mid << " "<< ll << " " << rr << "\n";
            RR = mid, l = mid + 1;
        }
    }
    assert(ff);
    // cerr << L << " " << RR << "\n";
    // return ;
    for(ll i = L; i <= RR; ++i) {
        auto[l, r] = in(get(0, 0, R * R, i), get(x, y, mx, i));
        for(ll j = ceil(l); j <= floor(r); ++j) {
            if(i * i + j * j > R * R) continue;
            if((x - i) * (x - i) + (y - j) * (y - j) <= ans) {
                flg = 1;
                ans = (x - i) * (x - i) + (y - j) * (y - j);
                sx = i, sy = j;
            }
        }
    }
    assert(flg);
    cout << 1 << "\n" << x + xc << " " << y + yc << " " << sx + xc << " " << sy + yc << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    for(int o = 1; o <= T; ++o) {
        solve();
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

namespace G {
    typedef long long ll;
    #define all(x) (x).begin(),(x).end()

    int sgn(const ll &x) {
        if(x < 0) return -1;
        return x > 0;
    }
    struct point {
        long long x, y;
        point() {}
        point(ll a, ll b) : x(a), y(b) {}
        point operator+(const point &o) const {return point(x+o.x, y+o.y);}
        point operator-(const point &o) const {return point(x-o.x, y-o.y);}
        ll operator*(const point &o) const {return x*o.y-y*o.x;}
        ll operator%(const point &o) const {return x*o.x+y*o.y;}
        ll len2() const {return x*x+y*y;}
    };

    const int DS[4] = {1, 2, 4, 3};
    int quad (const point &o) {
        return DS[(sgn(o.y)<0)*2+(sgn(o.x)<0)];
    }
    bool angle_cmp(const point &a, const point &b) {
        int c = quad(a), d = quad(b);
        if(c!=d) return c < d;
        return a*b > 0;
    }
    // int s = sgn(a*b);
    // return s > 0 || s == 0&&sgn(a.len2()-b.len2()) < 0;
}

void solve() {
    int n;
    cin >> n;

    vector<G::point> v(n);
    for(int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        v[i-1] = G::point(x, y);
    }
    sort(v.begin(), v.end(), G::angle_cmp);
    int ans = n;
    for(int i = 0; i < n; ++i) {
        v.push_back(v[i]);
        // cerr << v[i].x << " " << v[i].y << "\n";
    }
    for(int i = 0, j = 0; i < n; ++i) {
        j = max(i, j);
        // cerr << v[j+1].x << " " << v[j+1].y << " " << v[i].x << " " << v[i].y << " " << v[j+1]*v[i] << "\n";
        while(j + 1 != i + n && (v[j+1]*v[i] < 0 || (v[j+1]*v[i] == 0 && v[j+1]%v[i] > 0))) ++j;
        // cerr << i << " " << j << "\n";
        ans = min(ans, j-i+1);
        ans = min(ans, n-(j-i+1));
    } 
    // cerr << "======\n";
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while(T--) solve();

    return 0;
}
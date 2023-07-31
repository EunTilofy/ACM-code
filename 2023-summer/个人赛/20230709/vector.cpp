#include<bits/stdc++.h>
using namespace std;

struct vec {
    long long x, y;
    vec operator + (const vec & o) const {
        return (vec){x + o.x, y + o.y};
    }
    vec operator -(const vec & o) const {
        return (vec){x - o.x, y - o.y};
    }
    long long operator /(const vec & o) const {
        return 1ll * x * o.y - 1ll * y * o.x;
    }
    bool operator < (const vec & o) const {
        return atan2(y, x) < atan2(o.y, o.x);
    }
    long long operator * (const vec & o) const {
        return ((o.x >= 0)^(x>=0)) == 0 && ((o.y >= 0)^(y >= 0)) == 0;
    }
};
double Abs(vec x) {
    return sqrt((double)1.0*x.x*x.x+1.0*x.y*x.y);
}

void solve(bool ty) {
    int n;
    cin >> n;
    if(ty) cerr << n << endl;
    vector<vec> a(n), b;
    for(auto &[x, y] : a) {
        cin >> x >> y;
        if(ty) cerr << x << " " << y << endl;
    }
    sort(a.begin(), a.end());
    while(1);
    for(auto &o : a) {
        if(b.size() == 0) b.push_back(o);
        else if(b.back() / o == 0 && b.back() * o > 0) b.back() = b.back() + o;
        else b.push_back(o);
    } a = b;
    n = a.size();
    
    vec sum = a[0];
    int r = 0;
    for(int i = 1; i < n; ++i) {
        if(a[0] / a[i] > 0 || (a[0] / a[i] == 0 && a[0] * a[i] > 0) ) {
            r = max(r, i); sum = sum + a[i];
        }
        else sum = sum - a[i];
    }
    r = (r + 1) % n;
    double ans = Abs(sum);

    for(int i = 1; i < n; ++i) {
        sum = sum - a[i - 1] - a[i - 1];
        while(a[i] / a[r] > 0 || (a[i] / a[r] == 0 && a[i] * a[r] > 0) ) {
            sum = sum + a[r] + a[r];
            r = (r + 1) % n;
            if (i == r) break;
        }
        ans = max(ans, Abs(sum));
    }
    cout << fixed << setprecision(8) << ans << endl;
}

int main () {
    // freopen("test.in", "r", stdin);
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        solve(0);
    }
}

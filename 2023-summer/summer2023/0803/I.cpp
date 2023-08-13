#include<bits/stdc++.h>
using namespace std;
#define int long long
long long calS(vector<pair<int,int>> &a) {
    long long r = 0;
    for(int i = 0; i < a.size(); ++i) {
        int j = (i + 1) % a.size();
        r += (a[i].first * a[j].second) - (a[i].second * a[j].first);
    }
    return abs(r);
}
long long cals(pair<int,int> x, pair<int,int> y) {
    return abs(x.first-y.first) * abs(x.second-y.second);
}
typedef pair<int,int> pii;
int ccl(pii x, pii y) {
    int xx = x.first - y.first; xx = abs(xx);
    int yy = x.second - y.second; yy = abs(yy);
    int g = gcd(xx, yy);
    // cerr << xx << " " << yy << endl;
    if((xx/g)%2==0 || (yy/g)%2 == 0) return 0;
    // cerr << (g+1)/2 << endl;
    return (g+1)/2;
}
int calline(pair<int,int> x, pair<int,int> y) {
    pii xx, yy;
    xx.first = x.first * 2;
    xx.second = x.second * 2;
    yy.first = y.first * 2;
    yy.second = y.second * 2;
    return ccl(xx, yy);
}
long long cal(pair<int,int> x, pair<int,int> y) {
    // cerr << x.first << " " << x.second << " " << y.first << " " << y.second << endl;
    return (cals(x,y)+calline(x,y))/2;   
}

signed main() {
    freopen("semi-cool.in", "r", stdin);
    freopen("semi-cool.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for(auto &[x, y] : a) cin >> x >> y;
    long long S = calS(a);
    // cerr << S << endl;
    long long ans = 0;

    for(int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        ans += cal(a[i], a[j]);
        // cerr << "ans = " << ans << endl;
        // cerr << cals(a[i], a[j]) << endl;
        S -= cals(a[i], a[j]);
        // cerr << S << endl;
    }
    ans += S/2;
    // long long anss = (long long)(ans + 0.3);
    cout << ans << endl;
}
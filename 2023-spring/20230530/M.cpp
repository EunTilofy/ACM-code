#include<bits/stdc++.h>
using namespace std;
#define cin std::cin
#define cout std::cout
#define cerr std::cerr

typedef pair<int, int> pii;
#define ll long long

double ccal(int x, int y, int xx, int yy) {
    return 0.5 * (double)fabs(((ll)y*xx)-((ll)x*yy));
}

double cal(pii a, pii b, pii c) {
    return ccal(b.first-a.first, b.second-a.second, c.first-a.first, c.second-a.second);
}

void solve() {
    int n, k;
    cin >> n >> k;
    ++k;
    vector<pair<int, int>> a(n);
    for(auto &[x, y] : a) cin >> x >> y;

    double below = 0;

    for(int i = 1; i < k - 1; ++i) {
        below += cal(a[0], a[i], a[i + 1]);
    }
    // cerr << below << endl;

    int b = 0, c = k-1, top = k;

    for(int i = k + 1; i < n; ++i) {
        if(cal(a[b], a[c], a[top]) < cal(a[b], a[c], a[i])) top = i; 
    } 

    double ans = below + cal(a[b], a[c], a[top]);
    // cerr << "ans = " << ans << endl;
    
    for(b = 1, c = k; b < n; ++b, c=(c+1)%n) {
        below -= cal(a[b], a[(b+n-1)%n], a[(c+n-1)%n]);
        // cerr << below << endl;
        below += cal(a[b], a[c], a[(c+n-1)%n]);
        // cerr << b << " " << c << "xxx" << endl;
        // cerr << below << endl;
        if(top == c) top = (top + 1) % n;
        while((top + 1) % n != b && cal(a[b], a[c], a[(top + 1) % n]) > cal(a[b], a[c], a[top])) top = (top + 1) % n;

        // cerr << b << " " << c << " " << top << endl;
        ans = max(ans, below + cal(a[b], a[c], a[top]));
        // cerr << "ans = " << ans << endl;
    }

    cout << fixed << setprecision(12) << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }

}
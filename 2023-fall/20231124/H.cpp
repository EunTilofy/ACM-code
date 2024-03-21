#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node {
    int l, r;
};

bool cmp(node A, node B) {
    return A.l == B.l ? A.r < B.r : A.l < B.l;
}

ll C(ll x) {
    if(x <= 0) return 0ll;
    return x * (x - 1) / 2;
}
ll cal(int l, int r) {
    if(l > r) return 0ll;
    return C(r - l + 1);
}
ll len(int l, int r) {
    if(l > r) return 0ll;
    return r - l + 1;
}
int n; 
ll solve() {
    cin >> n;
    vector<node> a(n);
    for(auto &[x, y]: a) {
        cin >> x >> y;
    }
    sort(a.begin(), a.end(), cmp);
    int mxR = 0;
    for(auto [l, r] : a) mxR = max(mxR, r);
    if(n == 1) return 1;
    if(a[0].r == mxR) {
        auto [l, r] = a[0];
        int L = a[1].l, R = 0;
        for(int i = 1; i < n; ++i) R = max(R, a[i].r);
        return cal(l, r) - cal(l, L - 1) - cal(R + 1, r) - len(l, L - 1) * len(R + 1, r);
    }
    int id = 1;
    for(int i = 1; i < n; ++i) if(a[i].r >= a[id].r) id = i;
    if(a[0].r < a[id].l) {
        if(n == 2) return len(a[0].l, a[0].r) * len(a[id].l, a[id].r);
    }
    int l = a[0].l, r = a[id].r;
    int L = a[id].l, R = a[0].r;
    for(int i = 0; i < n; ++i) {
        if(i != 0) L = min(L, a[i].l);
        if(i != id) R = max(R, a[i].r);
    }
    if(n >= 4) return cal(l, r) - cal(l, L - 1) - cal(R + 1, r);
    return cal(l, r) - cal(l, L - 1) - cal(R + 1, r) - len(a[0].r + 1, L - 1) * len(R + 1, a[id].l - 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--){
        ll pos = solve();
        // if(pos == 150470606737462292) cout << pos << n << "\n";
        cout << pos << "\n";
    }
}
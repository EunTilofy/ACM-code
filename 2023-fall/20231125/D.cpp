#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node {
    int l, r;
};

bool cmp(node A, node B) {
    return A.r < B.r;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<node> a(n);
    for(auto &[l, r] : a) {
        cin >> l >> r;
    }
    sort(a.begin(), a.end(), cmp);
    ll ans = 0, now = 0;
    for(int i = 0; i < n; ++i) {
        int j = i;
        for(; j + 1 < n && a[j + 1].r == a[i].r; ++j) ;
        for(int k = i; k <= j; ++k) now = max(now, 1ll * a[k].l);
        ans += now * (j - i + 1);
        i = j;
    }
    cout << ans << "\n";
}
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
struct node {
    int l, r;
} a[N];

bool cmp(node A, node B) {
    return (A.l == B.l) ? A.r > B.r : A.l < B.l;
}

int ans[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= m; ++i) {
            cin >> a[i].l >> a[i].r;
        }
        sort(a + 1, a + 1 + m, cmp);
        set<int> s;
        for(int i = 1; i <= n; ++i) s.insert(i);
        int L = 1, R = 0;
        for(int o = 1; o <= m; ++o) {
            auto[l, r] = a[o];
            if(r <= R) continue;
            if(l > R) {
                for(int i = L; i <= R; ++i) s.insert(ans[i]);
                for(int i = R + 1; i < l; ++i) ans[i] = 1;
                for(int i = l; i <= r; ++i) {
                    int x = *s.begin();
                    ans[i] = x;
                    s.erase(x);
                }
            } else {
                for(int i = L; i < l; ++i) s.insert(ans[i]);
                for(int i = R + 1; i <= r; ++i) {
                    int x = *s.begin();
                    ans[i] = x;
                    s.erase(x);
                } 
            }
            L = l, R = r;
        }
        for(int i = R + 1; i <= n; ++i) ans[i] = 1;
        for(int i = 1; i <= n; ++i) cout << ans[i] << " ";
        cout << "\n";
    }
}
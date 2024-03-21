#include<bits/stdc++.h>
using namespace std;

int a[1005], id[1005];
vector<pair<int,int>> opt;
void add(int x, int y) {
    opt.push_back({x, y});
    // cerr << "Add : " << x << " " << y << "\n";
}
void sol(int l, int r, int L, int R) {
    // cerr << l << " " << r << " " << L << " "<< R << "\n";
    while(l <= r && a[id[l]] == L) ++l;
    if(l > r) return ;
    if(l == r) {
        for(int i = 1; i <= a[id[l]]-L; ++i) add(2, id[l]);
        return ;
    }
    if(L >= R) return;
    int mid = (L + R) >> 1;
    int m = l-1;
    while(m+1 <= r && a[id[m+1]] <= mid) ++m;
    // cerr << mid << " " << m << "\n";
    if(m + 1 <= r) {
        for(int i = m+1; i <= r; ++i) add(2, id[i]);
        for(int i = L+1; i <= mid; ++i) add(1, i);
        sol(m+1, r, mid+1, R);
    }
    if(l <= m) {
        sol(l, m, L, mid);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        id[i] = i;     
    }
    sort(id+1,id+n+1,[&](int x, int y)->bool{
        return a[x] < a[y];
    });

    sol(1, n, 0, n);
    if(opt.size() > 10000) assert(0);
    cout << opt.size() << "\n";
    for(auto [x, y] : opt) cout << x << " " << y << "\n";

    return 0;
}
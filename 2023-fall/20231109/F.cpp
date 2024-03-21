#include <bits/stdc++.h>
using namespace std;

const int MN = 1e6+5;
int a[MN];
int id[MN], rk[MN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        id[i] = i;
    }
    sort(id+1,id+n+1, [&](int x,int y)->bool{
        return a[x]==a[y]?x<y:a[x]<a[y];});
    for(int i = 1; i <= n; ++i) rk[id[i]]=i;

    int r = 1, tmp = 0, nw = 0;
    for(int l = 1; l <= n; ++l) {
        int _ = rk[l];
        while(nw < _) ++nw, r = max(r, id[nw]);
        while(l < r) {
            for(int k = l; k <= r; ++k) {
                _ = max(_, rk[k]);
            } l = r;
            while(nw < _) ++nw, r = max(r, id[nw]);
        }
        ++tmp;
    }
    cout << tmp << "\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n;
const int MN = 6e5 + 5;
int t[MN];
void C(int x, int y){for(; x <= n * 2 + 1; x += (x & -x)) t[x] += y;}
int G(int x) {int r = 0; for(; x; x -= (x & -x)) r += t[x]; return r;}
typedef pair<int, int> pii;
#define fi first
#define se second
pii o[MN];
int f[MN]; 
bool cmp(pii x, pii y){return x.se < y.se || (x.se == y.se && x.fi < y.fi);}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d%d", &o[i].fi, &o[i].se);
        C(o[i].fi, 1);
        C(o[i].se + 1, -1);
    }
    int a1 = 1;
    for(int i = 1; i <= n * 2; ++i) {
        a1 = max(a1, G(i));
    }
    int i, j = 0, a2; f[0] = 0;
    std::sort(o + 1, o + n + 1, cmp);
    for(i = 1, j = 0; i <= n * 2; ++i) {
        f[i] = f[i - 1];
        while(j + 1 <= n && o[j + 1].se == i) ++j, f[i] = max(f[i], f[o[j].fi - 1] + 1);
    }
    a2 = f[n * 2];
    int a3 = 0;
    std::sort(o + 1, o + n + 1);
    for(i = 1, j = 0; i <= n; ++i) {
        ++a3; int minr = o[i].se;
        while(j + 1 <= n && o[j + 1].fi <= minr) ++j, minr = min(minr, o[j].se);
        i = j;
    }
    printf("%d %d %d %d\n", a1, a2, a3, a1);
    return 0;
}
/*
3
1 3
2 4
5 6
*/
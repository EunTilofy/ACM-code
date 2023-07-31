#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x.size())
#define out(x) cerr << #x << " = " << x << " "
#define outln(x) cerr << #x << " = " << x << endl
#define outarr(x, l, r) {cerr << #x"[" << l << "~" << r << "] = "; for (int _ = l; _ <= r; ++_) cerr << x[_] << " "; cerr << endl;}

const int N = 3000005;
int n, m;
char s[N];
int a[N];

set<int> S;
void upd(int x, int w) {
    if (a[x] == 0) S.erase(S.find(x));
    a[x] += w;
    if (a[x] == 0) S.insert(x);
}

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; ++i) a[i + n] = s[i] - '0';
    for (int i = 1; i <= n; ++i) S.insert(i);
    for (int i = n + n + 1; i <= n + n + n; ++i) S.insert(i);
    for (int i = 1; i <= n; ++i) if (a[i + n] == 0) S.insert(i + n);
    for (int i = n + 1; i <= n + n; ++i) {
        if (a[i] == 2) {
            //int pl = i, pr = i;
            //while (pl >= n + 1 && a[pl]) --pl;
            //while (pr <= n + n && a[pr]) ++pr;
            int pl = *--S.lower_bound(i);
            int pr = *S.upper_bound(i);
            if (pl <= n) pl = n;
            if (pr >= n + n + 1) pr = n + n + 1;
            int dif = (pr - i) - (i - pl);
            upd(i, -1);
            upd(i + dif, -1);
            upd(pl, 1);
            upd(pr, 1);
            //out(i); out(pl); outln(pr);
            //outarr(a, n + 1, n + n);
        }
    }
    //outarr(a, n + 1, n + n);
    for (int i = n + 1; i <= n + n; ++i) printf("%d", a[i]);
    printf("\n");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x.size())
#define out(x) cerr << #x << " = " << x << " "
#define outln(x) cerr << #x << " = " << x << endl
#define outarr(x, l, r) {cerr << #x"[" << l << "~" << r << "] = "; for (int _ = l; _ <= r; ++_) cerr << x[_] << " "; cerr << endl;}

const int N = 1000005, M = 10000007;
int n, par[N], a[N], ch[N][2];
bool isprime[M];
int occ[M], minp[M], prime[680000], cnt = 0;
int lft[N], rgt[N];

void sieve(int n) {
    for (int i = 2; i <= n; ++i) isprime[i] = 1;
    for (int i = 2; i <= n; ++i) {
        if (isprime[i]) {
            prime[++cnt] = i;
            minp[i] = i;
        }
        for (int j = 1; j <= cnt && i * prime[j] <= n; ++j) {
            isprime[i * prime[j]] = 0;
            minp[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
    // outarr(minp, 1, 100);
    // outln(cnt);
}

int divi(int l, int r) {
    if (l > r) return -1;
    int blk = -1;
    for (int pl = l, pr = r; pl <= pr; ++pl, --pr) {
        if (lft[pl] <= l && rgt[pl] >= r) {
            blk = pl;
            break;
        }
        if (lft[pr] <= l && rgt[pr] >= r) {
            blk = pr;
            break;
        }
    }
    if (blk == -1) return -1;
    int A = divi(l, blk - 1);
    int B = divi(blk + 1, r);
    if (l <= blk - 1 && A == -1) return -1;
    if (blk + 1 <= r && B == -1) return -1;
    if (A != -1) par[A] = blk;
    if (B != -1) par[B] = blk;
    // out(blk); out(A); outln(B);
    return blk;
}

void pre_init() {
    sieve(10000000);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= 10000000; ++i) occ[i] = -1;
    for (int i = 0; i < n; ++i) {
        int u = a[i];
        int idx = -1;
        while (u > 1) {
            int t = minp[u];
            while (u % t == 0) u /= t;
            idx = max(idx, occ[t]);
            occ[t] = i;
        }
        lft[i] = idx + 1;
    }
    for (int i = 1; i <= 10000000; ++i) occ[i] = n;
    for (int i = n - 1; i >= 0; --i) {
        int u = a[i];
        int idx = n;
        while (u > 1) {
            int t = minp[u];
            while (u % t == 0) u /= t;
            idx = min(idx, occ[t]);
            occ[t] = i;
        }
        rgt[i] = idx - 1;
    }
    //outarr(lft, 0, n - 1);
    //outarr(rgt, 0, n - 1);
}

int main() {
    pre_init();
    for (int i = 0; i < n; ++i) par[i] = -1;
    int res = divi(0, n - 1);
    if (res == -1) {
        printf("impossible\n");
    } else {
        for (int i = 0; i < n; ++i) {
            printf("%d%c", par[i] + 1, " \n"[i == n - 1]);
        }
    }
    return 0;
} 

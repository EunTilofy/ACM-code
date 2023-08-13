#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x.size())
#define out(x) cerr << #x << " = " << x << " "
#define outln(x) cerr << #x << " = " << x << endl
#define outarr(x, l, r) {cerr << #x"[" << l << "~" << r << "] = "; for (int _ = l; _ <= r; ++_) cerr << x[_] << " "; cerr << endl;}

const int N = 4096;
const double eps = 1e-10;
int n, rn = 1;
int a[N];
int seq[N];
int main() {
    memset(seq, -1, sizeof seq);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    if (n == 2) {
        double ans = 1.0 * a[0] / (a[0] + a[1]);
        printf("%.12lf\n", ans);
        return 0;
    }
    while (rn < n) rn <<= 1;
    sort(a + 1, a + n);
    int k = rn - n, cur = 0;
    for (int i = 0; i < k; ++i) {
        seq[cur] = i;
        cur += 2;
    }
    for (int i = k; i < n; ++i) {
        seq[cur] = i;
        cur += 1;
    }
    int m = rn / 2;
    vector<vector<double>> dp(m, vector<double>(n, 0));
    for (int i = 0; i < m; ++i) {
        int A = seq[i + i], B = seq[i + i + 1];
        if (B == -1) {
            dp[i][A] = 1;
        } else {
            dp[i][A] = 1.0 * a[A] / (a[A] + a[B]);
            dp[i][B] = 1.0 * a[B] / (a[A] + a[B]);
        }
    }
    while (1) {
        m /= 2;
        vector<vector<double>> new_dp(m, vector<double>(n, 0));
        int blk = rn / (m + m);
        for (int i = 0; i < m; ++i) {
            int lft = blk * (i + i), rgt = blk * (i + i + 1);
            for (int p = lft; p < lft + blk; ++p) {
                for (int q = rgt; q < rgt + blk; ++q) {
                    int u = seq[p], v = seq[q];
                    if (u == -1 || v == -1) continue;
                    double pl = dp[i + i][u], pr = dp[i + i + 1][v];
                    if (pl < eps || pr < eps) continue;
                    new_dp[i][u] += pl * pr / (a[u] + a[v]) * a[u];
                    new_dp[i][v] += pl * pr / (a[u] + a[v]) * a[v];
                }
            }
        }
        dp = new_dp;
        if (m == 1) break;
    }
    double ans = dp[0][0];
    printf("%.12lf\n", ans);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x.size())
#define out(x) cerr << #x << " = " << x << " "
#define outln(x) cerr << #x << " = " << x << endl
#define outarr(x, l, r) {cerr << #x"[" << l << "~" << r << "] = "; for (int _ = l; _ <= r; ++_) cerr << x[_] << " "; cerr << endl;}

const int N = 505, M = 10005;
int n, m;
struct node {
    int d, s, p, id;
    bool operator < (const node &rhs) const {
        return p > rhs.p;
    }
}a[N];
int dp[N][M];
int pre[N][M];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].d, &a[i].s);
        if (a[i].d <= a[i].s) a[i].p = 0;
        else a[i].p = a[i].d - a[i].s;
        a[i].id = i + 1;
    }
    sort(a, a + n);
    memset(dp, -1, sizeof dp);
    dp[0][m] = 0;
    for (int i = 0; i < n; ++i) {
        int req = max(a[i].d, a[i].s), sto = a[i].s;
        for (int j = 0; j <= m; ++j) {
            dp[i + 1][j] = dp[i][j];
            pre[i + 1][j] = j;
            if (dp[i][j] >= 0 && j >= req) {
                int num = dp[i][j] + 1;
                if (num > dp[i + 1][j - sto]) {
                    dp[i + 1][j - sto] = num;
                    pre[i + 1][j - sto] = j;
                }
            }
        }
    }
    int cur = n, P = 0, ans = dp[n][0];
    for (int i = 0; i <= m; ++i) {
        if (dp[n][i] > ans) {
            ans = dp[n][i];
            P = i;
        }
    }
    vector<int> seq;
    while (cur >= 1) {
        int sto = a[cur - 1].s;
        int tmp = pre[cur][P];
        if (tmp != P) {
            assert(tmp == P + sto);
            seq.push_back(a[cur - 1].id);
        }
        cur -= 1;
        P = tmp;
    }
    printf("%d\n", ans);
    if (!seq.empty()) {
        // sort(seq.begin(), seq.end());
        reverse(seq.begin(), seq.end());
        bool tag = 1;
        for (int u : seq) {
            if (tag) tag = 0;
            else printf(" ");
            printf("%d", u);
        }
        printf("\n");
    }
    return 0;
} 

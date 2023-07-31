#include <bits/stdc++.h>
using namespace std;
const int V = 100;
#define int ll
#define ll long long
const int N = 105;
int mo = -1;

int qpow(int y, int z) {
  y %= mo;
  int ans = 1;
  for (int i = z; i; i >>= 1, y = y * y % mo)
    if (i & 1)
      ans = ans * y % mo;
  return ans;
}

int n, K, l, r, tot, w[5], m, sqr, f[N][N * 2][N * 2], g[N][N * 2][N * 2], h[N][N * 2][N * 2], sum, p[5], ans, s[N];
int a[5] = {V, V, V, V - 1, V + 1};
int b[5] = {V, V + 1, V - 1, V, V};

inline void add(int &x, int y) {
  x += y;
  x >= mo ? x -= mo : x;
}

signed main() {
  /* freopen("cal.in","r",stdin); */
  cin >> n >> mo;
  for (int i = 1; i <= 4; i++) {
    w[i] = 1;
    sum += w[i];
  }
  for (int i = 1; i <= 4; i++) {
    p[i] = w[i] * qpow(sum, mo - 2) % mo;
  }
  g[0][V][V] = f[0][V][V] = 1;
  for (int d = 0; d <= n; d++)
    for (int i = -d; i <= d; i++) {
      for (int j = -d; j <= d; j++) {
        for (int k = 1; k <= 4; k++)
          add(g[d + 1][i + a[k]][j + b[k]], g[d][i + V][j + V] * p[k] % mo);
      }
    }
  for (int d = 0; d <= n; d++) {
    for (int i = -d; i <= d; i++) {
      for (int j = -d; j <= d; j++) {
        int *cur = &f[d][i + V][j + V];
        *cur = g[d][i + V][j + V];
        for (int pre = 0; pre < d; pre++)
          add(*cur, mo - f[pre][i + V][j + V] * g[d - pre][0 + V][0 + V] % mo);
        s[d] += *cur;
        s[d] %= mo;
        if (!*cur)
          continue;
      }
    }
    ans += s[d] % mo;
    ans %= mo;
  }
  cout<<ans*qpow(sum,n)%mo<<endl;
}

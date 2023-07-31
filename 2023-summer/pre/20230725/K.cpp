#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
vector<pair<int, int>> e[N];
int ban[N], mx[N], sz[N];
int root;

void groot(int x, int fa, int sizz) {
  mx[x] = 0;
  sz[x] = 1;
  for (auto [v, w] : e[x]) {
    if (v == fa || ban[v])
      continue;
    groot(v, x, sizz);
    sz[x] += sz[v];
    mx[x] = max(mx[x], sz[v]);
  }
  mx[x] = max(mx[x], sizz - mx[x]);
  if (mx[x] < mx[root])
    root = x;
}

void put(int x, int fa) {
  sz[x] = 1;
  for (auto [v, w] : e[x]) {
    if (v == fa || ban[v])
      continue;
    put(v, x);
    sz[x] += sz[v];
  }
}

int cnt, id[N];
ll a[N], dep[N];

pair<ll, ll> s[N], t[N];

void dfs(int x, int fa) {
  s[++cnt] = {a[x], dep[x]};
  id[cnt] = x;
  for (auto [v, w] : e[x]) {
    if (v == fa || ban[v])
      continue;
    dep[v] = dep[x] + w;
    dfs(v, x);
  }
}

ll ans[N];

void cal(int x) {
  cnt = 0;
  dep[x] = 0;
  dfs(x, 0);
  sort(s + 1, s + cnt + 1);
  int top = 1;
  t[top] = s[1];
  for (int i = 2; i <= cnt; i++) {
    while (top > 1 && (s[i].second - t[top].second) * (s[i].first - t[top - 1].first) <=
                          (s[i].second - t[top - 1].second) * (s[i].first - t[top].first))
      top--;
    t[++top] = s[i];
  }
  for (int i = 1; i <= cnt; i++) {
    int cur=id[i];
    int l = 1, r = top;
    while (r - l > 1) {
      int m1 = (l + r) / 2;
      int m2 = min(m1 + 1, r - 1);
      if (t[m1].second + dep[cur] + t[m1].first * a[cur] > t[m2].second + dep[cur] + t[m2].first * a[cur])
        l = m1;
      else
        r = m2;
    }
    ans[cur] = min(ans[cur], t[l].second + dep[id[i]] + t[l].first * a[cur]);
    ans[cur] = min(ans[cur], t[r].second + dep[id[i]] + t[r].first * a[cur]);
  }
}

void solve(int x, int sizz) {
  root = 0;
  mx[0] = sizz + 1;
  groot(x, x, sizz);
  ban[root] = 1;
  put(root, root);
  cal(root);
  for (auto [v, w] : e[root]) {
    if (ban[v])
      continue;
    solve(v, sz[v]);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%lld", &a[i]);
  for (int i = 1; i < n; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    e[x].push_back({y, z});
    e[y].push_back({x, z});
  }
  for (int i = 1; i <= n; i++)
    ans[i] = a[i] * a[i];
  solve(1, n);
  ll res = 0;
  for (int i = 1; i <= n; i++)
    res += ans[i];
  cout << res << endl;
  return 0;
}

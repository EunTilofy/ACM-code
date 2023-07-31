#include <bits/stdc++.h>
using namespace std;
const int N = 205, M = 3e5 + 5, V = 1e5;
int a[N];
int dis[M][2];
// int vis[M][2];

int main() {
  int n;
  scanf("%d", &n);
  priority_queue<tuple<int, int, int>> q;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  q.push({0, 0, 0});
  memset(dis, 0x3f, sizeof(dis));
  dis[V][0] = 0;
//   vis[V][0] = 1;
  while (!q.empty()) {
    auto [d, x, ty] = q.top();
    q.pop();
    // if (!vis[x + V][ty]) {
      /* if(x<=10&&x>=0)cout<<"cur "<<x<<" "<<(ty)<<" "<<d<<endl; */
    //   vis[x + V][ty] = 1;

      for (int i = 1; i <= n; i++) {
        int v = 0;
        if (ty == 0) {
          v = x + a[i];
        }
        else {
          v = x - a[i];
        }
        if (v + V >= 0 && v + V < M && dis[v + V][ty ^ 1] > -d + 1) {
          dis[v + V][ty ^ 1] = -d + 1;
          /* if(v<=10&&v>=0)cout<<"upd "<<v<<" "<<(ty^1)<<" "<<-d+1<<endl; */
          q.push({-dis[v + V][ty ^ 1], v, ty ^ 1});
        }
      }
    // }
  }
  /* for (int i = 0; i <= 10; i++) { */
  /*   cout << dis[i + V][0] << " " << dis[i + V][1] << endl; */
  /* } */
  int Q;
  scanf("%d\n", &Q);
  while (Q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    int ans = 0x3f3f3f3f;
    if ((y + x) % 2 == 0)
      ans = min(ans, dis[(y + x) / 2 + V][1]);
    if ((y - x) % 2 == 0 && (y - x) / 2 + V >= 0)
      ans = min(ans, dis[(y - x) / 2 + V][0]);
    if (ans >= 0x3f3f3f3f) {
      puts("-1");
    }
    else
      printf("%d\n", ans);
  }
}

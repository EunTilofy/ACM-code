#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 10, M = 1e4 + 10;
int w[N], v[N], mk[N];
int pr[N][M];
ll f[N][M];

void get(int x, int y) {
    if(!x) return ;
    int ny = pr[x][y];
    if(ny != y) mk[x] = 1;
    get(x - 1, ny);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, W, k;
    cin >> n >> W >> k;
    for(int i = 1; i <= n; ++i) cin >> w[i] >> v[i];
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= W; ++j) {
            f[i][j] = f[i - 1][j], pr[i][j] = j;
            if(j >= w[i] && f[i - 1][j - w[i]] + v[i] > f[i][j]) {
                f[i][j] = f[i - 1][j - w[i]] + v[i];
                pr[i][j] = j - w[i];
            }
        }
    }
    int id = 0;
    ll ans = 0;
    for(int i = 0; i <= W; ++i) if(ans < f[n][i]) ans = f[n][i], id = i;
    get(n, id);
    // cout << ans << "\n";
    vector<int> q;
    for(int i = 1; i <= n; ++i) if(!mk[i]) q.push_back(v[i]);
    sort(q.begin(), q.end(), [&](int x, int y) {return x > y;});
    int sz = q.size();
    for(int i = 0; i < min(k, sz); ++i) ans += q[i];
    cout << ans << "\n";
}
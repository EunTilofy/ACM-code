#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3 + 10, M = 1e4 + 10;
int w[N], v[N];
ll f[N][M];
ll g[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, W, k;
    cin >> n >> W >> k;
    vector<pair<int,int>> pp(n);
    for(int i = 1; i <= n; ++i) cin >> pp[i-1].first >> pp[i-1].second;
    sort(pp.begin(), pp.end());
    for(int i = 1; i <= n; ++i) w[i] = pp[i-1].first, v[i] = pp[i-1].second;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = n; i; --i) {
        if(q.size() < k) {
            q.push(v[i]);
            g[i] = g[i+1] + v[i];
        } else {
            if(q.size() && q.top() < v[i]) {
                g[i] = g[i+1] + v[i] - q.top();
                q.pop();
                q.push(v[i]);
            } else g[i] = g[i+1];
        }
    } 
    ll ans = g[1];
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= W; ++j) {
            f[i][j] = f[i - 1][j];
            if(j >= w[i] && f[i - 1][j - w[i]] + v[i] > f[i][j]) {
                f[i][j] = f[i - 1][j - w[i]] + v[i];
            }
        }
        ans = max(ans, f[i][W] + g[i+1]);
    }
    cout << ans << "\n";
}
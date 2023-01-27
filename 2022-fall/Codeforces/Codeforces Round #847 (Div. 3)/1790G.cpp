#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define pb push_back
const int MN = 3e5 + 5;
int a[MN], B[MN], c[MN], dis[MN], mov[MN];
bool tok[MN], bon[MN], vis[MN], ca[MN];
vector<int> G[MN];

void solve(){
	int n, m;
    cin >> n >> m;
    int p, b;
    cin >> p >> b;
    for(int i = 1; i <= n; ++i) {
        dis[i] = 0;
        ca[i] = mov[i] = vis[i] = tok[i] = bon[i] = 0, G[i].clear();
    }
    for(int i = 1; i <= p; ++i) cin >> a[i], tok[a[i]] = 1;
    for(int i = 1; i <= b; ++i) cin >> B[i], bon[B[i]] = 1;
    for(int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].pb(y), G[y].pb(x);
    }
    if(tok[1]) {
        cout << "YES" << endl;
        return;
    }
    queue<int> q;
    q.push(1); vis[1] = 1; dis[1] = 0;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(auto y : G[x]) {
            if(x == 1 && tok[y]) {
                cout << "YES" << endl;
                return;
            }
            if(bon[y] && !vis[y]) {
                vis[y] = 1;
                dis[y] = dis[x] + 1;
                q.push(y);
            }
        }
    }
    long long sm = 0ll;
    for(int i = 1; i <= n; ++i) for(auto y : G[i]) if(bon[y]) ca[i] = 1;
    for(int i = 1; i <= n; ++i) if(tok[i]) {
        mov[i] = 0;
        for(auto y : G[i]) if(bon[y]) {
            mov[i] = max(mov[i], 1);
            if(ca[y]) mov[i] = 1000000000;
        }
        sm += mov[i];
    }
    for(int i = 1; i <= n; ++i) if(tok[i]) {
        long long ddis = -1;
        for(auto y : G[i]) if(vis[y]) {
            if(ddis == -1) ddis = dis[y] + 1;
            else ddis = min(ddis, dis[y] + 1ll);
        }
        if(ddis == -1) continue;
        if(sm - mov[i] + 1ll >= ddis) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}
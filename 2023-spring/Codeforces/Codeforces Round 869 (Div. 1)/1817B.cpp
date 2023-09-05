#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 3e5 + 5;
int a[MN], b[MN];
vector<int> G[MN];
int fd;
bool ok;
vector<pii> tmp;
void dfs(int x, int from) {
    if(b[x] == 1) {
        if(x == fd) {
            ok = 1;
            return;
        }
        return;
    }
    if(ok) return;
    b[x] = 1;
    for(auto y : G[x]) if(y != from) {
        tmp.push_back({x, y});
        dfs(y, x);
        if(ok) return;
        tmp.pop_back();
        if(ok) return;
    }
}
void solve(){
	int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) G[i].clear();
    vector<int> deg(n+1);
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
        ++deg[x];
        ++deg[y];
    } 
    for(int i = 1; i <= n; ++i) if(deg[i] >= 4) {
        for(int j = 1; j <= n; ++j) b[j] = 0;
        fd = i; ok = 0; tmp.clear(); dfs(i, 0);
        if(ok) {
            cout << "YES" << endl;
            int x1 = tmp[0].second;
            int x2 = tmp.back().first;
            vector<int> tt;
            for(auto y : G[i]) if(y != x1 && y != x2) {
                tt.push_back(y);
            }
            vector<pii> ans;
            ans.push_back({i, tt[0]});
            ans.push_back({i, tt[1]});
            ans.push_back({i, x1});
            ans.push_back({i, x2});
            for(int i = 1; i < tmp.size()-1; ++i) {
                ans.push_back(tmp[i]);
                if(tmp[i].second == tt[0] || tmp[i].second == tt[1])
                    break;
            }
            cout << ans.size() << endl;
            for(auto x : ans) cout << x.first << " " << x.second << endl;
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
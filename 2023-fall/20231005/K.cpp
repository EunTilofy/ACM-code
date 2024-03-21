#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int d[N], vs[N], yz[N];
vector<int> G[N];
map<int, int> mp[N];

int flg = 0;
void dfs(int x, int fa) {
    vs[x] = 1;
    for(int y : G[x]) if(y != fa) {
        if(vs[y]) {flg = 1; continue;}
        dfs(y, x);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    
    for(int i = 1, x, y; i <= n; ++i) {
        cin >> x >> y;
        if(x == y) y = x + k;
        if(x > y) swap(x, y);
        if(mp[x].count(y)) continue;
        mp[x][y] = 1;
        G[x].push_back(y);
        G[y].push_back(x);
        d[x]++, d[y]++;
    }
    vector<int> lf;
    for(int i = 1; i <= k * 2; ++i) if(d[i] == 1) {
        lf.push_back(i);
        yz[i] = 1;
    }
    for(int i :lf) {
        for(int y : G[i]) {
            d[y]--;
        }
    }
    for(int i : lf) d[i] = 0;
    for(int i = 1; i <= k * 2; ++i) if(d[i] > 2) {
        cout << "impossible\n";
        return 0;
    }
    int ans1 = 0, ans2 = 0;
    for(int i = 1; i <= k * 2; ++i) if(!vs[i] && G[i].size()) {
        flg = 0, dfs(i, 0);
        // if(flg) cerr << i << "\n";
        // cerr << i << " " << flg << "\n";
        if(flg) ans1++;
        else ans2++;
    }
    if(ans1 > 1 || (ans1 && ans2)) cout << "impossible\n";
    else cout << "possible\n";
    return 0;
}
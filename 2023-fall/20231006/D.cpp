#include<bits/stdc++.h>
using namespace std;
int n;char c;
string s[105];
int id[105][105];
pair<int, int> a[105*105];
bool vis[105*105];
vector<pair<pair<int,int>, pair<int,int>>> opt;
int cnt = 0;
bool check(pair<int,int> x, pair<int,int> y, char c) {
    if(c == 'B') {
        return abs(x.first-y.first) == abs(x.second-y.second);
    } if(c == 'K') {
        return abs(x.first-y.first)<=1 && abs(x.second-y.second)<=1;
    } if(c == 'Q') {
        return abs(x.first-y.first) == abs(x.second-y.second) ||
                (x.first == y.first) || (x.second == y.second);
    } if(c == 'R') {
        return (x.first == y.first) || (x.second == y.second);
    } if(c == 'N') {
        int xx = abs(x.first - y.first), yy = abs(x.second - y.second);
        return (xx==1&&yy==2)||(xx==2&&yy==1);
    }
    return 0;
}
void dfs(int x) {
    vis[x] = 1;
    for(int i = 1; i <= cnt; ++i) if(!vis[i]) {
        if(check(a[x], a[i], c)) {
            opt.push_back({a[i], a[x]});
            dfs(i);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> c;
    for(int i = 0; i < n; ++i) {
        cin >> s[i];
        for(int j = 0; j < n; ++j) {
            if(s[i][j] != '.') {
                id[i][j] = ++cnt;
                a[cnt] = {i,j};
            }
        }
    }
    dfs(1);
    for(int i = 1; i <= cnt; ++i) if(!vis[i]) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    reverse(opt.begin(), opt.end());
    for(auto [x, y] : opt) {
        cout << x.first+1 << " " << x.second+1 << " " << y.first+1 << " " << y.second+1 << "\n";
    }
    return 0;
}
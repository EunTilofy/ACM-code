#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MP = 2000;
bool mk[MP];
int pr[MP], tot;
void init() {
    for(int i = 2; i < MP; ++i) {
        if(!mk[i]) {
            pr[++tot] = i;
        }
        for(int j = 1; j <= tot && pr[j] * i < MP; ++j) {
            mk[i * pr[j]] = 1;
            if(i % pr[j] == 0) break; 
        }
    }
}
const long long INF = 1e18;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long num[2] = {0, 1};
    priority_queue<pair<long long, long long>> q;
    set<long long> vis;
    init();
    q.push({-1, 1});
    vis.insert(1);
    // vector<long long> ans;
    int now = 0;

    long long UP;
    cin >> UP;

    while(!q.empty()) {
        long long x = q.top().first;
        long long _num = q.top().second;
        q.pop();
        x = -x;
        if(_num < num[0]) continue;
        ++now;
        if(now == UP) {
            cout << x;
            return 0;
        }
        // cerr << x << "\n";
        // if(ans.size() == UP) break;
        for(int i = 1; i <= tot; ++i) {
            if(x <= INF/pr[i] && !vis.count(1ll * x * pr[i])) {
                long long xx = x;
                int step = 0;
                while(xx % pr[i] == 0) xx/=pr[i], ++step;
                long long __num = _num / (step + 1ll) * 1ll * (step + 2ll);
                vis.insert(1ll * x * pr[i]);
                q.push({-(1ll * x * pr[i]), __num});
            }
        }
        num[0] = max(_num, num[0]);
        if(num[1] < num[0]) swap(num[0], num[1]);
    }
    // cerr << now << endl;
    cout << -1;
    return 0;
}
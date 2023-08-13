#include<bits/stdc++.h>
using namespace std;

const int MN = 5e5+5;
int n;
int s[MN];
vector<int> G[MN]; 
#define Mod 998244353

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n; 
    for(int i = 1; i <= n; ++i) {
        cin >> s[i];
        for(int j = 1; j <= s[i]; ++j) {
            int x;
            cin >> x;
            G[i].push_back(-x);
        }
        sort(G[i].begin(), G[i].end());
    }
    
    vector<int> ss;
    for(int i = 1; i <= n; ++i) for(auto &x : G[i]) ss.push_back(x);
    sort(ss.begin(), ss.end());
    map<int,int> mp;
    for(int i = 0; i < ss.size(); ++i) mp[ss[i]] = i+1;
    
    for(int i = 1; i <= n; ++i) for(auto &x : G[i]) {
        int y = mp[x]; mp[x]--;
        x = y;
    }
    // for(int i = 1; i <= n; ++i, cout << endl) for(auto &x : G[i]) {
    //     // int y = mp[x]; mp[x]--;
    //     // x = y;
    //     cout << x << " ";
    // }
    // return 0;
    /*
3 4 6 10 11 
5 7 9 
2 
1 8 12
    */
    set<pair<int,int>> now;
    for(int i = 1; i <= n; ++i) {
        int k = G[i].back();
        int l = -1;
        if(now.size() == 0 || now.begin()->first >= k) {
            l = -1000;
        }
        else {
        //     // l = -1;
            l = (--now.lower_bound({k, 0}))->first;
        }
        // cout << l << endl;
        int L = 0, R = G[i].size() -1, fd = -1;
        while(L <= R) {
            int mid = (L + R)>>1;
            if(G[i][mid] > l) fd = mid, R = mid - 1;
            else L = mid + 1;
        }
        // cerr << fd << endl;
        now.insert({G[i][fd], i});
    }

    vector<pair<int,int>> last;
    last.push_back({0, 1});
    for(auto &[val, id] : now) {
        // id
        // cerr << id << endl;
        vector<pair<int,int>> _;
        for(auto &x : G[id]) {
            int L = 0, R = last.size()-1, fd = -1;
            // cout << "size = " << last.size() << endl; 
            while(L <= R) {
                int mid = (L + R) >> 1;
                if(last[mid].first <= x) fd = mid, L = mid + 1;
                else R = mid - 1;
            }
            // cout << fd << endl;
            if(fd != -1) {
               int xx = 0;
               if(_.size()) xx = _.back().second;
            //    cerr << xx << endl;
                _.push_back({x, (xx + last[fd].second) % Mod});
            }
            // cerr << "!" << endl;;
        }
        last = _;
        // for(auto [xx, yy] : last) cout << xx << " " << yy << endl;cout << endl;
    }
    if(last.size()) cout << last.back().second;
    else cout << 0;
    return 0;
}
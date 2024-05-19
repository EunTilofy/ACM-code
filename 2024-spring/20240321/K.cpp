#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), ans(n);
    for(int &x : a) cin >> x;
    set<pair<int, int>> s;
    for(int i = 1; i <= k; ++i) s.insert({0, i});
    for(int i = 0; i < n; ++i) {
        if(a[i] == 1) {
            auto[val, id] = *s.begin();
            ans[i] = id;
            s.erase({val, id}), s.insert({val + 1, id});
        } else {
            auto [val, id] = *s.rbegin();
            ans[i] = id;
            s.erase({val, id}), s.insert({max(0, val - 1), id});
        }
    }
    for(int x : ans) cout << x << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
}
/*
5
3 2
1 -1 1
4 2
-1 1 1 -1
7 3
1 1 1 1 1 1 1
10 3
1 1 1 1 -1 -1 1 1 1 1
12 4
1 1 1 1 -1 -1 -1 -1 1 1 1 1


1 1 2 
1 1 2 2 
1 1 1 2 2 2 3 
1 1 1 2 1 2 2 2 3 3 
1 1 2 2 1 2 3 4 3 3 4 4
*/
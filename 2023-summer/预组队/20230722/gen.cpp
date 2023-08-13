#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    set<pair<int,pair<int,int>>> S;
    S.insert({0,{0,0}});

    for(int i = -2; i <= 2; ++i) for(int j = -2; j <= 2; ++j) {
        S.insert({i, {j, 2}});
        S.insert({i, {j, -2}});
        S.insert({2, {i, j}});
        S.insert({-2, {i, j}});
        S.insert({i, {2, j}});
        S.insert({i, {-2, j}});
    }
    cout << S.size() << "\n";
    for(auto o : S) cout << o.first << " " << o.second.first << " " << o.second.second << "\n";
    return 0;
}
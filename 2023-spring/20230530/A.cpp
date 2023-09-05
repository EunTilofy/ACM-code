#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while(T--) {
        int n, k;
        std::cin>>n>>k;
        std::vector<pair<int,int>> a;
        for(int i = 0; i < n; ++i) {
            int x, y;
            std::cin>>x>>y;
            a.push_back({x, y});
        }
        sort(a.begin(), a.end());
        long long ret = 0, now = 0, nowt = 0;
        bool fl = 1;
        for(auto &[x, y] : a) {
            ret += y;
            now += 1ll * (x - nowt) * k;
            nowt = x;
            fl &= (ret <= now);
        }
        if(fl) std::cout << "Yes" << endl;
        else std::cout << "No" << endl;
    }
    return 0;
}
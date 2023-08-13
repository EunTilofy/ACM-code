#include<bits/stdc++.h>
using namespace std;
int ans=0;
bool vs[105];
vector<int> a;
void dfs(int last, int now, int UP, int gc, int lc, int n) {
    if(now > UP) {
        if(gc + lc == n) {
            ++ans;
            // for(auto &x : a) cout << x << " " ;
            // cout << "\n";
            // cout << gc << " " << lc << "\n";
        }
        return;
    }
    for(int i =last + 1; i <= n; ++i) {
        int gcc = (gc == 0) ? i : gcd(gc, i);
        int lcc = lc * i / gcd(i, lc);
        a.push_back(i);
        dfs(i, now+1, UP, gcc, lcc, n);
        a.pop_back();
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    dfs(0, 1, k, 0, 1, n);
    cout << ans;
}
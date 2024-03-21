#include<bits/stdc++.h>
using namespace std;

int ans, n, deg[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ans = n;
    bool fl = 1;
    for(int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        deg[x]++;
        deg[y]++;
        if(deg[x] == 3) --ans;
        if(deg[y] == 3) --ans; 
        if(max(deg[x], deg[y]) > 3) fl = 0;
    }
    cout << fl * ans << "\n";
    return 0;
}
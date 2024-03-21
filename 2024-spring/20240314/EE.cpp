#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int a[N],cnt[N][N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        memset(cnt, 0, sizeof cnt);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) cnt[j][i] = cnt[j][i-1];
            cnt[a[i]][i] ++;
        }
        int ans =0;
        for(int l = 1; l <= n; ++l) 
            for(int r = l; r <= n; ++r) 
                for(int i = 1; i <= n; ++i)
                    for(int j = 1; j <= n; ++j) {
                        ans = max(ans, (cnt[i][r] - cnt[i][l-1]) | (cnt[j][r] - cnt[j][l-1]));
                    }
        cout << ans << "\n";
    }
}
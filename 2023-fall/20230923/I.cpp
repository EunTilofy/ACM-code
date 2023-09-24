#include<bits/stdc++.h>
using namespace std;
int p[500005];
int pre[500005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;cin >> T;
    while(T--){
        int n; cin >> n;
        for(int i=0;i<n;i++) cin >> pre[i];
        for(int i=0;i<n;i++){
            cin >> p[i];
        }
        long double ans = n;
        // for(int i=1;i<=n;i++){
            // f[i]=max()
        // }
        for(int i = 0; i < n-1; ++i) {
            // cerr << i << " " << pre[i] << " " << p[i] << endl;
            long double res = i+1+(long double)(i-pre[i]+1)*(long double)(100000-p[i])/(long double)p[i];
            // cerr << T << " " << fixed << setprecision(12) <<  res << "\n";
            ans = min(ans, res);
            // cerr << T << " " << fixed << setprecision(12) <<  ans << "\n";
        } 
        cout << fixed << setprecision(12) << ans << "\n";
    }
}
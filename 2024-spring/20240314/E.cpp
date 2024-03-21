#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],cnt[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin>>T;
    while(T--){
        int n; cin >> n;
        for(int i=1;i<=n;i++){
            cnt[i]=0;
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)cnt[a[i]]++;

        // cout << cnt[1] << " " << cnt[2] << " " << cnt[3] << "\n";

        sort(cnt+1,cnt+1+n);

        if(cnt[n-1]==0)cout<<cnt[n]<<'\n';
        else {
            long long ans = cnt[n]|cnt[n-1];
            for(int i = 1; i < n; ++i) {
                if(cnt[i] == 0) continue;
                int pos = (1ll<<(31 - __builtin_clz(cnt[i]&cnt[n])));
                ans = max(ans, 
                    (long long)cnt[n]|(cnt[i] - pos) | (pos - 1));
                // cerr << cnt[i] << " " << pos - 1 << "\n";
                ans = max(ans, (long long)cnt[n] | cnt[i]);
            }
            cout << ans << "\n";
        }
    }
}
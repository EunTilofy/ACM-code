#include<bits/stdc++.h>
using namespace std;
int dp[5005],nxt[5005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, w;
    cin >> n >> w;
    vector<pair<int,string>> a(n);
    for(auto &x : a) {
        cin >> x.second;
        x.first = x.second.size();
    }
    int l = 1, r = n-1, ans = n;
    while(l <= r) {
        int mid = (l+r)/2;
        int all = 0;
        dp[n]=-1;
        for(int i = n-1; ~i; --i) {
            dp[i]=dp[i+1]+1+a[i].first;
            nxt[i]=i+1;
            int mx=a[i].first;
            for(int j=i+1;j<n&&j<=i+mid-1;++j){
                mx=max(mx,a[j].first);
                if(dp[j+1]+1+mx<=dp[i]){
                    nxt[i]=j+1;
                    dp[i]=dp[j+1]+1+mx;
                }
            }
            // cout << mid << " " << "dp" << i << dp[i] << endl;
            if(dp[i]>w){dp[0]=w+1;break;}
        }
        all = dp[0];
        if(all <= w) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    for(int i = n-1; ~i; --i) {
        dp[i]=dp[i+1]+1+a[i].first;
        nxt[i]=i+1;
        int mx=a[i].first;
        for(int j=i+1;j<n&&j<=i+ans-1;++j){
        mx=max(mx,a[j].first);
            if(dp[j+1]+1+mx<=dp[i]){
                nxt[i]=j+1;
                dp[i]=dp[j+1]+1+mx;
            }
        }
    }
    vector<int> rows;
    for(int i = 0; i < n; i = nxt[i]) {
        int mx = 0;
        for(int j = i; j < nxt[i]; ++j) {
            mx = max(mx, a[j].first);
        }
        rows.push_back(mx);
    }
    cout << ans << " " << rows.size() << endl;
    for(auto x : rows) cout << x << " "; cout << endl;
    for(int i = 0; i < ans; ++i) {
        for(int j = 0, r = 0; j+i < n; j = nxt[j], ++r) {
            int num = 0;
            if(j+i<nxt[j]) cout << a[j+i].second, num+=a[j+i].first;
            for(int k = 1; k <= rows[r]-num+1;++k) cout << " ";
        }
        cout << endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define int long long
#define all(x) x.begin(),x.end()

#define MN 1000005
int cnt;
int b[MN], tmp[MN];
void init(){
    for(int i = 0; i * i <= 262144; ++i) b[++cnt] = i * i;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<int> c(n + 1);
    for(int i = 1 ;i <= n; ++i) cin >> a[i], c[i] = c[i - 1] ^ a[i];
    long long ans = 1ll * n * (n + 1) / 2ll;
    for(int i = n; ~i; --i) {
        for(int j = 1; j <= cnt; ++j) {
            ans -= tmp[b[j] ^ c[i]];
        }
        tmp[c[i]] ++;
    }
    for(int i = 0; i <= n; ++i) tmp[c[i]] = 0;
    cout << ans << endl;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
    init();int T;cin>>T;
	while(T--) solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()
#define int long long

#define MN 1000005
int mu[MN], pr[MN], cnt;
bool mk[MN];
void init() {
    mu[1] = 1;
    for(int i = 2; i < MN; ++i) {
        if(!mk[i]) {pr[++cnt] = i; mu[i] = -1;}
        for(int j = 1; 1ll * pr[j] * i < MN; ++j) {
            mk[1ll * pr[j] * i] = 1;
            mu[1ll * pr[j] * i] = -mu[i];
            if(i % pr[j] == 0) {
                mu[pr[j] * i] = 0;
                break;
            }
        }
    }
}

int num[MN][2], ret;
// long long dfs(int n, long long left) {
//     if(left == 0) {
//         return 0;
//     }
//     if(left < 0) {
//         return -1;
//     }
//     if(n == 0) {
//         return -1;
//     }
//     if(num[n][0] > left) {
//         int l = 1, r = n-1, mid;
//         while(l <= r) {
//             int mid = (l + r) >> 1;
//             if(num[mid][0] > left) r = mid - 1;
//             else l = mid + 1;
//         }
//         return dfs(l, left);
//     }
//     int _ = -1;
//     for(long long cho = min(left/num[n][0], num[n][1]); ~cho; --cho) {
//         int __ = dfs(n - 1, left - 1ll * cho * num[n][0]);
//         if(__ != -1) {
//             if(_ == -1) _ = __;
//             else _ = min(_, __);
//         }
//     }
//     return _;
// }

void solve(){
    long long n, m;
    cin >> n >> m;
    vector<long long> ans(n+1);
    for(int k = 2; k <= n; ++k) {
        for(int i = 1; i * k <= n; ++i) ans[k] += 1ll * ((n/i/k) * (n/i/k - 1)) / 2 * mu[i];
    }
    long long all = m;
    int ret = 0;
    for(int i = n; i >= 2; --i) if(ans[i] >= i - 1) {
        int tmp = ans[i] / (i - 1) * (i - 1);
        if (all < tmp) {
            ret += all / (i-1);
            all %= i-1;
        }
        else {
            ret += ans[i] / (i-1);
            all -= tmp;
        }
    }
    if(all > 0) {
        cout << "-1" << endl;
        return ;
    }
    else cout << m + ret << endl;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
    init();
	while(T--) solve();
}
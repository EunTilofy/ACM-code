#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
int n, cnt;
int a[MN];
int v[MN], num[MN], f[MN];
const int P = 998244353;
int Add(int x, int y) {return (x+y)%P;}
int Mul(int x, int y) {return 1ll*x*y%P;}
int fpow(int x, int y) {
    int r = 1;
    for(;y;y>>=1,x=Mul(x,x))if(y&1)r=Mul(r, x);
    return r;
}
std::vector<pair<int,int>> d[MN];
bool in[MN];
int cal(int X) {
    vector<int> nm;
    vector<int> q(20, 0);
    int _ = 0;
    for(auto [x, y] : d[X]) _+=y, nm.push_back(x);
    int m=0;
    for(auto x : nm) {
        for(int y = 19; y >= 0; --y) if((x >> y) & 1) {
            if(!q[y]) {
                q[y] = x;
                break;
            } else x ^= q[y];
        }
    }
    for(auto x : q) if(x) m++;
    return fpow(2, _-m);
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    cnt = 0;
    for(int i = 1; i <= n; ++i) if(a[i] != a[i-1]) {
        v[++cnt] = a[i];
        num[cnt] = 1;
    } else ++num[cnt];
    for(int i = 1; i <= cnt; ++i) {
        f[i] = fpow(2, num[i]-1);
    }
    for(int i=1; i<=n;++i) in[a[i]]=1; in[0]=1;
    for(int i=1; i<=cnt;++i) {
        for(int j=0; j<=n;j+=v[i]) if(in[j]&&j!=v[i]) {
            d[j].push_back({v[i], num[i]});
        }
    }
    int ans=cal(0);
    ans = Add(ans, P-1);
    for(int i=1;i<=cnt;++i) if(d[v[i]].size()>0) {
        ans=Add(ans, Mul(cal(v[i]), f[i]));
    } else ans = Add(ans, f[i]);
    for(int i=0; i<=n;++i) d[i].clear(), in[i]=0;
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
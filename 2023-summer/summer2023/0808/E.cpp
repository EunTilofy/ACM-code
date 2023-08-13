#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;

int Add(int x, int y) {
    return (x + y) % mod;
}
int Mul(int x, int y) {
    return (1ll * x * y) % mod;
}
const int MX = 1e5+5;
int fac[MX], inv[MX];
int C(int n, int m) {
    if(m<0||m>n||n<0) return 0;
    return Mul(fac[n], Mul(inv[m], inv[n-m]));
}
vector<pair<int,int>> _;
int res;
int fpow(int x, int y) {
    int r = 1;
    for(;y;y>>=1, x=Mul(x,x)) if(y&1) r=Mul(r, x);
    return r;
}
void dfs(int now, int UP, int x, int fl, int n, int nn, int mm) {
    if(x == 0) return;
    if(now == UP) {
        // cerr << x << " " << y << endl;
        res = Add(res, Mul(fl, Mul(C(x, n), fpow(2, mm))));
        // res = Add(res, Mul(Mul(fl, fpow(2, nn)), Add(Mul(C(x, n),2), mod-C(y, n))));
        return;
    }
    else {
        dfs(now + 1, UP, Mul(x, _[now].second+1), fl, n, nn, mm);
        dfs(now + 1, UP, Mul(x, _[now].second), mod-fl, n, nn+1, mm+1);
        dfs(now + 1, UP, Mul(x, _[now].second-1), fl, n, nn+1, mm);
    }
}

int sol(int x, int n) {
    if(x <= 0) return 0;
    // cerr << x << " " << n << endl;
    _.clear();    
    int xx=x;
    int d=1;
    for(int i = 2; 1ll * i * i <= xx; ++i) if(x % i == 0) {
        int step = 0;
        while(x%i==0) ++step, x/=i;
        _.push_back({i, step});
        // cerr << step << " ~ ";
        d=Mul(d, step+1);
    }
    // cerr << endl;
    if(x!=1) _.push_back({x, 1}), d=Mul(d, 2);
    // cerr << "d = " << d << endl;
    if(n > d) return 0;
    res = 0;
    dfs(0, _.size(), 1, 1, n, 0, 0);
    // cout << _.size() << endl;
    // cerr << res << endl;
    return (res%mod+mod)%mod;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    for(int i = 2; i < MX; ++i) {
        fac[i] = Mul(i, fac[i-1]);
        inv[i] = Mul(inv[mod%i], (mod-mod/i));
    }
    for(int i = 2; i < MX; ++i) inv[i] = Mul(inv[i-1], inv[i]);

    int x, k;
    cin>>x>>k;
    int ans = 0;
    for(int i=1;1ll*i*i<=x;++i) if(x % i == 0){
        if(i <= x-i) ans = Add(ans, sol((x-i)/i, k));
        if(i != x/i && (x/i) <= x-(x/i)) ans = Add(ans, sol((x-(x/i))/(x/i), k));
    }
    cout << (ans%mod+mod)%mod;
    return 0;
}
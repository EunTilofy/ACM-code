#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int Add(int x, int y) {return (x+y)%mod;}
int Mul(int x, int y) {return 1ll*x*y%mod;}
int Dec(int x, int y) {return Add(x, mod-y);}
const int MN = 1e6+5;
int a[1<<21], b[1<<21], S[MN], w[MN], v[MN], vv[MN], pw[1<<21];

int dig[1<<21], val[1<<21], num[1<<21];
int fpow(int x, int y) {
    int r = 1;
    for(;y;x=1ll*x*x%mod, y>>=1)if(y&1)r=1ll*r*x%mod;
    return r;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;cin >> n;
    int _[21];
    for(int i = 0; i < 20; ++i) cin >> _[i];
    pw[1] = 0;
    for(int i = 2; i <= 2000000; i=i*2) {
        pw[i]=pw[i/2]+1;
    }
    for(int i = 1; i <= n; ++i) {
        cin >> S[i];
        int s = S[i];
        for(;s;s-=(s&(-s))) {
            v[i] = Add(v[i], _[pw[s&(-s)]]);
            ++w[i];
        }
        v[i] = fpow(v[i], w[i]);
        dig[S[i]] = w[i];
        ++num[S[i]];
        a[S[i]] = Add(a[S[i]], v[i]);
        val[S[i]] = v[i];
    }
    int all = (1<<20);
    for(int k = 1; k < all; k <<= 1) {
        for(int i = 0; i < all; i+=k<<1)
            for(int j = 0; j < k; ++j)
                a[i+j+k]=Add(a[i+j+k], a[i+j]);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans = Add(ans, Mul(v[i], Add(a[S[i]], mod-v[i])));
        // cerr << v[i] << " " << Add(a[S[i]], mod-v[i]) << "\n";
        b[S[i]] = Add(b[S[i]], vv[i]=Mul(w[i], Add(a[S[i]], mod-v[i])));
    }
    for(int k = 1; k < all; k <<= 1) {
        for(int i = 0; i < all; i+=k<<1)
            for(int j = 0; j < k; ++j)
                b[i+j+k]=Add(b[i+j+k], b[i+j]);
    }
    for(int i = 1; i <= n; ++i) {
        ans = Add(ans, Mul(v[i], Add(b[S[i]], mod-vv[i])));
        // cerr << v[i] << " " << Add(b[S[i]], mod-vv[i]) << "\n";
    }
    for(int i = 0; i < all; ++i) {
        if(num[i] >= 2) {
            ans = Add(ans, mod-Mul((1ll*num[i]*(num[i]-1)/2)%mod, Mul(val[i], val[i])));
            ans = Add(ans, mod-Mul(Mul(num[i],num[i]-1), Mul(dig[i], Mul(val[i], val[i]))));
        }
        if(num[i] >= 3) {
            ans = Add(ans, mod-Mul(Mul((1ll*num[i]*(num[i]-1)/2)%mod, num[i]-2), 
                Mul(Mul(val[i], val[i]), dig[i])));
        }
    }
    cout << ans << "\n";
    return 0;
}

/*
216 738
216 738
9 18
9 18
25 50
25 50

*/
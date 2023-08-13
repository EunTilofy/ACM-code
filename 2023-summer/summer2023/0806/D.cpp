#include<bits/stdc++.h>
using namespace std;

const int P = 998244353;

int Add(int x, int y) {
    return (x + y) % P;
}
int Mul(int x, int y) {
    return 1ll * x * y % P;
}
int fpow(int x, int y) {
    int r = 1;
    for(;y;y>>=1,x=Mul(x,x))if(y&1)r=Mul(r,x);
    return r;
}
int Inv(int x) {
    return fpow(x, P-2);
}
int Cal(int x, int y) {
    if(x == 1) return y + 1;
    return Mul((Add(fpow(x, y + 1), P-1)), Inv(x-1));
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    a = Mul(a, Inv(b));
    // cerr << a << endl;
    b = Add(1, P-a);
    a = Mul(a, Inv(Add(1, P-a)));
    // cerr << a << endl;
    int i=1, ans=1;
    for(i=2;i<=n;++i) {
        ans = Mul(Mul(ans, Cal(a, i-1)), fpow(b, i-1));
    }
    cout << ans;
}
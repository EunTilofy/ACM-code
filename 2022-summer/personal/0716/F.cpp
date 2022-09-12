// abandoned
#include<bits/stdc++.h>
using namespace std;
long long n, P;
const int MN = 5e5 + 5;
typedef std::pair<int, int> pii;
#define fi first
#define se second
int Mul(int x, int y){return 1ll * x * y % P;}
int Add(int x, int y){return (x + y) % P;}
pii Mul_(pii x, pii y){return make_pair(Add(Mul(x.fi, y.fi), P - Mul(x.se, y.se)), Add(Mul(x.fi, y.se), Mul(x.se, y.fi)));}
pii Add_(pii x, pii y){return make_pair(Add(x.fi, y.fi), Add(x.se, y.se));}
int fac[MN];
pii ans; 
pii fpow(pii x, long long y) {
    pii r = make_pair(1, 0);
    for(; y; y >>= 1, x = Mul_(x, x)) if(y & 1) r = Mul_(r, x);
    return r;
}
pii get() {
    
}
int main() {
    scanf("%lld%lld", &n, &P);
    for(int i = fac[0] = 1; i <= n; ++i) fac[i] = Mul(fac[i - 1], i);
    long long _ = n / P;
    ans = fpow(fpow(get(), _), _);

}
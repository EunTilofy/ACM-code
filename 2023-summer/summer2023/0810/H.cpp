#include<bits/stdc++.h>
using namespace std;

long double PI = 3.14159265358979323846264338327950288419716939937510582;
bool B[200000005];

long long num(long long x) {
    if(x <= 2) return 0;
    return (x + 1) / 2 - 1;
}
long long num2(long long x) {
    if(x < 8) return 0;
    return (x / 4) - 1 ;
}

typedef pair<long long, long long> pll;
pll get(pll x, pll y) {
    long double X = 1.0, Y = 1.0;
    X = x.first * X / x.second;
    Y = x.first * Y / y.second;
    X -= PI, Y -= PI;
    if(X < 0) X = -X;
    if(Y < 0) Y = -Y;
    if(X < Y) return x;
    return y;
}

void solve() {
    int l, r;
    cin >> l >> r;
    long long L = l * 2, R = l * 4;
    long long qL = (long long)sqrt(L), qR = (long long)sqrt(R);
    while(1ll * (qL + 1) * (qL + 1) + 1 <= L) ++qL;
    while(1ll * (qR + 1) * (qR + 1) + 4 <= R) ++qR;
    while((1ll * qL * qL + 1) / 2 > L) --qL;
    while((1ll * qR * qR + 4) / 4 > L) --qR;
    
    pair<long long, long long> ans = {l, (num(qL) + num2(qR)) * 2ll};

    for(int i = l; i <= r; ++i) {
        while((1ll * (qL + 1) * (1 + qL) + 1) / 2 <= i) ++qL;
        while((1ll * (qR + 1) * (qR + 1) + 4) / 4 <= i) ++qR;
        ans = get(ans, {i, (num(qL) + num2(qR)) * 2ll});
        cerr << i <<  " " << ((num(qL) + num2(qR)) * 2ll) << " " << qR << "\n";
    }
    long long g = gcd(ans.first, ans.second);
    ans.first /= g;
    ans.second /= g;
    cout << ans.first << " / " << ans.second << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // for(int i = 1; i <= 100; ++i) for(int j = i +1; j <= 100; ++j) for(int k = j +1; k <= 100; ++k) {
    //     if(i * i + j * j == k * k && gcd(gcd(i, j), k) == 1) cerr << i << " " << j << " " << k << "\n";
    // }

    int n;
    cin >> n;
    while(n--) solve();
}
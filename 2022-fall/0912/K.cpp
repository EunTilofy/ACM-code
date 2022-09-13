#include <bits/stdc++.h>
#define ll long long
using namespace std;

void read(int &x) {
    x = 0; char ch = getchar(); int f = 1;
    for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') f = -1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    x *= f;
}

int solve() {
    int n, a, b;
    read(n), read(a), read(b);
    if(a == b) return n;
    else {
        ll pos = 1ll * (n - 1) * a;
        int tmp = 1ll * n * a / b;
        if(1ll * tmp * b <= 1ll * (n - 1) * a) {
            return tmp + 1;
        }
        return tmp;
    }
}

int main() {
    int T; read(T);
    for(int o = 1; o <= T; ++o) {
        printf("%d\n", solve());
    }
    return 0;
}
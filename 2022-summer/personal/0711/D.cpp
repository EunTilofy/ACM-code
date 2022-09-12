#include<bits/stdc++.h>
using namespace std;
long long mi, ma;
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        mi = ma = 0;
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            int x;
            scanf("%d", &x);
            mi += (x + 3ll) / 2ll;
            ma += x - 1ll;
        }
        if((mi + ma) & 1) {
            puts("2");
            printf("%lld %lld\n", (mi + ma - 1ll) / 2ll, (mi + ma + 1ll) / 2ll);
        }
        else {
            puts("1");
            printf("%lld\n", (mi + ma) / 2ll);
        }
    }
}
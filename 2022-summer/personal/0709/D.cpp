#include<bits/stdc++.h>
using namespace std;
long long a,b,c,S;
int main() {
    int cas;
    scanf("%d", &cas);
    while(cas --) {
        long long ans;
        scanf("%lld%lld%lld%lld", &a, &b, &c, &S);
        if(1ll *a * b > c) {
            ans = 1ll *a * (S - 1) + std::max(a, c);
        }
        else{
            ans = 1ll * ((S - 1) / b) * c;
            long long lef = (S - 1) % b + 1;
            ans += std::max(1ll * a * (lef - 1) + std::max(a, c), 1ll * (lef / b) * c + 1ll * (lef % b) * a + ((lef % b) > 1) * std::max(0ll, c - a));   
        }
        printf("%lld\n", ans);
    }
    return 0;
}
/*
4
1 1 4 5
1 4 1 9
1 9 8 10
114 514 1919 810

*/
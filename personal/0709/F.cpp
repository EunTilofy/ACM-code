#include<bits/stdc++.h>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int a,b,c;
        scanf("%d%d%d", &a, &b, &c);
        double ans = b * b * b - a * a * a + (a - c) * (a - c) * (a - c);
        ans = pow(ans, 1.0/3);
        ans = (double)b - ans;
        printf("%.10lf\n", ans);
    }
}
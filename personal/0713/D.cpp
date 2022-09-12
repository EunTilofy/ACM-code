#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    long long sum = 0;
    for(int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        sum += x;
        if(sum <= 0 && i < n) return 0 * printf("NO");
    }
    printf("YES");
    return 0;
}
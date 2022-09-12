#include<bits/stdc++.h>
using namespace std;
inline long long read() {
    long long x = 0, f = 1;char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch <='9' && ch >='0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
bool mk[100000005];
int pr[100000005], mi[100000005], cnt;
void init() {
    for(int i = 2; i <= 100000000; ++i) {
        if(!mk[i]) {pr[++cnt] = i;}
        for(int j = 1; j <= cnt && 1ll * pr[j] * i <= 100000000; ++j) {
            mk[pr[j] * i] = true;
            mi[pr[j] * i] = pr[j];
            if(i % pr[j] == 0) break;
        }
    }
} 
int get_mi(long long x) {
    if(x <= 100000000) return mi[x];
    for(int i = 1; i <= cnt; ++i) {
        if(x % pr[i] == 0) return pr[i];
    }
    return x;
}

void sol(long long x) {
    printf("%lld = ", x);
    while(x != 1) {
        if(x <= 100000000 && !mk[x]) {printf("%d\n", x); return;}
        int r = get_mi(x);
        if(x == r) {printf("%d\n", x); return;}
        printf("%d * ", r);
        x /= r;
    }
}
int main() {
    init();
    long long res = 1;
    for(int i = 1; i <= 18; ++i) {
        res *= 10;
        sol((res - 1) / 3);
    }
    return 0;
}

/*
3 = 3
33 = 3 * 11
333 = 3 * 3 * 37
3333 = 3 * 11 * 101
33333 = 3 * 41 * 271
333333 = 3 * 3 * 7 * 11 * 13 * 37
3333333 = 3 * 239 * 4649
33333333 = 3 * 11 * 73 * 101 * 137
3333333333 = 3 * 11 * 41 * 271 * 9091
333333333333 = 3 * 3 * 7 * 11 * 13 * 37 * 101 * 9901
*/
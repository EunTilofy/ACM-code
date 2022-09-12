#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch <='9' && ch >='0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
int n;
const int MN = 1e5+5;
int a[MN],b[MN],nn;
long long now;
bool flag = 0;
void dfs(int id) {
    if(now == 1) {
        flag = 1;
        return ;
    }
    if(id > nn) return;
    for(int i = id; i <= nn; ++i) {
        if(now % b[i] == 0) {
            now /= b[i];
            dfs(i + 1);
            now *= b[i];
        }
    }
}

long long VAL[] = {0, 3, 33, 333, 3333, 33333, 333333, 3333333, 33333333, 3333333333, 333333333333};

int main() {
    n = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    std::sort(a + 1, a + n + 1);
    int last = 0; bool ok = 0;
    for(int i = 1; i <= n; ++i) {
        ok = 0;
        for(int j = 10; j; --j) {
            if(VAL[j] % a[i] == 0) {
                ok = 1;
                break;
            }
        }
        if(a[i] == a[last] && a[i] != 3 && last > 0) continue;
        if(a[last] == 3 && a[i] == 3 && last > 1) continue;
        if(ok) a[++last] = a[i];
    }
    n = last;
    for(int i = 10; i; --i) {
        now = VAL[i];
        nn = 0;
        for(int j = 1; j <= n; ++j) {
            if(VAL[i] % a[j] == 0) {
                b[++nn] = a[j];
            }
        }
        dfs(1);
        if(flag) return 0 * printf("%lld\n", VAL[i]);
    }
    puts("Not Found!");
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
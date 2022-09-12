#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch <='9' && ch >='0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
const int P = 1e9 + 7;
const int MN = 1e5 + 5;
int n, m, c;
int X[MN];
int mx, my;
int mp(int x, int y){return (x - 1) * m + y;}
int Mul(int x, int y) {return 1ll * x* y % P;}
int a[MN], b[MN], d[MN];
bool flag;
int ans;
int main() {
    n = read();
    m = read();
    c = read();
    mx = my = 1;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
        X[mp(i,j)] = read();
        if(X[mp(i,j)] > X[mp(mx, my)]) mx = i, my = j;
    }
    // a[mx] = max_num
    bool fl = 1;
    if(fl) {
        for(int i = 1; i <= m; ++i) b[i] = X[mp(mx, i)];
        memset(d, 0 ,sizeof d); flag = 1;
        memset(a, 0, sizeof a);
        long long res = 1ll;
        for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
            int val = X[mp(i, j)];
            if(val == b[j]) {
                d[i] = max(d[i], val);
                if(a[i] && a[i] < d[i]) flag = 0;
            }
            else if(val < b[j]){
                if((a[i] && a[i] != val) || val < d[i]) flag = 0;
                a[i] = val;
            }
            else flag = 0;
        }
        if(flag) {
            for(int i = 1; i <= n; ++i) {
                if(!a[i]) res = Mul(res, c - d[i] + 1);
            }
            ans = (ans + res) % P;
        }
    }
    // b[my] = max_num
    fl = 1;
    if(fl) {
        for(int i = 1; i <= n; ++i) a[i] = X[mp(i, my)];
        memset(d, 0 ,sizeof d); flag = 1;
        memset(b, 0, sizeof b);
        long long res = 1ll;
        for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
            int val = X[mp(i, j)];
            if(val == a[i]) {
                d[j] = max(d[j], val);
                if(b[j] && b[j] < d[j]) flag = 0;
            }
            else if(val < a[i]){
                if((b[j] && b[j] != val) || val < d[j]) flag = 0;
                b[j] = val;
            }
            else flag = 0;
        }
        if(flag) {
            for(int j = 1; j <= m; ++j) {
                if(!b[j]) res = Mul(res, c - d[j] + 1);
            }
            ans = (ans + res) % P;
        }
    }
    // a[mx] = b[my] = max_num
    fl = 1;
    if(fl) {
        for(int i = 1; i <= n; ++i) a[i] = X[mp(i, my)];
        for(int i = 1; i <= m; ++i) b[i] = X[mp(mx, i)];
        for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
            fl &= min(a[i], b[j]) == X[mp(i, j)];
        }
        if(fl) ans = (ans + P - 1) % P;
    }
    printf("%d\n", ans);
    return 0;
}
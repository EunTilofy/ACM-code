#include<bits/stdc++.h>
using namespace std;
#define int long long
long long read() {
    long long x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')f = -1; ch = getchar();}
    while(ch >='0' && ch <='9'){x = (x << 1) + (x << 3) + ch -'0'; ch = getchar();}
    return x * f;
}
#define MN 505
int n, m;
bool mk[MN][MN];
std::set<int> row[MN];
std::set<int>::iterator it;
int L, R, up[MN], down[MN];
// int id[MN];
// bool cmp(int x, int y) {return up[x] < up[y];}
// int t[MN << 2];
// void build(int k, int l, int r) {
//     if(l == r) {
//         t[k] = down[l + L - 1];
//         return ;
//     }
//     int mid = (l + r) >> 1;
//     build(k << 1, l, mid);
//     build(k << 1 | 1, mid + 1, r);
//     t[k] = min(t[k << 1], t[k << 1 | 1]);
// }
// int que(int k, int l, int r, int a, int b) {
//     if(l == a && r == b) return t[k];
//     int mid = (l + r) >> 1;
//     if(b <= mid) return que(k << 1, l, mid, a, b);
//     if(a > mid) return que(k << 1 | 1, mid + 1, r, a, b);
//     return min(que(k << 1, l, mid, a, mid), que(k << 1 | 1, mid + 1, r, mid + 1, b));
// }
int get_up(int x, int y) {
    it = row[y].lower_bound(x); --it;
    return x - *it - 1;
}
int get_down(int x, int y) {
    it = row[y].upper_bound(x);
    return *it - x - 1;
}
long long cal(int x, int y) {
    L = R = y;
    up[y] = get_up(x, y);
    down[y] = get_down(x, y);
    while(L - 1 >= 1 && !mk[x][L - 1]) {
        --L;
        up[L] = get_up(x, L);
        down[L] = get_down(x, L);
    }
    while(R + 1 <= m && !mk[x][R + 1]) {
        ++R;
        up[R] = get_up(x, R);
        down[R] = get_down(x, R);
    }
    // build(1, 1, R - L + 1);
    // for(int i = L; i <= R; ++i) id[i] = i;
    // std::sort(id + L, id + R + 1, cmp);
    // int last = -1, LL = L, RR = R;
    long long ret = 0ll;
    for(int i = L; i <= y; ++i) {
        int above = up[y], below = down[y];
        for(int j = L; j <= y; ++j) above = min(above, up[j]), below = min(below, down[j]);
        for(int j = y; j <= R; ++j) {
            above = min(above, up[j]);
            below = min(below, down[j]);
            ret += 1ll * (above + 1) * (below + 1);
        }
    }
    // for(int i = L; i <= R; ++i) {
    //     if(LL > RR) break;
    //     int o = id[i];
    //     int below = que(1, 1, R - L + 1, LL - L + 1, RR - L + 1);
    //     ret += 1ll * (below + 1) * (up[o] - last) * 1ll * (1 + y - LL) * (1 + RR - y);
    //     if(id[i] <= y) LL = max(LL, id[i] + 1);
    //     if(id[i] >= y) RR = min(RR, id[i] - 1);       
    //     last = up[o];
    //     while(i + 1 <= R && up[id[i + 1]] == up[o]) {
    //         ++i;
    //         if(id[i] <= y) LL = max(LL, id[i] + 1);
    //         if(id[i] >= y) RR = min(RR, id[i] - 1);
    //     }
    // }
    return ret;
}
signed main() {
    n = read(); m = read();
    int all = n * m;
    long long ans = 0, lastans = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) ans = ans + 1ll * (n - i + 1) * (m - j + 1);
    // printf("%d\n", ans);
    for(int i = 1; i <= m; ++i) row[i].insert(0), row[i].insert(n + 1);
    while(all --) {
        long long x = read() ^ lastans;
        long long y = read() ^ lastans;
        if(x < 1 || x > n || y < 1 || y > m || mk[x][y]) return 0;
        ans -= cal(x, y);
        mk[x][y] = 1;
        row[y].insert(x);
        printf("%lld\n", ans);
        lastans = ans;
    }
    return 0;
}
/*
2 2
2 1
7 7
2 2
0 3
*/
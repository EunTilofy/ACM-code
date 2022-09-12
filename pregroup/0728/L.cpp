#include<bits/stdc++.h>
using namespace std;
int read(void) {
    int ch = getchar(), res = 0, flg = 0;
    while (!isdigit(ch) && ch != '-')
        ch = getchar();
    if (ch == '-')
        flg = 1, ch = getchar();
    for (; isdigit(ch); ch = getchar())
        res = (res << 1) + (res << 3) + (ch - '0');
    return flg ? -res : res;
}
const int MN = 1e6 + 6;
int n, a[MN], b[MN][22], c[MN];
int q[MN], top;
long long ans[MN];
int get(int l, int r, int x) {
    if(l > r) return 0;
    int p = l - 1;
    for(int j = 20; ~j; --j) if(b[p][j] <= n && a[b[p][j]] >= x) p = b[p][j];
    p = b[p][0];
    if(p <= r) {
        int ret = 1;
        for(int j = 20; ~j; --j) if(b[p][j] <= r) p = b[p][j], ret += (1 << j);
        return ret;
    }
    else return 0;
}
int main() {
    n = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    q[top = 1] = n; b[n][0] = n + 1; a[0] = n + 1;
    for(int i = n - 1; ~i; --i) {
        while(top && a[q[top]] >= a[i]) --top;
        if(top) b[i][0] = q[top];
        else b[i][0] = n + 1;
        q[++top] = i;
    }
    c[2] = a[2];
    for(int i = 3; i <= n; ++i) c[i] = min(c[i - 1], a[i]);
    for(int k = 1; k <= 20; ++k) for(int i = 0; i <= n; ++i) {
        if(b[i][k - 1] == n + 1) b[i][k] = n + 1;
        else b[i][k] = b[b[i][k - 1]][k - 1];
    }
    int MI = a[1], last = 1, step = 1;
    ans[1] = 1;
    for(int i = 2; i <= n; ++i) {
        if(a[i] < MI) {
            ++step;
            ans[i] = ans[last] + 2;
            if(last == 1) ans[i] --;
            for(int j = last; j < i; ++j) {
                ans[i] += 2 + get(2, j - 1, a[j]);
            }
            last = i; MI = a[i];
        }
        else {
            ans[i] = ans[i - 1];
            ans[i] += 2 + get(2, last - 1, a[i]);
            if(min(a[i], c[last - 1]) < a[1]) {
                ans[i] += get(last + 1, i - 1, min(a[i], c[last - 1]));
            }
            else ans[i] += get(last + 1, i - 1, a[1]) + 1;
        }
    }
    for(int i = 1; i <= n; ++i) printf("%d ", ans[i]);
    return 0;
}
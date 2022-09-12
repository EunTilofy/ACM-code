#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch <='9' && ch >='0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
const int MN = 2e5+5;
int n,q;
double t[MN << 2], t0[MN << 2], tag1[MN << 2], tag2[MN << 2];
bool tag3[MN << 2];
void pushup(int k) {
    t[k] = max(t[k<<1], t[k<<1|1]);
    t0[k] = max(t0[k<<1], t0[k<<1|1]);
}
void build(int k, int l, int r) {
    if(l == r) {
        t[k] = t0[k] = read();
        tag1[k] = 0;
        tag2[k] = 1;
        tag3[k] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build(k<<1|1, mid + 1, r);
    pushup(k);
}
#define ls (k<<1)
#define rs (k<<1|1)
void pushdown(int k) {
    if(tag3[k]) {
        tag1[ls] = tag1[rs] = 0;
        tag2[ls] = tag2[rs] = 1;
        tag3[ls] = tag3[rs] = 1;
        t[ls] = t0[ls];
        t[rs] = t0[rs];
        tag3[k] = 0;
        return ;
    }
    double a = tag2[k], b = tag1[k];
    t[ls] = t[ls] * a + b;
    t[rs] = t[rs] * a + b;
    tag2[ls] *= a;
    tag2[rs] *= a;
    tag1[ls] = tag1[ls] * a + b;
    tag1[rs] = tag1[rs] * a + b;
    tag1[k] = 0; tag2[k] = 1;
    return ; 
}
void add(int k, int l, int r, int a, int b, int x) {
    if(l == a && r == b) {
        tag1[k] += x;
        t[k] += x;
        return ;
    }
    pushdown(k);
    int mid = (l + r) >> 1;
    if(b <= mid) add(ls, l, mid, a, b, x);
    else if(a > mid) add(rs, mid + 1, r, a, b, x);
    else add(ls, l, mid, a, mid, x), add(rs, mid+1, r, mid+1, b, x);
    pushup(k);
}
void div(int k, int l, int r, int a, int b, int x) {
    if(l == a && r == b) {
        tag1[k] /= (double)x;
        tag2[k] /= (double)x;
        t[k] /= (double)x;
        return ;
    }
    pushdown(k);
    int mid = (l + r) >> 1;
    if(b <= mid) div(ls, l, mid, a, b, x);
    else if(a > mid) div(rs, mid + 1, r, a, b, x);
    else div(ls, l, mid, a, mid, x), div(rs, mid+1, r, mid+1, b, x);
    pushup(k);
}
void rem(int k, int l, int r, int a, int b) {
    if(l == a && r == b) {
        tag3[k] = 1;
        tag2[k] = 1;
        tag1[k] = 0;
        t[k] = t0[k];
        return ;
    }
    pushdown(k);
    int mid = (l + r) >> 1;
    if(b <= mid) rem(ls, l, mid, a, b);
    else if(a > mid) rem(rs, mid + 1, r, a, b);
    else rem(ls, l, mid, a, mid), rem(rs, mid+1, r, mid+1, b);
    pushup(k);
}
int que(int k, int l, int r, int a, int b) {
    if(l == a && r == b) {
        return (int)t[k];
    }
    pushdown(k);
    int mid = (l + r) >> 1;
    if(b <= mid) return que(ls, l, mid, a, b);
    else if(a > mid) return que(rs, mid + 1, r, a, b);
    else return max(que(ls, l, mid, a, mid), que(rs, mid+1, r, mid+1, b));
}
int main() {
    n = read(), q = read();
    build(1, 1, n);
    int opt, l, r, x;
    while(q --) {
        opt = read(), l = read() + 1, r= read() + 1, x = read();
        if(opt == 0) {
            add(1, 1, n, l, r, x);
        }
        else if(opt == 1) {
            div(1, 1, n, l, r, x);
        }
        else if(opt == 2) {
            printf("%d\n", que(1, 1, n, l, r));
        }
        else rem(1, 1, n, l, r);
    }
}
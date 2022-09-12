#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch <='9' && ch >='0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
const int MN = 1005;
struct xxx{
    // 1
    int num1, pos1[2], l1[2], r1[2];
    // -1
    int num2, pos2[2], l2[2], r2[2];
    // node
    int num3, x[25], y[25];
    //flag
    bool cannot;
}a[MN];
int n;
xxx cb(xxx x, xxx y) {
    xxx ret;
    ret.num1 = ret.num2 = ret.num3 = ret.cannot = 0;
    if(x.cannot || y.cannot) {ret.cannot = 1; return ret;}
    
    for(int i = 0; i < x.num1; ++i) for(int j = 0; j < y.num1; ++j) if(x.pos1[i] == y.pos1[j]) {
        int l = max(x.l1[i], y.l1[j]);
        int r = min(x.r1[i], y.r1[j]);
        if(l == r) {
            ret.x[ret.num3] = l;
            ret.y[ret.num3] = l + x.pos1[i];
            ret.num3 ++;
        }
        else if(l < r) {
            ret.pos1[ret.num1] = x.pos1[i];
            ret.l1[ret.num1] = l;
            ret.r1[ret.num1] = r;
            ret.num1 ++; 
        }
    }
    for(int i = 0; i < x.num2; ++i) for(int j = 0; j < y.num2; ++j) if(x.pos2[i] == y.pos2[j]) {
        int l = max(x.l2[i], y.l2[j]);
        int r = min(x.r2[i], y.r2[j]);
        if(l == r) {
            ret.x[ret.num3] = l;
            ret.y[ret.num3] = x.pos2[i] - l;
            ret.num3 ++;
        }
        else if(l < r) {
            ret.pos2[ret.num2] = x.pos2[i];
            ret.l2[ret.num2] = l;
            ret.r2[ret.num2] = r;
            ret.num2 ++; 
        }
    }
    for(int i = 0; i < x.num1; ++i) for(int j = 0; j < y.num2; ++j) {
        int p1 = x.pos1[i];
        int p2 = y.pos2[j];
        int xx = (p2 - p1) / 2;
        int yy = xx + p1;
        int l = max(x.l1[i], y.l2[j]);
        int r = min(x.r1[i], y.r2[j]);
        if(yy - xx == p1 && yy + xx == p2 && xx >= l && xx <= r) {
            ret.x[ret.num3] = xx;
            ret.y[ret.num3] = yy;
            ret.num3 ++;
        }
    }
    for(int i = 0; i < y.num1; ++i) for(int j = 0; j < x.num2; ++j) {
        int p1 = y.pos1[i];
        int p2 = x.pos2[j];
        int xx = (p2 - p1) / 2;
        int yy = xx + p1;
        int l = max(y.l1[i], x.l2[j]);
        int r = min(y.r1[i], x.r2[j]);
        if(yy - xx == p1 && yy + xx == p2 && xx >= l && xx <= r) {
            ret.x[ret.num3] = xx;
            ret.y[ret.num3] = yy;
            ret.num3 ++;
        }
    }
    for(int i = 0; i < x.num3; ++i) {
        bool flag = 0;
        int xx = x.x[i], yy = x.y[i];
        for(int j = 0; j < y.num1; ++j) if(yy - xx == y.pos1[j]) {
            flag |= ((xx >= y.l1[j]) && (xx <= y.r1[j]));
        }
        for(int j = 0; j < y.num2; ++j) if(yy + xx == y.pos2[j]) {
            flag |= ((xx >= y.l2[j]) && (xx <= y.r2[j]));
        }
        for(int j = 0; j < y.num3; ++j) {
            flag |= ((xx == y.x[j]) && (yy == y.y[j]));
        }
        if(flag == 1) {
            ret.x[ret.num3] = xx;
            ret.y[ret.num3] = yy;
            ret.num3 ++;
        }
    }
    for(int i = 0; i < y.num3; ++i) {
        bool flag = 0;
        int xx = y.x[i], yy = y.y[i];
        for(int j = 0; j < x.num1; ++j) if(yy - xx == x.pos1[j]) {
            flag |= ((xx >= x.l1[j]) && (xx <= x.r1[j]));
        }
        for(int j = 0; j < x.num2; ++j) if(yy + xx == x.pos2[j]) {
            flag |= ((xx >= x.l2[j]) && (xx <= x.r2[j]));
        }
        for(int j = 0; j < x.num3; ++j) {
            flag |= ((xx == x.x[j]) && (yy == x.y[j]));
        }
        if(flag == 1) {
            ret.x[ret.num3] = xx;
            ret.y[ret.num3] = yy;
            ret.num3 ++;
        }
    }
    bool o[30];
    memset(o, 0, sizeof o);
    for(int i = 0; i < ret.num3; ++i) if(!o[i]) for(int j = i + 1; j < ret.num3; ++j) {
        if(ret.x[j] == ret.x[i] && ret.y[j] == ret.y[i]) o[j] = 1;
    }
    for(int i = 0; i < ret.num3; ++i) if(!o[i]) {
        int xx = ret.x[i], yy = ret.y[i];
        for(int j = 0; j < ret.num1; ++j) if(yy - xx == ret.pos1[j]) {
            o[i] |= ((xx >= ret.l1[j]) && (xx <= ret.r1[j]));
        }
        for(int j = 0; j < ret.num2; ++j) if(yy + xx == ret.pos2[j]) {
            o[i] |= ((xx >= ret.l2[j]) && (xx <= ret.r2[j]));
        }
    }
    int tmp = 0;
    for(int i = 0; i < ret.num3; ++i) if(!o[i]) {
        ret.x[tmp] = ret.x[i];
        ret.y[tmp] = ret.y[i];
        ++tmp;
    }
    ret.num3 = tmp;
    if(ret.num3 == 0 && ret.num1 == 0 && ret.num2 == 0) ret.cannot = 1;
    return ret;
}
int main() {
    n = read();
    for(int i = 1; i <= n; ++i) {
        int x, y, D;
        x = read(), y = read(), D = read();
        if(D == 0) {
            a[i].num1 = a[i].num2 = 0;
            a[i].num3 = 1;
            a[i].x[0] = x;
            a[i].y[0] = y;
            a[i].cannot = 0;
        }
        else {
            a[i].num1 = a[i].num2 = 2;
            a[i].num3 = 0;
            a[i].pos1[0] = y - x + D;
            a[i].pos1[1] = y - x - D;
            a[i].pos2[0] = x + y - D;
            a[i].pos2[1] = x + y + D;
            a[i].l1[0] = a[i].l2[0] = x - D;
            a[i].r1[0] = a[i].l1[1] = x;
            a[i].r2[0] = a[i].l2[1] = x;
            a[i].r1[1] = a[i].r2[1] = x + D;
            a[i].cannot = 0;
        }
    }
    xxx now = a[1];
    for(int i = 2; i <= n; ++i) {
        now = cb(now, a[i]);
    }
    if(now.cannot) puts("impossible");
    else {
        if(now.num1 > 0 || now.num2 > 0 || now.num3 > 1) puts("uncertain");
        else printf("%d %d\n", now.x[0], now.y[0]);
    }
    return 0;
}
/*
3
999999 0 1000
999900 950 451
987654 123 13222

2
100 0 101
0 200 199

2
100 0 100
0 200 199

2
0 0 5
10 0 6


*/
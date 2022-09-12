#include<bits/stdc++.h>
using namespace std;
const int MN = 1e5 + 5;
inline int read() {
	int x = 0, f = 1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n, a[MN], id[MN], rk[MN], pre_rk[MN], val[MN];
bool cmp(int x, int y) {return (a[x] < a[y]);}

struct node{
    int val, lazy_add, lazy_min;
    bool _add, _min;
}t[MN << 2];

void build(int k, int l, int r) {
    if(l == r) {
        t[k].val = max(val[l] - a[n], 0);
        return ;
    }
    int mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    t[k].val = min(t[k<<1].val, t[k<<1|1].val);
}

void pushdown(int k, int l, int r) {
    if(t[k]._min) {
        t[k << 1]._min = t[k << 1 | 1]._min = 1;
        t[k << 1].lazy_min = min(t[k << 1].lazy_min, t[k].lazy_min);
        t[k << 1 | 1].lazy_min = min(t[k << 1 | 1].lazy_min, t[k].lazy_min);
        t[k << 1].val = min(t[k << 1].val, t[k << 1].lazy_min);
        t[k << 1 | 1].val = min(t[k << 1 | 1].val, t[k << 1 | 1].lazy_min);
        t[k]._min = t[k].lazy_min = 0;
    }
    if(t[k]._add) {
        t[k << 1]._add = t[k << 1 | 1]._add = 1;
        t[k << 1].lazy_add += t[k].lazy_add;
        t[k << 1 | 1].lazy_add += t[k].lazy_add;
        t[k << 1].val += t[k].lazy_add;
        t[k << 1 | 1].val += t[k].lazy_add;
        t[k]._add = t[k].lazy_add = 0;
    }
}

int que(int k, int l, int r, int x) {
    if(l == r) {return t[k].val;}
    int mid = (l + r) >> 1;
    pushdown(k, l, r);
    if(x <= mid) return que(k<<1, l, mid, x);
    else return que(k<<1|1, mid + 1, r, x);
}

int f(int x) {
    return que(1, 1, n, x);
}

int main() {
    n = read();
    for(int i = 1; i <= n; ++i) a[i] = read(), id[i] = i;

    std::sort(id + 1, id + n + 1, cmp);
    for(int i = 1; i <= n; ++i) {
        if(i == 1) rk[id[i]] = 1;
        else rk[id[i]] = rk[id[i - 1]] + (a[id[i]] != a[id[i - 1]]);
        val[i] = a[id[i]];
    }

    for(int i = 1; i <= n; ++i) pre_rk[i] = max(pre_rk[i - 1], rk[i]);

    build(1, 1, rk[n]);
    
    for(int i = n - 1; i; --i) {
        int Max = pre_rk[i - 1];
        if(rk[i] >= Max) continue;
        //j <= rk[i]

        //j > rk[i]
        // Add(1, 1, rk[n], rk[i] + 1, Max, )?
    }
    
    return 0 * printf("%lld\n", f(rk[1]));
}
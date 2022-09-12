#include<bits/stdc++.h>
using namespace std;
const int MN = 5e5+5;
inline int read() {
    int x = 0, f = 1;char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch <='9' && ch >='0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
int Q, q[MN][2], n;
bool st[MN];
int fa[MN][20];
std::vector<int> chi[MN];
int pos[MN], id[MN], l[MN], r[MN], dind = 0;
void dfs(int x) {
    id[++dind] = x;
    pos[x] = dind;
    l[x] = dind;
    for(unsigned int i = 0; i < chi[x].size(); ++i) dfs(chi[x][i]);
    r[x] = dind;
}
int t[MN << 2];
void pushup(int k) {
    if(t[k<<1] != -1) t[k] = t[k<<1];
    else t[k] = t[k<<1|1];
}
void build(int k, int l, int r) {
    if(l == r) {
        if(st[id[l]]) t[k] = -1;
        else t[k] = id[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(k<<1, l, mid);
    build(k<<1|1, mid + 1, r);
    pushup(k);
}
void edi(int k, int l, int r, int x) {
    if(l == r) {
        if(st[id[l]]) t[k] = -1;
        else t[k] = id[l];
        return ;
    }
    int mid = (l + r) >> 1;
    if(x <= mid) edi(k<<1, l, mid, x);
    else edi(k<<1|1, mid + 1, r, x);
    pushup(k);
}
int que(int k, int l, int r, int a, int b) {
    if(l == a && r == b) return t[k];
    int mid = (l + r) >> 1;
    if(b <= mid) return que(k<<1, l, mid, a, b);
    else if(a > mid) return que(k<<1|1, mid + 1, r, a, b);
    else {
        int res = que(k<<1, l, mid, a, mid);
        if(res != -1) return res;
        return que(k<<1|1, mid + 1, r, mid + 1, b);
    }
}
std::vector<int> ans;
int main() {
    Q = read();
    n = 1;
    for(int i = 1; i <= Q; ++i) {
        q[i][0] = read();
        q[i][1] = read();
        if(q[i][0] == 1) {
            fa[++n][0] = q[i][1];
            chi[q[i][1]].push_back(n);
            for(int i = 1; i < 20; ++i) fa[n][i] = fa[fa[n][i -1]][i - 1];
            q[i][1] = n;
        }
        if(q[i][0] == 2) st[q[i][1]] ^= 1;
    }
    dfs(1);
    build(1, 1, n);
// puts("ok");    

    for(int i = Q; i; --i) {
        if(q[i][0] == 1) {
            st[q[i][1]] ^= 1;
            edi(1, 1, n, pos[q[i][1]]);
        }
        else if(q[i][0] == 2) {
            st[q[i][1]] ^= 1;
            edi(1, 1, n, pos[q[i][1]]);            
        }
        else{
            int x = q[i][1];
            int _ = que(1, 1, n, l[x], r[x]);
            if(_ != -1) {
                ans.push_back(_);
                continue;
            }
            for(int o = 19; o>=0; --o) if(fa[x][o]) {
                int ro = fa[x][o];
                if(que(1, 1, n, l[ro], r[ro]) == -1) x = ro; 
            }
            // printf("ro = %d\n", x);
            if(x == 1) ans.push_back(-1);
            else ans.push_back(que(1, 1, n, l[fa[x][0]], r[fa[x][0]]));
        }
    }
    for(int i = ans.size() - 1; ~i; --i) printf("%d\n", ans[i]);
    return 0;
}
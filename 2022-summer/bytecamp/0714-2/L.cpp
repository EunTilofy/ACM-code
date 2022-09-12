#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch <='9' && ch >='0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
const int MN = 150005;
int ch[MN * 64][2], tot;
bool in[MN];
std::set<int> S[MN];
int t[MN * 64], cnt;
std::set<int>::iterator it;
int num[MN * 64];
void add(int x, int now, int step, int id, int ADD) {
    bool k = (x >> step) & 1;
    if(!ch[now][k]) ch[now][k] = ++tot;
    num[ch[now][k]] += ADD;
    if(step == 0) {
        if(!t[ch[now][k]]) t[ch[now][k]] = ++cnt;
        //if(x == 3) printf("the value 3 :%d\n", t[ch[now][k]]);
        // if(ADD == -1) printf("DEL %d\n", t[ch[now][k]]);
        if(ADD == 1) S[t[ch[now][k]]].insert(id);
        else S[t[ch[now][k]]].erase(id);
        return ;
    }
    add(x, ch[now][k], step - 1, id, ADD);
}
long long a[MN], p[MN];
int xxor = 0;
std::pair<int, int> que(int x) {
    int _ = xxor ^ x;
    int now = 0, step = 63;
    // printf("_ = %d \n", _);
    for(; ~step; --step) {
        bool k = (_ >> step) & 1;
        // printf("k = %d ", k);
        if(num[ch[now][k ^ 1]] > 0) now = ch[now][k ^ 1]; //, printf("to %d \n", k ^ 1);
        else now = ch[now][k]; //, printf("to : %d \n", k);
    }
    it = S[t[now]].end(); --it;
    // printf("found %d %d %d\n", t[now], S[t[now]].size(), *it);
    return make_pair(*it, p[*it] ^ p[1] ^ xxor);
}
int n;
signed main() {
    n = read();
    for(int i = 1; i <= n; ++i) {
        a[i] = read();
        p[i] = p[i - 1] ^ a[i];
        if(i < n && i > 1) add(p[i] ^ p[1], 0, 63, i, 1), in[i] = 1;
    }
    if(n < 3) {
        for(int i = 1; i <= n; ++i) printf("%lld ", a[i]);
        return 0;
    }
    int now = a[1], di = 1, last = 1;
    for(int i = 1; i < n - 1; ++i) {
        std::pair<int, int> o = que(now);
        // printf("%d %d\n", o.first, o.second);
        if(now > (now ^ o.second)) {
            printf("%lld ", now);
            now = p[last];
            ++last; while(!in[last]) ++last;
            now ^= p[last];
            if(i == n - 2) break;
            xxor ^= p[di];
            ++di; while(!in[di]) ++di;
            add(p[di] ^ p[1], 0, 63, di, -1); in[di] = 0;
            xxor ^= p[di];
        }
        else {
            // printf("%d\n", o.first);
            printf("%lld ", now ^ o.second);
            // printf("%d\n", o.first);
            add(p[o.first] ^ p[1], 0, 63, o.first, -1); in[o.first] = 0;
            now = o.second;
        }
    }
    int j = n - 1;
    while(!in[j] && j >= 2) a[n] ^= a[j--];
    printf("%lld %lld", now, a[n]);
    return 0;
}
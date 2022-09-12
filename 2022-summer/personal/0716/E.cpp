#include<bits/stdc++.h>
using namespace std;
#define int long long
long long fpow(long long x, int y, long long mod) {
    __int128 r = 1;
    __int128 X = x;
    for(; y; y >>= 1, X = X * X % mod) if(y & 1) r = r * X % mod;
    return (long long)r;
}
long long Mul(long long x, long long y, long long mod) {
    __int128 r = x;
    r = r * y % mod;
    return (long long)r;
}
long long n, r, p;
long long S[8] = {2, 3, 5, 7, 11, 13, 17, 19};
struct STR{
    int len;
    int a,b,c,d;
    int ok;
};
void print(STR o) {
    if(o.len >= 1) printf("%c", o.a + 'A' - 1);
    if(o.len >= 2) printf("%c", o.b + 'A' - 1);
    if(o.len >= 3) printf("%c", o.c + 'A' - 1);
    if(o.len >= 4) printf("%c", o.d + 'A' - 1);
}
map<long long, STR> mp;
map<long long, STR>::iterator it;
int tmp[4];
std::pair<STR, STR> ans; int tot = 0;
void dfs1(int now, int UP, int len, long long tmp_val) {
    if(now == UP) {
        STR o;
        o.len = len;
        if(len >= 1) o.a = tmp[0]; else o.a = 0;
        if(len >= 2) o.b = tmp[1]; else o.b = 0;
        if(len >= 3) o.c = tmp[2]; else o.c = 0;
        if(len >= 4) o.d = tmp[3]; else o.d = 0;
        o.ok = 1;
        if(mp.count(tmp_val)) o.ok = 0;
        mp[tmp_val] = o;
        return;
    }
    for(int i = 1; i <= 26; ++i) {
        tmp[len - UP + now] = i;
        dfs1(now + 1, UP, len, Mul(tmp_val, fpow(S[now], i, p), p));
    }
}  
void dfs2(int now, int UP, int len, long long tmp_val) {
    // printf("%d %d\n", now, UP);
    if(now == UP) {
        STR o;
        o.len = len;
        if(len >= 1) o.a = tmp[0]; else o.a = 0;
        if(len >= 2) o.b = tmp[1]; else o.b = 0;
        if(len >= 3) o.c = tmp[2]; else o.c = 0;
        if(len >= 4) o.d = tmp[3]; else o.d = 0;
        long long exp = Mul(r, fpow(tmp_val, p - 2, p), p);
        // printf("%lld %lld\n", tmp_val, exp);
        if(mp.count(exp)) {
            ++tot;
            if(mp[exp].ok == 0 || tot > 1) {puts("ambiguous"); exit(0);}
            ans = make_pair(mp[exp], o);
        }
        return;
    }
    for(int i = 1; i <= 26; ++i) {
        tmp[len - UP + now] = i;
        dfs2(now + 1, UP, len, Mul(tmp_val, fpow(S[now], i, p), p));
    }
}
signed main() {
    scanf("%lld%lld%lld", &n, &r, &p);
    if(S[n - 1] >= p) {
        if(r == 0) return 0 * puts("ambiguous");
        else return 0 * puts("not a word");
    }
    if(r == 0) return 0 * puts("not a word");
    int mid = n >> 1;
    dfs1(0, mid, mid, 1);
    dfs2(mid, n, n - mid, 1);
    if(!tot) return 0 * puts("not a word");
    print(ans.first);print(ans.second);
    return 0;
}
//6 215457738 998244353
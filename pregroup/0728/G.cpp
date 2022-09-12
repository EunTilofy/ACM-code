#include<bits/stdc++.h>
using namespace std;
#define P 1000000007
#define B 29

int n, k;
const int MN = 1e5 + 5;
int pos[MN], len[MN], vt, a[MN * 10], b[MN * 10], lent;
char t[MN], s[MN * 10];
int powB[MN * 10];
int get(int l, int r) {
    return (a[r] - 1ll * a[l - 1] * powB[r -l + 1] % P + P) % P;
}

std::map<int, int> o, oo;

bool chk(int x) {
    oo.clear();
    for(int i = 1; i <= n; ++i) {
        o.clear();
        for(int j = pos[i]; j <= pos[i] + len[i] - x; ++j) {
            if(b[j] + lent - 1 <= j + x - 1) {
                j = b[j];
                continue;
            }
            if(++o[get(j, j + x - 1)] == k) {
                if(++oo[get(j, j + x - 1)] == n) return 1;
            }
        }
    }
    return 0;
}
int main() {
    scanf("%d%d", &n, &k);
    int now = 1;
    for(int i = 1; i <= n; ++i) {
        pos[i] = now;
        scanf("%s", s + now);
        now += len[i] = strlen(s + now);
    }
    scanf("%s", t + 1);
    lent = strlen(t + 1);
    for(int i = powB[0] = 1; i <= now; ++i) powB[i] = 1ll *powB[i - 1] * B % P; 
    for(int i = 1; i <= lent; ++i) {
        vt = (1ll * vt * B % P + t[i] - 'a' + 1) % P;
    }
    for(int i = 1; i <= now; ++i) {
        a[i] = (1ll * a[i - 1] * B % P + s[i] - 'a' + 1) % P;
    }
    b[now] = now + 1;
    for(int i = now - 1; i; --i) {
        b[i] = b[i + 1];
        if(i + lent - 1 <= now) {
            if(get(i, i + lent - 1) == vt) b[i] = i;
        }
    }
    int l = 1, r = now, ans = -1, mid;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(chk(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    return 0 * printf("%d\n", ans);
}
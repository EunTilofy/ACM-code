#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
    while(ch >='0' && ch <='9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
#define MN 100005
int n, q;
bool mk[MN];
int tot, pr[MN], mi[MN], a[MN], b[MN];
void init() {
    for(int i = 2; i < MN; ++i) {
        if(!mk[i]) {pr[++tot] = i; mi[i] = tot;}
        for(int j = 1; j <= tot && 1ll * pr[j] * i < MN; ++j) {
            mk[i * pr[j]] = 1;
            mi[i * pr[j]] = j;
            if(i % pr[j] == 0) break;
        }
    }
}
int c[MN][2];
long long ans, alla, allb;
int main() {
    init();
    n = read();
    for(int i = 1; i <= n; ++i) {
        a[i] = read();
        int x = a[i];
        while(x != 1) {
            int j = mi[x];
            bool num = 0;
            while(x % pr[j] == 0) x /= pr[j], num ^= 1;
            if(num) alla += pr[j], c[j][0]++;
        }
    }
    for(int i = 1; i <= n; ++i) {
        b[i] = read();
        int x = b[i];
        while(x != 1) {
            int j = mi[x];
            bool num = 0;
            while(x % pr[j] == 0) x /= pr[j], num ^= 1;
            if(num) allb += pr[j], c[j][1] ++;
        }
    }
    for(int i = 1; i <= tot; ++i) {
        ans += 1ll * pr[i] * c[i][0] * (n - c[i][1]);
        ans += 1ll * pr[i] * c[i][1] * (n - c[i][0]);
    }

    printf("%lld\n", ans);

    q = read();
    while(q --) {
        int opt = read();
        int id = read();
        int y = read();
        if(opt == 1) {
            int x = a[id];
            while(x != 1) {
                int j = mi[x];
                bool num = 0;
                while(x % pr[j] == 0) x /= pr[j], num ^= 1;
                long long all = 0;
                if(num == 1) {
                    c[j][0] --;
                    ans -= 1ll * pr[j] * (n - c[j][1]);
                    all += 1ll * pr[j] * c[j][1];
                    alla -= pr[j];
                }
            }
            ans -= allb;
            x = y;
            while(x != 1) {
                int j = mi[x];
                bool num = 0;
                while(x % pr[j] == 0) x /= pr[j], num ^= 1;
                long long all = 0;
                if(num == 1) {
                    c[j][0] ++;
                    ans += 1ll * pr[j] * (n - c[j][1]);
                    all -= 1ll * pr[j] * c[j][1];
                    alla += pr[j];
                }
            }            
            ans += allb;
            a[id] = y;
        }
        if(opt == 2) {
            int x = b[id];
            while(x != 1) {
                int j = mi[x];
                bool num = 0;
                while(x % pr[j] == 0) x /= pr[j], num ^= 1;
                long long all = 0;
                if(num == 1) {
                    c[j][1] --;
                    ans -= 1ll * pr[j] * (n - c[j][0]);
                    all += 1ll * pr[j] * c[j][0];
                    allb -= pr[j];
                }
                ans -= alla;
            }
            x = y;
            while(x != 1) {
                int j = mi[x];
                bool num = 0;
                while(x % pr[j] == 0) x /= pr[j], num ^= 1;
                long long all = 0;
                if(num == 1) {
                    c[j][1] ++;
                    ans += 1ll * pr[j] * (n - c[j][0]);
                    all -= 1ll * pr[j] * c[j][0];
                    allb += pr[j];
                }
                ans += alla;
            }            
            b[id] = y;
        }
        printf("%lld\n", ans);
    }
}
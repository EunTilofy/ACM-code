#include<bits/stdc++.h>
using namespace std;
int n, k, a[5005];
char s[5005];
int opt[5005][2], tot;

int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);
    for(int i = 1; i <= n; ++i) a[i] = (s[i] == '(' ? 1 : -1);
    int now_p, last_opt = 0;

    for(int _ = 1; _<= n; ++_) {
        now_p = 0;
        for(int i = 1; i <= n; ++i) {
            if(now_p == 0 && a[i] == -1) {
                ++tot;
                opt[tot][0] = i;
            }
            if(now_p == -1 && a[i] == 1) {
                opt[tot][1] = i;
            }
            now_p += a[i];
        }
        for(int i = last_opt + 1; i <= tot; ++i) {
            int l = opt[i][0], r = opt[i][1];
            for(int j = l; j < r - j + l; ++j) swap(a[j], a[r - j + l]);
        }
        last_opt = tot;
        now_p = 0;
        for(int i = 1; i <= n; ++i) {
            if(now_p == k && a[i] == 1) {
                ++tot;
                opt[tot][0] = i;
            }
            if(now_p == k + 1 && a[i] == -1) {
                opt[tot][1] = i;
            }
            now_p += a[i];
        }
        for(int i = last_opt + 1; i <= tot; ++i) {
            int l = opt[i][0], r = opt[i][1];
            for(int j = l; j < r - j + l; ++j) swap(a[j], a[r - j + l]);
        }
        last_opt = tot;
    }
    printf("%d\n", tot);
    for(int i = 1; i <= tot; ++i) {
        printf("%d %d\n", opt[i][0], opt[i][1]);
    }
    return 0;
}
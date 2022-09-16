#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int T = 1, inf = 100000;
    printf("%d\n", T);
    for(int o = 1; o <= T; ++o) {
        int n = inf;
        printf("%d\n", n);
        for(int i = 2; i <= n; ++i) {
            int x = rand() % (i - 1) + 1;
            printf("%d %d\n", i, x);
        }
        int q = inf, res = 0;
        printf("%d\n", q);
        for(int i = 1; i <= q; ++i) {
            // printf("i = %d\n", i);
            int tp = rand() % 2 + 1;
            // printf("%d ", tp);
            if(tp == 1 || !res) {
                ++res;
                int l = rand() % n + 1, r = rand() % (n - l + 1) + l;
                printf("1 %d %d %d\n", res, l, r);
            } else {
                printf("3 ");
                int x = rand() % n + 1;
                printf("%d ", x);
                int nm = rand() % res + 1;
                printf("%d ", min(10, nm));
                for(int j = 1; j <= min(10, nm); ++j) printf("%d ", j);
                puts("");
            }
        }
    }
    return 0;
}
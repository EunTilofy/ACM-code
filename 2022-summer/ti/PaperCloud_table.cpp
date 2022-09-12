#include <cstdio>
#include <cstring>
const int N = 105, M = 5005;
int n, m, p[N], q, l[N], i, j, k, f, e;
char s[N], t[N][M];
inline void ph() {
    putchar('+');
    for (int i = 1; i <= m; putchar('+'), ++i)
        for (int j = 1; j <= p[i]; ++j) putchar('-');
    puts("");
}
int main() {
    scanf("%d%d%s", &n, &m, s + 1);
    for (i = 1; i <= n; ++i) {
        scanf("%s", t[i] + 1), l[i] = strlen(t[i] + 1);
        for (q = 0, j = 1, k = 1; j <= l[i]; ++j) t[i][j] != ',' ? ++q : (q = 0, ++k), q > p[k] && (p[k] = q);
    }
    ph();
    for (i = 1; i <= n; ++i) {
        putchar('|');
        for (e = 0, j = 1; j <= m; ++j) {
            for (f = e + 1, e = f; e <= l[i] && t[i][e] != ','; ++e)
                ;
            if (s[j] == 'L') {
                for (k = f; k < e; ++k) putchar(t[i][k]);
                for (k = 1; k <= p[j] - e + f; ++k) putchar(' ');
            } else if (s[j] == 'R') {
                for (k = 1; k <= p[j] - e + f; ++k) putchar(' ');
                for (k = f; k < e; ++k) putchar(t[i][k]);
            } else {
                for (k = 1; k <= p[j] - e + f >> 1; ++k) putchar(' ');
                for (k = f; k < e; ++k) putchar(t[i][k]);
                for (k = 1; k <= p[j] - e + f - (p[j] - e + f >> 1); ++k) putchar(' ');
            }
            putchar('|');
        }
        puts("");
        ph();
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

bool o[1<<18][2];
int a[1<<18][2];

int cal(int i, int j) {
    return 2 * ((2 - i) * 3 + 2 - j);
}

int dfs(int x, int _) {
    if(o[x][_]) return a[x][_];
    int xx = x, num = 0;
    int tmp[3][3];
    for(int i = 2; ~i; --i) for(int j = 2; ~j; --j) {
        tmp[i][j] = xx % 4;
        xx >>= 2;
        num += (tmp[i][j] != 0);
    }
    // printf("num = %d\n", num);
    if(num == 9) {
        int t1 = 0, t2 = 0;
        for(int i = 0; i < 3; ++i) {
            if(tmp[i][0] == tmp[i][1] && tmp[i][0] == tmp[i][2]) {
                if(tmp[i][0] == 1) ++t1;
                else ++t2;
            }
            if(tmp[0][i] == tmp[1][i] && tmp[0][i] == tmp[2][i]) {
                if(tmp[0][i] == 1) ++t1;
                else ++t2;
            }
        }
        if(tmp[0][0] == tmp[1][1] && tmp[1][1] == tmp[2][2]) {
            if(tmp[0][0] == 1) ++t1;
            else ++t2;
        }
        if(tmp[0][2] == tmp[1][1] && tmp[1][1] == tmp[2][0]) {
            if(tmp[1][1] == 1) ++t1;
            else ++t2;
        }
        return t1 - t2;
    }

    if(_ == 0) { //Bob min
        a[x][_] = 8;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) if(tmp[i][j] == 0) {
                a[x][_] = min(a[x][_], dfs(x | (2 << cal(i, j)), _^1));
            }
        }
    }
    else { // Alice max
        a[x][_] = -8;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) if(tmp[i][j] == 0) {
                a[x][_] = max(a[x][_], dfs(x | (1 << cal(i, j)), _^1));
            }
        }
    }
    o[x][_] = 1; return a[x][_];
}

char s[5];
int get(char c) {
    if(c == '.') return 0;
    if(c == 'O') return 1; // Alice
    return 2; // Bob
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int x;
        scanf("%d", &x);
        int S = 0;
        for(int i = 0; i < 3; ++i) {
            scanf("%s", s);
            for(int j = 0; j < 3; ++j) S = (S << 2) | get(s[j]);
        }
        printf("%d\n", dfs(S, x));
    }
    return 0;
}

/*
2
0
.OO
X.O
OXO
1
XXX
XXX
XXX

*/
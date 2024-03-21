#include<bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
bool mk[MN];
int pr[MN], tot;
void init() {
    mk[1] = 1;
    for(int i = 2; i < MN; ++i) {
        if(!mk[i]) {
            pr[++tot] = i;
        }
        for(int j = 1; j <= tot; ++j) {
            if(1ll * pr[j] * i >= MN) break;
            mk[pr[j] * i] = 1;
            if(i % pr[j] == 0) break;
        }
    }
}

int a[MN], f[MN][4];
void Min(int &x, int y) {x = min(x, y);}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();

    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    
    // 0 - yuan
    // 1 - 1
    // 2 - jishu (not 1)
    // 3 - oushu 

    f[1][0] = 0;
    f[1][1] = (a[1] != 1);
    f[1][2] = 1;
    f[1][3] = 1;

    for(int i = 2; i <= n; ++i) {
        f[i][0] = f[i][1] = f[i][2] = f[i][3] = i;
        // yuan
        if(!mk[a[i-1]+a[i]]) Min(f[i][0], f[i-1][0]);
        if(!mk[1+a[i]]) Min(f[i][0], f[i-1][1]);
        if(a[i]%2==0) Min(f[i][0], f[i-1][2]);
        if(a[i]%2==1) Min(f[i][0], f[i-1][3]);
        // 1
        if(!mk[1+a[i-1]]) Min(f[i][1], f[i-1][0]+(a[i]!=1));
                          Min(f[i][1], f[i-1][1]+(a[i]!=1));
                          Min(f[i][1], f[i-1][3]+(a[i]!=1));
        // jishu not 1 (need oushu)
        if(a[i-1]%2==0) Min(f[i][2], f[i-1][0]+1);
                        Min(f[i][2], f[i-1][3]+1);
        // oushu (need jishu)
        if(a[i-1]%2==1) Min(f[i][3], f[i-1][0]+1);
                        Min(f[i][3], f[i-1][1]+1);
                        Min(f[i][3], f[i-1][2]+1);
    }

    // for(int i = 1; i <= n; ++i) {
    //     cout << f[i][0] << " " << f[i][1] << " " << f[i][2] << " " << f[i][3] << "\n";
    // }

    cout << min(min(f[n][0], f[n][1]), min(f[n][2], f[n][3]));
    return 0;
}

/*
6
1 5 1 4 4 1
9
30 6 7 12 15 8 20 17 14
*/
#include<bits/stdc++.h>
using namespace std;

bool tmp[6][6];
int all, x[6], y[6];

bool vis[3][1<<26], ans[3][1<<26];


bool chk(int xx, int yy) {
    for(int i = 1; i <= all; ++i) {
        bool _ = 1;
        for(int j = 1; j <= all; ++j) if(i != j) {
            int xxx = xx + (x[j] - x[i]);
            int yyy = yy + (y[j] - y[i]);
            if(!(xxx >= 0 && xxx <= 5 && yyy >= 0 && yyy <= 5 && tmp[xxx][yyy])) {
                _ = 0;
                break;
            }
        }
        if(_) return 1;
    }
    return 0;
}

bool dfs(int nm) {
    long long val = 0;
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            val += ((tmp[i][j]*(1ll)) << (i*5+j));
        }
    }
    if(vis[nm%3][val]) return ans[nm%3][val];
    if(nm % 3 == 2) {
        // if win
        for(int i = 0; i < 5; ++i)
            for(int j = 0; j < 5; ++j) {
                if(!tmp[i][j] && chk(i, j)) {
                    vis[nm%3][val] = 1;
                    return ans[nm%3][val] = 1;
                }
            }
        bool fl = 0;
        for(int i = 0; i < 5; ++i) {
            for(int j = 0; j < 5; ++j) {
                if(!tmp[i][j]) {
                    tmp[i][j] = 1;
                    fl |= (dfs(nm + 1) == 0);
                    tmp[i][j] = 0;
                    if(fl) break;
                }
            }
            if(fl) break;
        }
        vis[nm%3][val] = 1;
        return ans[nm%3][val] = fl;
    } else {
        bool fl = 0;
        for(int i = 0; i < 5; ++i) {
            for(int j = 0; j < 5; ++j) {
                if(!tmp[i][j] && !chk(i, j)) {
                    tmp[i][j] = 1;
                    fl |= (dfs(nm + 1) == 0);
                    tmp[i][j] = 0;
                    if(fl) break;
                }
            }
            if(fl) break;
        }
        vis[nm%3][val] = 1;
        return ans[nm%3][val] = fl;
    }
}

void solve() {
    // memset(vis, 0, sizeof vis);
    // memset(ans, 0, sizeof ans);
    string a[5];
    for(int i = 0; i < 5; ++i) cin >> a[i];
    all = 0;
    for(int i = 0; i < 5; ++i) for(int j = 0; j < 5; ++j) {
        if(a[i][j] == 'o') {
            x[++all] = i;
            y[all] = j;
        }
    }

    string str[] = {"Away", "Far"};

    if(all == 1) {
        cout << str[0] << "\n";
        return ;
    } if (all == 2) {
        cout << str[1] << "\n";
        return ;
    } if(all == 3) {
        cout << str[0] << "\n";
        return ;
    } 
    if(all == 4) {
        bool fl = 0;

        tmp[2][1] = tmp[2][2] = tmp[2][3] = 1;
        fl |= (chk(1, 1) || chk(1, 3) || chk(3, 1) || chk(3, 3) || chk(1, 2) || chk(3, 2));
        tmp[2][1] = tmp[2][2] = tmp[2][3] = 0;
        tmp[1][2] = tmp[2][2] = tmp[3][2] = 1;
        fl |= (chk(1, 1) || chk(3, 1) || chk(1, 3) || chk(3, 3) || chk(2, 1) || chk(2, 3));
        tmp[1][2] = tmp[2][2] = tmp[3][2] = 0;
        
        tmp[1][1] = tmp[1][2] = tmp[2][2] = 1; fl |= chk(2, 3);
        tmp[1][1] = tmp[1][2] = tmp[2][2] = 0;

        tmp[1][2] = tmp[1][3] = tmp[2][1] = 1; fl |= chk(2, 2);
        tmp[1][2] = tmp[1][3] = tmp[2][1] = 0;

        tmp[1][1] = tmp[2][1] = tmp[2][2] = 1; fl |= chk(3, 2);
        tmp[1][1] = tmp[2][1] = tmp[2][2] = 0;

        tmp[2][1] = tmp[3][1] = tmp[1][2] = 1; fl |= chk(2, 2);
        tmp[2][1] = tmp[3][1] = tmp[1][2] = 0;

        cout << str[fl] << "\n";
        return ;
    }

    // for(int i = 0; i < 5; ++i) for(int j = 0; j < 5; ++j) tmp[i][j] = 0;
    // cout << str[dfs(0)] << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}

/*



.oo..
.oo..
.....
.....
.....

.....
.....
.....
.oooo
.....

.....
ooo..
..o..
.....
.....

.o...
.oo..
.o...
.....
.....

.....
.....
..oo.
.oo..
.....


*/
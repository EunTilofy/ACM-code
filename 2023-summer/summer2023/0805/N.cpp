#include<bits/stdc++.h>
using namespace std;
void ok() {
    cout << "Possible\n";
    return;
}
void no() {
    cout << "Impossible\n";
    return;
}
int cal(int x, int y, int n) {
    if(x == 1 && y == 1) return 2;
    if(x == 1 && y == n) return 2;
    if(x == n && y == 1) return 2;
    if(x == n && y == n) return 2;
    if(x == 1 || x == n || y == 1 || y == n) return 3;
    return 4;
}
bool check(int x, int y, int n, int m) {
    int num3 = 0, num4 = 0, num2 = 0;
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= n; j ++) {
        if((x + i) % 2 == (y + j) % 2) {
            int xx = i;
            int yy = j;
            int z = cal(xx, yy, n);
            if(z == 3) ++num3;
            if(z == 4) ++num4;
            if(z == 2) ++num2;
        }
    }
    int all = 2 * n * (n - 1);
    bool fd = 0;
    int nn3, nn4, nn2;

    // cout << all << " " << m << "\n";
    // cout << num2 << " " << num3 << " " << num4 << "\n";

    for(int i = 0; i <= num3; ++i) {
        int xx = all - m;
        if(3 * i <= xx) {
            int yy = xx - 3 * i;
            for(int j = 0; j <= num2; ++j) if(j * 2 <= yy){
                int zz = yy - j * 2;
                if(zz%4==0&&zz/4<=num4) {
                    fd = 1;
                    nn3 = i;
                    nn2 = j;
                    nn4 = zz/4;
                    break;
                }
                if(fd == 1) break;
            }
        }
        if(fd == 1) break;
    }
    if(fd) {
        ok();
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if((i + x) % 2 == (j + y) % 2) {
                    int z = cal(i, j, n);
                    if(z == 2) {
                        if(nn2>0) {
                            --nn2;
                            cout << "B";
                        }
                        else cout << "R";
                    }
                    if(z == 3) {
                        if(nn3>0) {
                            --nn3;
                            cout << "B";
                        }
                        else cout << "R";
                    }
                    if(z == 4) {
                        if(nn4>0) {
                            --nn4;
                            cout << "B";
                        }
                        else cout << "R";
                    }
                }
                else cout << "B";
            }
            cout << "\n";
        }
        return 1;
    }
    return 0;
}
void solve() {
    int n, m;
    cin >> n >> m;
    if(n == 1) {
        if(m == 0) {
            ok();
            cout << "B\n";
        } else {
            no();
        }
        return;
    }
    if(n == 3 && m == 5) {
        ok();
        cout << "RBB\nBBB\nBRB\n";
        return;
    }
    if(n == 3 && m == 7) {
        ok();
        cout << "BRB\nBBB\nRBR\n";
        return;
    }
    if(!check(1, 1, n, m)) {
        if(!check(1, 0, n, m)) {
            no();
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}

/*
Impossible
Possible
BBBB
BBBB
BBBB
BBBR
Possible
BBBB
BBBB
BBBB
BRBB
Possible
RBBB
BBBB
BBBB
BBBR
Possible
BBBB
BBBB
BBBB
BRBR
Possible
BBBB
BBBB
RBBB
BRBB
Possible
RBBB
BBBB
BBBB
BRBR
Possible
BBBB
BBBB
RBBB
BRBR
Possible
BBBB
BBBR
RBBB
BRBB
Possible
RBBB
BBBB
RBBB
BRBR
Possible
BBBB
BBBR
RBBB
BRBR
Possible
BBRB
BBBR
RBBB
BRBB
Possible
RBBB
BBBR
RBBB
BRBR
Possible
BBRB
BBBR
RBBB
BRBR
Possible
BBBB
BBBR
RBRB
BRBR
Possible
RBRB
BBBR
RBBB
BRBR
*/
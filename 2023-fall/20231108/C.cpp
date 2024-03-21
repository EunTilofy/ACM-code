#include<bits/stdc++.h>
using namespace std;

string s; int k;
int d[40];

__int128 f[36][19][2], pw[36];
bool g[36][19][2];
void print(__int128 t) {
    if(t < 10) cout << (int)t;
    else print(t/10), cout << (int)(t%10);
}
void solve2() {
    memset(g, 0, sizeof g);
    g[0][0][0] = 1; f[0][0][0] = 0;
    for(int i = 1; i <= 35; ++i) for(int j = 0; j <= k; ++j) {
        // g[i][j][1]
        g[i][j][1] = ((j>0)&&d[i-1]>0&&g[i-1][j-1][0]) || ((j>0)&&g[i-1][j-1][1]);
        if(g[i][j][1]) {
            if((j>0)&&d[i-1]>0&&g[i-1][j-1][0]) {
                f[i][j][1] = pw[i]*(10-d[i-1])+f[i-1][j-1][0];
                if(j>0&&g[i-1][j-1][1]) {
                    f[i][j][1] = min(f[i][j][1], pw[i]*(10-d[i-1]-1)+f[i-1][j-1][1]);
                }
            } else {
                f[i][j][1] = pw[i]*(10-d[i-1]-1)+f[i-1][j-1][1];
            }
        }
        // g[i][j][0]
        g[i][j][0] = g[i-1][j][0] || (g[i-1][j][1]&&d[i-1]<9);
        if(g[i][j][0]) {
            if(g[i-1][j][0]) {
                f[i][j][0] = f[i-1][j][0];
                if(g[i-1][j][1]&&d[i-1]<9) {
                    f[i][j][0] = min(f[i][j][0], f[i-1][j][1]);
                }
            } else {
                f[i][j][0] = f[i-1][j][1];
            }
        }
        // cerr << i << " " << j << " ";print(f[i][j][0]);cerr << " " ;print(f[i][j][1]); cerr << " " << g[i][j][0] << " " << g[i][j][1] << "\n";
    }
    assert(g[35][k][0]);
    print(f[35][k][0]);
    cout << "\n";
}


void solve() {
    memset(d, 0, sizeof d);
    cin >> s >> k;
    for(int j = s.size()-1, i = 0; j >= 0; --j, ++i) {
        d[i] = s[j] - '0';
    }
    if(k == 0) {
        vector<int> _;
        for(int i = 0; i < 40; ++i) {
            if(d[i] == 9) _.push_back(0);
            else {_.push_back(1); break;}
        }
        reverse(_.begin(), _.end());
        for(auto dig : _) cout << dig; cout << "\n";
        return ;
    }
    vector<int> _;
    int now = 0, pre = 0;
    for(int i = 0; i < 40; ++i) {
        // carry ? 
        if(now == k) break;
        if(d[i] + pre > 0) {
            int j = i;
            while(d[j+1] == 9) ++j;
            if(j-i+1+now<=k) {
                for(int ii = i; ii <= j; ++ii) {
                    _.push_back(10-d[ii]-pre);
                    pre = 1;
                }
                now+=(j-i+1);
                i = j;
            } else if(j-i+1+now>k) {
                solve2();
                return;
            } else {
                _.push_back(0);
                pre = 0;
            }
        } else {
            _.push_back(0);
            pre = 0;
        }
        if(now == k) break;
    }
    while(_.back() == 0) _.pop_back();
    reverse(_.begin(), _.end());
    for(auto dig : _) cout << dig; cout << "\n";
    return ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    pw[1] = 1;
    for(int i = 2; i < 35; ++i) pw[i] = pw[i-1] * 10;
    int T;
    cin >> T;
    while(T--) solve();
}

/*
4
12345678 0
12345678 5
12345678 18
990099 5

1
54322
999999999987654322
9910
*/
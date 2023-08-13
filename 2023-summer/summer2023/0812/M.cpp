#include<bits/stdc++.h>
using namespace std;

void pr(char c, int num) {
    for(int i = 1; i <= num; ++i) cout << c;
}

vector<int> G[20000];
int n, m;
int ID(int x, int y) {
    return (x - 1) * m + y;
}
void add(int x, int y) {
    G[x].push_back(y);
    G[y].push_back(x);
}
void solU(int x, int y1, int y2) {
    if(y1 < y2) {
    if(x % 2 == 0) {
        for(int i = 1; i <= x/2; ++i) {
            pr('L', y1-1);
            pr('U', 1);
            pr('R', y1-1);
            pr('D', 1-(i==x/2));
        }
        pr('R', 1);
        for(int i = 1; i <= x/2; ++i) {
            pr('R', m-y2);
            pr('D', 1);
            pr('L', m-y2);
            pr('D', 1-(i==x/2));
        }
        pr('D', 1);
    }
    else {
        pr('L', y1-1);
        for(int i = 1; i <= m/2; ++i) {
            pr('U', x-1);
            pr('R', 1);
            pr('D', x-1);
            pr('R', 1-(i==m/2));
        }
    }
    }
}

void solve() {
    int x, y;
    cin >> n >> m >> x >> y;
    if(n==1) {
        if(y == 1) {
            pr('R', m-1);
        } else if(y == m) {
            pr('L', m-1);
        }
        else cout << "IMPOSSIBLIE";
        return ;
    }
    if(m==1) {
        if(x==1) {
            pr('D', n-1);
        } else if(x==n) {
            pr('U', n-1);
        }else cout << "IMPOSSIBLE";
        return ;
    }
    if(x != 1) {
        if(y==m) solU(x, y, y-1);
        else solU(x, y, y+1);
    }
    if(x != n) {
        if(y == m) solD(x, y, y-1);
        else solD(x, y, y+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        solve();
        if(T) cout << "\n";
    }
}
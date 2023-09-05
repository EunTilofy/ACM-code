#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int f[N][N], g[N][N];

struct node {
    int x, y;
};

void gameover(int Mv) {
    cout << "Game over with " << Mv <<".\n";
    exit(0);
}

void get(int val, int city, int now) {
    cout << "Get "<<val<<" at "<<city<<" on day "<<now<<".\n";
}

int main() {
    int n, m, me, d;
    cin >> n >> m >> me >> d;
    vector<node> a;
    int Mv, Mx;
    cin >> Mx >> Mv;
    for(int i = 1, x, y; i < n; ++i)  {
        cin >> x >> y;
        a.push_back({x, y});
    }
    
    memset(f, 0x3f, sizeof f), memset(g, 0x3f, sizeof g);
    for(int i = 0; i < m; ++i) f[i][i] = g[i][i] = 0;
    for(int i = 1, x, y, z; i <= me; ++i) {
        cin >> x >> y >> z;
        if(x == y) continue;
        f[x][y] = f[y][x] = min(f[x][y], z);
        g[x][y] = g[y][x] = 1;
    }
    for(int k = 0; k < m; ++k) for(int x = 0; x < m; ++x) for(int y = 0; y < m; ++y) {
        if(f[x][y] > f[x][k] + f[k][y]) {
            f[x][y] = f[x][k] + f[k][y];
            g[x][y] = g[x][k] + g[k][y];
        } else if(f[x][y] == f[x][k] + f[k][y]) {
            g[x][y] = min(g[x][y], g[x][k] + g[k][y]);
        }
    }
    
    int now = 0, ban = -1;
    while(1) {
        int val = -1, id = -1;
        if(!a.size()) {
//             now++;now = min(now, d);
            if(!now) now++;
            cout << "WIN on day "<<now<<" with "<<Mv<<"!\n";
            return 0;
        }
        for(auto[x, y] : a) if(x != ban) {
            if(y <= Mv) {
                if(val == -1) val = y, id = x;
                else if(val < y || (val == y && (f[Mx][x] < f[Mx][id] || (f[Mx][x] == f[Mx][id] && (g[Mx][x] < g[Mx][id] || (g[Mx][x] == g[Mx][id] && x < id)))))) {
                    val = y, id = x;
                }
            }
        }
        if(val == -1) {
            now++, now = min(now, d);
            cout << "Lose on day "<<now<<" with "<<Mv<<".\n";
            break;
        }
//         if(id == 3) {
//             cout << Mv << "!!!!\n";
//             for(auto[x, y] : a) {
//                 cout << x << " " << y << "\n";
//             }
//         }
        ban = -1;
        now += f[Mx][id];
        if(now > d) {
            cout << "Game over with " << Mv <<".\n";
            break;
        } else {
            if(Mx != id) cout << "Move from "<<Mx<<" to "<<id<<".\n";
            Mx = id;
            now++;
            if(now <= d) { 
                get(val, id, now), Mv += val;
                while(1) {
                    vector<node> b;
                    int sum = 0, flg = 0;
                    for(auto[x, y] : a) {
                        if(x == id && y <= Mv) {
                            sum += y;
                        } else {
                            if(x == id) flg = 1;
                            b.push_back({x, y});
                        }
                    }
                    sum -= val;
                    if(sum) b.push_back({id, sum});
                    a = b;
                    if(!flg && sum && sum <= Mv) {
                        now++;
                        if(now <= d) {
                            get(sum, id, now);
                            val = sum;
                            Mv += sum;
                        }
                        else gameover(Mv);
                    } else {ban = id; break;}
                }
            } else {
                gameover(Mv);
            }
        }
    }
    return 0;
}
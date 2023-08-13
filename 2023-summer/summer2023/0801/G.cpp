#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int h, w, vs[N][N];
int dx[4] ={0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
string s[N];
struct node {
    int mx, nx, my, ny;
} a[N * N];

int res = 0;
void dfs(int x, int y) {
    // cerr << "!!" << x << " " << y << "\n";
    vs[x][y] = res;
    a[res].mx = max(a[res].mx, x);
    a[res].nx = min(a[res].nx, x);
    a[res].my = max(a[res].my, y);
    a[res].ny = min(a[res].ny, y);
    for(int i = 0; i < 4; ++i) {
        int xx = x + dx[i], yy = y + dy[i];
        // cerr << xx << " " << yy << "!!!\n";
        if(xx < 0 || xx >= h || yy < 0 || yy >= w || s[xx][yy] != '.' || vs[xx][yy]) continue;
        dfs(xx, yy);
    }
}

const int MN = 2e6+10;
#define T 2000005
#define S 2000004
struct edge{
    long long to, w, nex;
}e[MN * 10];int en = 1;int cur[MN], hr[MN];
void ins(int x, int y, int w) {
    // cerr << x << " " << y << " " << w << endl;
    e[++en]=(edge){y, w, hr[x]}; hr[x] = en;
    e[++en]=(edge){x, 0, hr[y]}; hr[y] = en;
} 
int d[MN], q[MN], top;
#define ID(x,y) ((x)*w+(y))
bool bfs() {
    memset(d, 0, sizeof d);
    int i,j;
    for(d[q[i=top=1]=S]=1;i<=top;++i) {
        for(j=hr[q[i]];j;j=e[j].nex)
            if(e[j].w&&!d[e[j].to])
                d[q[++top]=e[j].to]=d[q[i]]+1;
    }
    return d[T];
}
long long Dfs(int x, long long f) {
    if(x==T) return f;
    long long used=0;
    for(int &i=cur[x];i;i=e[i].nex)
        if(d[e[i].to]==d[x]+1&&e[i].w) {
            long long tmp=Dfs(e[i].to,min(f-used,e[i].w));
            e[i].w-=tmp;e[i^1].w+=tmp;used+=tmp;
            if(used==f) return used;
        }
    return d[x]=-1,used;
}
const int inf = 0x3f3f3f3f;
int dinic() {
    long long mf=0;
    while(bfs()) {
        memcpy(cur, hr, sizeof cur);
        mf+=Dfs(S,inf);
    }
    return mf;
}

int RES = -1;
bool pd(int x, int y) {
    if(x<0||y<0||x==h||y==w) return 0;
    if(vs[x][y] == RES) {
        return 1;
    }
    if(s[x][y] == '#') return 1;
    return 0;
}
bool PD(int x, int y) {
    // cerr << x << " " << y << endl;
    if(s[x][y] != '#') return 0;
    if(x==0||x==h-1||y==0||y==w-1) return 1;
    for(int i = -1; i <= 1; ++i) for(int j = -1; j <= 1; ++j) {
        if(i == 0 && j == 0) continue;
        if(s[x+i][y+j]=='.' && vs[x+i][y+j] != RES) return 1;
    }
    return 0;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> h >> w;
    for(int i = 0; i < h; ++i) cin >> s[i];
    for(int i = 0; i < h; ++i) for(int j = 0; j < w; ++j) if(!vs[i][j] && s[i][j] == '.') {
        // cerr << i << " " << j << "\n";
        ++res, a[res].mx = a[res].my = 0, a[res].nx = a[res].ny = 1e9, dfs(i, j);
    }
    // cerr << "!!\n";
    
    int flg = 0;
    for(int i = 1; i <= res; ++i) {
        if(a[i].mx == h - 1 || a[i].nx == 0 || a[i].my == w - 1 || a[i].ny == 0) continue;
        assert(!flg);
        RES = i;
        // cerr << i << "\n";
        // cerr << a[i].mx << " " << a[i].nx << " " << a[i].my << " " << a[i].ny << "\n";
        // a[i].mx++, a[i].my++, a[i].nx--, a[i].ny--;
        // for(int j = 0; j < h; ++j) {
        //     for(int k = 0; k < w; ++k) {
        //         if(j == a[i].mx || j == a[i].nx) {
        //             if(k >= a[i].ny && k <= a[i].my) cout << "#";
        //             else cout << ".";
        //         } else if(k == a[i].ny || k == a[i].my) {
        //             if(j >= a[i].nx && j <= a[i].mx) cout << "#";
        //             else cout << ".";
        //         } else cout << ".";
        //     }
        //     cout << "\n";
        // }
        flg = 1;
    }
    int _ = h * w;
    for(int i = 0; i < h; ++i) for(int j = 0; j < w; ++j) {
        if(pd(i,j)) {
            // cerr << i << " " << j << endl;
            if(vs[i][j] == RES) {
                ins(ID(i,j), ID(i,j)+_, inf);
                // cerr << "NEI " << i << " " << j << endl;
            }
            else ins(ID(i,j), ID(i,j)+_, 1);
            if(PD(i, j)) {
                // cerr << i << " " << j << endl;
                ins(ID(i,j)+_, T, inf);
                // cerr << "WAI " << i << " " << j << endl; 
            }
            for(int ii = -1; ii <= 1; ++ii) for(int jj = -1; jj <=1; ++jj) {
                if(ii == 0 && jj == 0) continue;
                if(pd(i+ii, j+jj)) {
                    ins(ID(i,j)+_, ID(i+ii,j+jj), inf);
                    // cerr << "LIN " << i << " " << j << " " << i + ii << " " << j + jj << endl;
                }
            }
        } if(vs[i][j] == RES) {
            ins(S, ID(i,j), inf);
        }
    }
    int MF = dinic();
    // cerr << MF << endl;
    for(int i = 0; i < h; ++i) for(int j = 0; j < w; ++j) {
        bool fl = 0;
        for(int k=hr[ID(i,j)]; k; k = e[k].nex) {
            if(e[k].to == ID(i,j)+_) {
                if(e[k].w == 0) fl = 1; 
            }
        }
        if(fl) cout << "#";
        else cout << ".";
        if(j == w - 1) cout << endl;
    }
    return 0;
}
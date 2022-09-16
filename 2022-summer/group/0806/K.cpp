#include<bits/stdc++.h>
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define mod 998244353
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}

struct node {
    int x, id;
} a[20];

bool cmp(node xx, node yy) {
    return xx.x < yy.x;
}

int b[4][4], c[4][4];
int mx = 0, d[4][4], v[4][4];

void fz() {
    for(int i = 0; i < 4; ++i) for(int j = 0; j < 4; ++j) d[i][j] = c[i][j], v[i][j] = b[i][j];
}

void dfs(int dep) {
    if(dep > 12) {
        int res = 0;
        for(int i = 0; i < 4; ++i) {
            // printf("%d %d %d\n", c[i][1], c[i][2], c[i][3]);
            if(b[i][1] + b[i][2] > b[i][3]) res++;
        }
        // exit(0);
        if(res > mx) mx = res, fz();
        return ;
    }
    // printf("%d %d %d\n", dep, a[dep].x, a[dep].id);
    for(int i = 0; i < 4; ++i) {
        if(!b[i][0]) {
            // printf("!%d %d\n", dep, i);
            b[i][0]++, b[i][1] = a[dep].x, c[i][1] = a[dep].id;
            dfs(dep + 1);
            b[i][0]--;
            break;
        } else if(b[i][0] < 3){
            b[i][0]++;
            int nw = b[i][0];
            // if(nw == 3) puts("?????");
            b[i][nw] = a[dep].x, c[i][nw] = a[dep].id;
            dfs(dep + 1);
            b[i][0]--;
        }
    }
}

void solve(int o) {
    mx = 0;
    for(int i = 0; i < 4; ++i) for(int j = 0; j < 4; ++j) c[i][j] = d[i][j] = v[i][j] = b[i][j] = 0;
    for(int i = 1; i <= 12; ++i) a[i].x = read(), a[i].id = i;
    sort(a + 1, a + 1 + 12, cmp);
    dfs(1);
    printf("Case #%d: %d\n", o, mx);
    for(int i = 0; i < 4; ++i) {
        if(v[i][1] + v[i][2] > v[i][3]) {
            printf("%d %d %d\n", v[i][1], v[i][2], v[i][3]);
        }
    }
}

int main() {
    int T = read();
    for(int o = 1; o <= T; ++o) {
        solve(o);
    }
    return 0;
}

/*
Case #1: 4
1 1 1
4 3 2
1 1 1
6 7 5
Case #2: 3
6 5 4
10 12 11
9 8 7
Case #3: 0
Case #4: 2
83 121 72
234 159 201
Case #5: 1
1024 1281 512

*/
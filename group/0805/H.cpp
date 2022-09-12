#include<bits/stdc++.h>
#define ll long long
#define db double
#define LL __int128
#define DB __float128
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define mod 998244353
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0'; ch = getchar();}
    return x * f;
}
const int MN = 1e5 + 5;
int val[MN], a[MN][2], cnt;
int ans;
// void sol(int x) {
//     for(int i = 1; i <= cnt; ++i) {
//         ans += a[i][1] / 2;
//         a[i][1] %= 2;
//     }
//     int ccnt = 0;
//     for(int i = 1; i <= cnt; ++i) if(a[i][1]) b[++ccnt] = a[i][0];
//     if(ccnt == 0) {cnt = 0; return;}
//     int l = 1, r = 1;
//     while(r + 1 <= ccnt && (b[r + 1] == b[1] || b[r + 1] == x - b[1])) ++r;
//     int nn = ccnt + 1;
//     while(nn - 1 > r && (b[nn - 1] == b[1] || b[nn - 1] == x - b[1])) --nn;
//     cnt = 0;
//     a[++cnt][0] = b[1]; a[cnt][1] = r - l + 1 + ccnt - nn + 1;
//     for(int i = r + 1; i < nn; ++i) {
//         int j = i;
//         while(j + 1 < nn && (b[j + 1] == b[i] || b[j + 1] == x - b[i])) ++j;
//         a[++cnt][0] = b[i]; a[cnt][1] = j - i + 1;
//         i = j;
//     }
// }
int b[MN], ccnt = 0;
int main() {
    int n = read(), x = read();
    for(int i = 1; i <= n; ++i) val[i] = read();
    int l = 1, r = 1;
    while(r + 1 <= n && (val[r + 1] == val[1] || val[r + 1] == x - val[1])) ++r;
    int nn = n + 1;
    while(nn - 1 > r && (val[nn - 1] == val[1] || val[nn - 1] == x - val[1])) --nn;
    a[++cnt][0] = val[1]; a[cnt][1] = r - l + 1 + n - nn + 1;
    for(int i = r + 1; i < nn; ++i) {
        int j = i;
        while(j + 1 < nn && (val[j + 1] == val[i] || val[j + 1] == x - val[i])) ++j;
        a[++cnt][0] = val[i]; a[cnt][1] = j - i + 1;
        i = j;
    }
    for(int i = 1; i <= cnt; ++i) {
        ans += a[i][1] / 2;
        if(a[i][1] % 2 == 1) {
            if(ccnt && (b[ccnt] == a[i][0] || b[ccnt] + a[i][0] == x)) --ccnt, ++ans;
            else b[++ccnt] = a[i][0];
        }
    }
    for(int i = 1; i + i <= ccnt; ++i) {
        if(b[i] == b[ccnt - i + 1] || b[i] + b[ccnt - i + 1] == x) {
            ++ans;
        }
        else break;
    }
    printf("%d\n", ans);
    return 0;
}
#include<bits/stdc++.h>
#define ll long long
//#define int long long
#define db double
#define ld long double
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
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define FOr(i,a,b) for(int i=(a);i>=(b);--i)
#define y1 y11111111111
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
const int MN = 1e6 + 505;
char s[MN];
int nx[MN];
int f[MN][26];
bool yes[MN];
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    scanf("%s", s + 1);
    int len = strlen(s + 1);

    for(int i = 1, j = 0; i <= len; ++i) {
        if(i != 1) {
            while(s[j + 1] != s[i] && j > 0) j = nx[j];
            if(s[j + 1] == s[i]) ++j;
            nx[i] = j;
        }
        if(!yes[j]) {
            int _;
            REP(o, 0, 26) {
                _ = j;
                while(s[_ + 1] != 'a' + o && !yes[_] && _ > 0) _ = nx[_]; 
                if(s[_ + 1] == 'a' + o) f[j][o] = ++_;
                else f[j][o] = f[_][o];
            }
            yes[j] = 1;
        }
    }
    int T = read();
    while(T--) {
        scanf("%s", s + len + 1);
        int tlen = strlen(s + len + 1);
        for(int i = len + 1, j = nx[len]; i <= len + tlen; ++i) {
            while(s[j + 1] != s[i] && !yes[j]) j = nx[j];
            if(s[j + 1] == s[i]) nx[i] = ++j;
            else nx[i] = f[j][s[i] - 'a'];
            j = nx[i];
            // dbg1(j); dbg2(nx[i]);
        }
        REP(i, len + 1, len + tlen + 1) printf("%d ", nx[i]);
        printf("\n"); 
    }
    return 0;
}
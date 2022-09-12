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
const int MN = 1e4 + 4;
int cnt, _[MN];
bool in[MN];
int main() {
    int n;
    scanf("%d", &n);
    printf("? %d", n);
    for(int i = 1; i <= n; ++i) printf(" %d", i);printf("\n");
    fflush(stdout);
    int all;
    scanf("%d", &all);
    srand(time(NULL));
    for(int o = 1; o <= 29; ++o) {
        cnt = 0;
        for(int i = 1; i <= n; ++i) {
            if(in[i] = rand()%2) _[++cnt] = i;
        }
        printf("? %d", cnt);
        for(int i = 1; i <= cnt; ++i) printf(" %d", _[i]);printf("\n");
        fflush(stdout);
        int ans1, ans2;
        scanf("%d", &ans1);
        printf("? %d", n - cnt);
        for(int i = 1; i <= n; ++i) if(!in[i]) printf(" %d", i); printf("\n");
        fflush(stdout);
        scanf("%d", &ans2);
        if((all - ans1 - ans2) % 2 == 1) {
            printf("! NO\n");
            fflush(stdout);
            return 0;
        }
    }
    printf("! YES\n");
    fflush(stdout);
    return 0;
}
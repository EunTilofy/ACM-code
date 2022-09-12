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
const int MN = 1e5 + 5;
int a[MN], b[MN], cnt;
bool mk[1<<21];
int main() {
    int T = read();
    while(T--) {
        int n = read();
        for(int i = 1; i <= n; ++i) mk[a[i] = read()] = 1;
        std::sort(a + 1, a + n + 1);
        bool fl = 1;
        cnt = 0;
        for(int i = n; i > 1; --i) {
            if((a[i] & a[1])!= a[1]) fl = 0;
        }
        if(!fl) puts("-1");
        else {
            for(int i = 1; i <= n; ++i) {
                if(i > 1 && ((a[i - 1] & a[i])!= a[i - 1])) {
                    b[++cnt] = a[1];
                }
                b[++cnt] = a[i];
            }
            printf("%d\n", cnt);
            for(int i = 1; i <= cnt; ++i) {
                printf("%d ", b[i]);
            }
            puts("");
        }
        for(int i = 1; i <= n; ++i) mk[a[i]] = 0;
    }
}
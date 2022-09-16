#include<bits/stdc++.h>
#define ll long long
// #define int long long
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
const int MN = 3e5 + 5;
int sum, ans;
char now[105][20];
int num[105];
std::map<char, int> mp;
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T = read();
    while(T--) {
        int n,k;
        scanf("%d%d", &n, &k);
        mp.clear();
        sum = 0; ans = 0;
        REP(i, 1, n + 1) {
            int user = (i - 1) % k + 1;
            if(i > k) {
                sum -= (mp[now[user][1]] == 5);
                mp[now[user][1]] -= num[user];
                sum += (mp[now[user][1]] == 5);
            }
            scanf("%s%d", now[user] + 1, &num[user]);
            sum -= mp[now[user][1]] == 5;
            mp[now[user][1]] += num[user];
            if(mp[now[user][1]] == 5) ++sum;
            ans += sum;
        }
        printf("%d\n", ans);
    }
    return 0;
}
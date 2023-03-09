#include<bits/stdc++.h>
using namespace std;
int n,q,i,j;
long long x,dp[10000005],ddp[10000005];
struct node {
    long long v,c;
    bool operator<(const node&_)const {
        return c*_.v>_.c*v;
    }
} w[55];
int main() {
    scanf("%d%d",&n,&q);
    for(i=1; i<=n; i++)scanf("%lld%lld",&w[i].v,&w[i].c);
    sort(w+1,w+n+1);
    memset(dp,-1,sizeof(dp)),dp[0]=0;
    for(i=2; i<=n; i++)
        for(j=0; j+w[i].v<10000005; j++)
            if(dp[j]!=-1)dp[j+w[i].v]=max(dp[j+w[i].v],dp[j]+w[i].c);
    for(i=10000004-w[1].v; ~i; --i) {
        if(dp[i+w[1].v]!=-1) dp[i]=max(dp[i+w[1].v]-w[1].c, dp[i]);
    }
    for(int i=0;i<10000005;++i)ddp[i]=dp[i];
    while(q--) {
        scanf("%lld",&x);
        long long ans=-1;
        if(dp[x-(x/w[1].v)*w[1].v]!=-1) ans=dp[x-(x/w[1].v)*w[1].v]+(x/w[1].v)*w[1].c;
        ans=max(ans, -1ll);
        for(i=1; i<=n; i++) {
            long long y=x/w[i].v;
            long long z=0;
            if(i>1) {
                z=y/w[1].v*w[i].v,y%=w[1].v;
            }
            while(y>0&&x-y*w[i].v-z*w[1].v<10000005) {
                if(ddp[x-y*w[i].v-z*w[1].v]!=-1) {
                    ans=max(ans,ddp[x-y*w[i].v-z*w[1].v]+w[i].c*y+w[1].c*z);
                    break;
                }
                y--;
            }
        }
        ans=max(ans,-1ll);
        printf("%lld\n",ans);
    }
    return 0;
}

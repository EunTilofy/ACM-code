#include<bits/stdc++.h>
using namespace std;
const int N=(1 << 20);
int a[N];
class bit{
    int t[N];
    int LOG(int n) {
        return 31 - __builtin_clz(n);
    }
public:
    void ins(int x) {
       // cerr << x <<"ins\n";
        for(;x<N;x+=(x&(-x))) t[x] += 1;
    }
    void del(int x) {
        //cerr << x <<"del\n";
        for(;x<N;x+=(x&(-x))) t[x] -= 1;
    }
    int v(int x) {
        int r = 0;
        for(;x;x-=(x&(-x))) r += t[x];
        return r;
    }
    int query(int x) {
        // cerr << x << "??\n";
        int pos = v(x), now = 0, sum = 0;
        // cerr << pos << "pos\n";
        for(int i = 19; i >= 0; --i) {
            if(sum + t[now + (1 << i)] - pos + 1 >= now + (1 << i) - x + 1) {
                now += (1 << i);
                sum += t[now];
            }
        }
        // cerr << now <<"now\n";
        return now + 1;
    }
}B;
int nxt[N][2];
#define ll long long
ll f[N][2];
int n,k;
int T;
int pos[N];
int dis(int x,int y){
    if(x<=0)x+=n;
    if(x>n)x-=n;
    if(y<=0)y+=n;
    if(y>n)y-=n;
    return min(abs(x-y),n-abs(x-y));
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            pos[a[i]]=i;
        }
        for(int i=1;i<=k;i++){
            B.ins(a[i]);
        }
        int st=B.query(0);
        for(int i=1,j=k,t=1;t<=n;++t){
            nxt[a[i]][0]=B.query(a[i]);
            nxt[a[j]][1]=B.query(a[j]);
       //     cout<<i<<" "<<j<<" "<<nxt[a[i]][0]<<" "<<nxt[a[j]][1]<<endl;
            B.del(a[i]);++i;if(i>n)i=1;
            ++j;if(j>n)j=1;B.ins(a[j]);
         //   cout<<i<<" "<<j<<endl;
        }
        for(int i=1;i<=k;i++){
            B.del(a[i]);
        }
        ll ans=1e18;
        if(st>n)ans=0;
        for(int i=1;i<=n;i++)
            for(int j:{0,1}){
                f[i][j]=1e17;
            }
        
        f[st][0]=dis(1,pos[st]);
        f[st][1]=dis(1,pos[st]-k+1);
       // cout<<st<<endl;
        for(int i=st;i<=n;i++){
                if(nxt[i][0]>n){
                    ans=min(ans,f[i][0]);
                }
                if(nxt[i][1]>n){
                    ans=min(ans,f[i][1]);
                }
                f[nxt[i][0]][0]=min(f[nxt[i][0]][0],f[i][0]+dis(pos[i],pos[nxt[i][0]]));
                f[nxt[i][0]][1]=min(f[nxt[i][0]][1],f[i][0]+dis(pos[i],pos[nxt[i][0]]-k+1));
                f[nxt[i][1]][0]=min(f[nxt[i][1]][0],f[i][1]+dis(pos[i]-k+1,pos[nxt[i][1]]));
                f[nxt[i][1]][1]=min(f[nxt[i][1]][1],f[i][1]+dis(pos[i]-k+1,pos[nxt[i][1]]-k+1));
        }
        cout<<ans<<'\n';
    }
    
}
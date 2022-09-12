#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
#define MN 2005
#define S 0
#define T 205
#define inf 200000000
struct edge{int to,w,nex;}e[MN*T];
int hr[T+5],cnt=1,d[T+5];
int q[T+5],top,ans;
int m,n;
void ins(int f,int t,int w){
    e[++cnt]=edge{t,w,hr[f]};hr[f]=cnt;
    e[++cnt]=edge{f,0,hr[t]};hr[t]=cnt;
}
bool bfs(){
    memset(d,0,sizeof d);
    register int i,j;
    for(d[q[top=i=1]=S]=1;i<=top;++i)
        for(j=hr[q[i]];j;j=e[j].nex)
        if(e[j].w&&!d[e[j].to])
            d[q[++top]=e[j].to]=d[q[i]]+1;
    return d[T];
}
int dfs(int x,int f){
    if(x==T) return f;
    register int i,used=0;
    for(i=hr[x];i;i=e[i].nex)
        if(e[i].w&&d[e[i].to]==d[x]+1){
            int w=dfs(e[i].to,min(f-used,e[i].w));
            used+=w;e[i].w-=w;e[i^1].w+=w;
            if(f==used) return f;
        }
    return d[x]=-1,used;
}
int main(){
    n=read(),m=read();
    register int x,y;
    while(1){
        x=read(),y=read();
        if(x==-1&&y==-1) break;
        ins(x,y+100,1);
    }
    for(x=1;x<=n;x++) ins(S,x,1);
    for(y=1;y<=m;y++) ins(y+100,T,1);
    while(bfs()) ans+=dfs(S,inf);
    printf("%d\n",ans);
    if(!ans) printf("No Solution!\n");
    for(int i=hr[S];i;i=e[i].nex)if(!e[i].w){
        for(int j=hr[e[i].to];j;j=e[j].nex)if(!e[j].w&&e[j].to!=S)
        printf("%d %d\n",e[i].to,e[j].to-100);
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=100001,INF=1e9;
const int B=29;
int ch[N*30][2];
int sz[N*30],b[N*30];
vector<int>f[N*30];
int indec=1;
void insert(int x){
    int cur=1;
    sz[cur]++;
    for(int i=B;i>=0;i--){
        if(!ch[cur][x>>i&1])ch[cur][x>>i&1]=++indec;
        cur=ch[cur][x>>i&1];
        sz[cur]++;
      //  cout<<x<<" "<<(x>>i&1)<<" "<<ch[cur][x>>1&1]<<" "<<cur<<endl;
    }
    b[cur]=x;
}
#define ls (ch[x][0])
#define rs (ch[x][1])

void dfs(int x,int dep){
    if(!x)return;
    f[x].resize(sz[x]+1);
 //   cout<<"dfs "<<x<<" "<<dep<<' '<<sz[x]<<endl;
    if(dep<0)return;
    if(sz[x]==1&&(!ls)&&(!rs)){f[x][1]=0;return;}
    dfs(ls,dep-1);
    dfs(rs,dep-1);

    for(int k=1;k<=sz[x];k++){
        f[x][k]=INF;
        if(k<=sz[ls])f[x][k]=min(f[x][k],f[ls][k]);
        else f[x][k]=min(f[x][k],f[rs][k-sz[ls]]+(1<<dep));
        if(k<=sz[rs])f[x][k]=min(f[x][k],f[rs][k]);
        else f[x][k]=min(f[x][k],f[ls][k-sz[rs]]+(1<<dep));
     //   cout<<x<<" "<<k<<" "<<f[x][k]<<endl;
    }

}
int solve(int x,int L,int R,int k,int dep){
    if(!x)return 0;
    //cout<<"solve "<<x<<" "<<L<<" "<<R<<" "<<k<<" "<<dep<<endl;
    if(L==-1&&R==-1)return f[x][k];
    if(dep==-1)return 0;
    int ans=INF;
    if(L==-1&&R!=-1){
        if(k<=sz[ls]){
            if(R>>dep&1)ans=min(ans,f[ls][k]);
            else ans=min(ans,solve(ls,-1,R,k,dep-1));
        }
        else{
            if(R>>dep&1)ans=min(ans,f[rs][k-sz[ls]]+(1<<dep));
            else ans=min(ans,solve(rs,L,R,k-sz[ls],dep-1)+(1<<dep));
        }
        if(k<=sz[rs]){
            if(R>>dep&1)ans=min(ans,solve(rs,-1,R,k,dep-1));
        }
        else{
            if(R>>dep&1)ans=min(ans,solve(ls,-1,R,k-sz[rs],dep-1)+(1<<dep));
        }
    }
    else if(L!=-1&&R==-1){
        if(k<=sz[ls]){
            if(!(L>>dep&1))ans=min(ans,solve(ls,L,-1,k,dep-1));
        }
        else{
            if(!(L>>dep&1))ans=min(ans,solve(rs,L,-1,k-sz[ls],dep-1)+(1<<dep));
        }
        if(k<=sz[rs]){
            if(!(L>>dep&1))ans=min(ans,f[rs][k]);
            else ans=min(ans,solve(rs,L,-1,k,dep-1));
        }
        else{
            if(!(L>>dep&1))ans=min(ans,f[ls][k-sz[rs]]+(1<<dep));
            else ans=min(ans,solve(ls,L,-1,k-sz[rs],dep-1)+(1<<dep));
        }
    }
    else{
        if(k<=sz[ls]){
            if(!(L>>dep&1)){
                if(!(R>>dep&1))ans=min(ans,solve(ls,L,R,k,dep-1));
                else ans=min(ans,solve(ls,L,-1,k,dep-1));
            }
        }
        else{
            if(!(L>>dep&1)){
         //   cout<<"in "<<endl;
                if(!(R>>dep&1))ans=min(ans,solve(rs,L,R,k-sz[ls],dep-1)+(1<<dep));
                else ans=min(ans,solve(rs,L,-1,k-sz[ls],dep-1)+(1<<dep));
            }
        }
        if(k<=sz[rs]){
            if((R>>dep&1)){
                if(L>>dep&1)ans=min(ans,solve(rs,L,R,k,dep-1));
                else ans=min(ans,solve(rs,-1,R,k,dep-1));
            }
        }
        else{
            if((R>>dep&1)){
                if(L>>dep&1)ans=min(ans,solve(ls,L,R,k-sz[rs],dep-1)+(1<<dep));
                else ans=min(ans,solve(ls,-1,R,k-sz[rs],dep-1)+(1<<dep));
            }
        }
    }
   // cout<<x<<" "<<L<<" "<<R<<" "<<k<<" "<<ans<<endl;
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,Q;
    cin>>n>>Q;
   //int n=100000,Q=100000;
    for(int i=1;i<=n;i++){
        int x;
      //  x=rand()%(1<<30);
        cin>>x;
        insert(x);
    }
    dfs(1,B);
    for(int i=1;i<=Q;i++){
        int l,r,k;
       // int l=rand()%(1<<30),r=rand()%(1<<30),k=rand()%(n-1)+1;
       // if(l>r)swap(l,r);
        cin>>l>>r>>k;
        cout<<solve(1,l,r,k,B)<<'\n';
    }
}
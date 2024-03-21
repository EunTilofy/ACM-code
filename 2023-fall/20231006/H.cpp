#include<bits/stdc++.h>
using namespace std;
int a[1<<16],b[1<<16];
int f[1<<16],g[1<<16];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int cur=0;
    vector<int>q;
    vector<int>t;
    for(int day=1;day<=n;day++){
        int x;
        scanf("%d",&x);
        if(cur<x){
            for(int i=cur+1;i<=x;i++)q.push_back(day);
        }
        else if(cur>x){
            while(q.size()>x){
                int y=q.back();
                q.pop_back();
                t.push_back(day-y);
                if(q.size()>m){
                    puts("0");
                    return 0;
                }
            }
        }
        cur=x;
    }
    while(!q.empty()){
        t.push_back(n-q.back()+1);
        q.pop_back();
    }
    for(int i=0;i<m;i++){
        scanf("%d%d",&a[1<<i],&b[1<<i]);
    }
    for(int i=0;i<(1<<m);i++){
        for(int j=0;j<m;j++){
            if(i>>j&1&&i!=(1<<j))a[i]+=a[1<<j],b[i]+=b[1<<j];
        }
    }
    int ans=0;
    for(int i=0;i<t.size();i++){
        memcpy(g,f,sizeof(f));
    //    cout<<"round "<<i<<" "<<t[i]<<endl;
        f[0]=-1e9;
        for(int u=1;u<(1<<m);u++){
            f[u]=-1e9;
            for(int s=u; s>0; s=(s-1)&u){
                
                if(a[s]==t[i]){
                    
                //    cout<<s<<" "<<a[s]<<' '<<b[s]<<endl;
                    f[u]=max(f[u],g[u^s]+b[s]);
                }
            }
            if(i==t.size()-1)ans=max(ans,f[u]);
           // cout<<"  "<<u<<" "<<f[u]<<endl;
        }
    }
    printf("%d\n",ans);

}
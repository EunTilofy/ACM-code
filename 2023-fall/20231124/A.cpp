#include<bits/stdc++.h>
using namespace std;
#define int long long
void bfs(int x,unordered_map<int,int> &res){
    queue<int>q;
    unordered_map<int,int>dis;
    dis[x]=0;
    q.push(x);
 //   cout<<"bfs "<<x<<endl;
    while(!q.empty()){
        auto x=q.front();
        q.pop();
        if(dis[x]>=32)continue;
        int y=x/2;
        int a=x+1,b=x-1;
        if((y>0)&&dis.find(y)==dis.end()) {
            dis[y]=dis[x]+1;
            q.push(y);
        }  
    }
    for(auto [key,val]:dis){
      //  cout<<"add "<<key<<' '<<val<<endl;
        res[key]=1;
    }
}
signed main(){
    int T=1;
    scanf("%lld",&T);
    while(T--){
        int n,m;
        unordered_map<int,int>res;
      //  n=500,m=250;
        scanf("%lld%lld",&n,&m);
        vector<int>a(n+1);
        m=n-m;
        for(int i=1;i<=n;i++){
            int x;
          //  x=rand()%1000000000;
            scanf("%lld",&x);
            bfs(x,res);
            a[i]=x;
        }
        int Ans=1e9;
        for(auto &[key,_]:res){
            vector<int>q;
            for(int i=1;i<=n;i++){
                int cnt=0,x=a[i],ans=2e9;
                while(x){
                    ans=min(ans,abs(x-key)+cnt);
                    cnt++;
                    x/=2;
                }
                q.push_back(ans);
            }
            sort(q.begin(),q.end());
            if(q.size()>=m){
           //     cout<<key<<" "<<q.size()<<endl;
                int ans=0;
                for(int i=0;i<m;i++)ans+=q[i];
                Ans=min(Ans,ans);
            }
            
        }
        printf("%lld\n",Ans);
    }
}
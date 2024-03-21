#include<bits/stdc++.h>
using namespace std;
const int C=100001;
const int N=100001;
bitset<C>bit[100][100];
vector<int>pri;
int vis[N],ord[N],a[N],ans[N];
vector<int>ban[N];
void init(){
    for(int i=2;i<=sqrt(N);i++){
        if(!vis[i]){
            pri.push_back(i);
            ord[i]=pri.size();
            for(int j=1;j*i<=sqrt(N);j++){
                vis[i*j]=1;
            }
        }
    }
}
vector<pair<int,int>>que[N];
pair<int,int>qs[N];
void pre(int x,int id){
    int y=x;
    for(auto p:pri){
        while(x%p==0){
            x/=p;
            bit[ord[p]][ord[p]][C-id]=1;
         //   cout<<y<<" "<<ord[p]<<" "<<id<<' '<<endl;
        }
        if(p>x)break;
    }
    if(x>1)ban[x].push_back(id);
}
int main(){
    int n,q;
    init();
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        pre(a[i],i);
    }
    for(int i=1;i<=q;i++){
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        qs[i]={l,r};
        int tmp=x;
        for(auto p:pri){
            while(tmp%p==0)tmp/=p;
            if(p>tmp)break;
        }
        que[tmp].push_back({x,i});
    }
    for(int i=1;i<=pri.size();i++){
        for(int j=1;j<=pri.size();j++){
            bit[i][j]=bit[i][i]|bit[j][j];
            
        }
    }
    for(int i=1;i<=pri.size();i++)
        for(int j=1;j<=pri.size();j++)
            bit[i][j].flip();
    for(int mx=1;mx<=N;mx++){
        if(!que[mx].empty()){
            bitset<C>ori={0};
            ori.flip();
            for(auto v:ban[mx]){
                ori[C-v]=0;
            }
            for(auto [v,id]:que[mx]){
                bitset<C>res=ori;
           //     cout<<endl<<mx<<" "<<v<<" "<<id<<endl;
                vector<int>cur;
                for(auto p:pri){
                    if(v%p==0)cur.push_back(p);
                    while(v%p==0)v/=p;
                    if(p>v)break;
                }
                
               // cout<<(res)<<endl;
                for(int i=0;i<cur.size();i+=2){
                    if(i+1<cur.size())res&=bit[ord[cur[i]]][ord[cur[i+1]]];
                    else res&=bit[ord[cur[i]]][ord[cur[i]]];
                }
                int l=qs[id].first,r=qs[id].second;
              //  cout<<(res)<<endl;
            //    cout<<C-r<<" "<<(res>>(C-r))<<endl;
                int pos=C-(res._Find_next(C-r-1));
              //  cout<<pos<<endl;
              ///  cout<<l<<" "<<r<<endl;
                if(pos<=r&&pos>=l)ans[id]=pos;
                else ans[id]=-1;
                
            }
        }
    }
    for(int i=1;i<=q;i++){
        printf("%d\n",ans[i]);
    }

}
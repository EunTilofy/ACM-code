#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int fa[N];
vector<pair<int,int>>e[N];
int find(int x){
    return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
vector<int>res;
int dfs(int x,int fa,int goal){
    if(x==goal)return 1;
    for(auto [v,id]:e[x]){
        if(v==fa)continue;
        if(dfs(v,x,goal)){
            res.push_back(id);
            return 1;
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        res.clear();
        for(int i=1;i<=n;i++){
            fa[i]=i;
        }
        for(int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y;
          //  cout<<T<<" "<<x<<" "<<y<<" "<<res.size()<<endl;
            if(!res.empty())continue;
            e[x].push_back({y,i});
            e[y].push_back({x,i});
            int rx=find(x),ry=find(y);
            if(rx!=ry){
                fa[rx]=ry;
            }
            else{
                dfs(x,0,y);
                res.push_back(i);
                sort(res.begin(),res.end());
                for(int i = 0; i < res.size(); ++i){
                    cout<<res[i]<<" \n"[i == res.size() - 1];
                }
            }
        }
        if(res.empty()){
            cout<<"-1"<<'\n';
        }
        for(int i=1;i<=n;i++){
            e[i]=vector<pair<int,int>>();
        }
    }
}
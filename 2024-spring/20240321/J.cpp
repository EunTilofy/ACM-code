#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<int>e[N];
int vis[N];
int dfs(int x,int fa){
    int cnt=0,sum=0;
    for(auto v:e[x]){
        if(v==fa)continue;
        sum+=dfs(v,x);
        if(!vis[v]){
            cnt++;
        }
    }
    if(cnt){
        cnt--;
        vis[x]=1;
    }
    return sum+vis[x]+cnt*2;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    int res=dfs(1,0);
    if(!vis[1])res+=2;
    cout<<res<<endl;
}
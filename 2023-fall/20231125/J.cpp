#include<bits/stdc++.h>
using namespace std;
const int N=105;
vector<int>e[N];
vector<int>d[2];
int col[N];
void dfs(int x,int fa){
    d[col[x]].push_back(x);
    for(auto v:e[x]){
        if(v==fa)continue;
        col[v]=col[x]^1;
        dfs(v,x);
    }
}
#define ll long long
ll res[N];
int bit[N];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1,0);
    if(d[0].size()>d[1].size()){
        swap(d[0],d[1]);
    }
    int cnt=2;
    for(auto v:d[0]){
        res[v]=(1ll<<60)-1;
        res[v]^=1;
        res[v]^=(1ll<<cnt);
        bit[v]=cnt;
        cnt++;
    }
    for(auto x:d[1]){
        res[x]^=1;
        for(auto v:e[x]){
            res[x]^=(1ll<<bit[v]);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<res[i]<<" ";
    }
}
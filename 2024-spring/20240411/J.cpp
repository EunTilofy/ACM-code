#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
vector<int>e[N];
int fa[N];
int n,m;
int find(int x){
    if(x==fa[x])return x;
    else return fa[x]=find(fa[x]);
}
int col[N];
int link[N][2];
void set_val(int x,int fa,int tp,int val){
  //  cout<<"set "<<x<<" "<<tp<<" "<<val<<endl;
    link[x][tp]=val;
    for(auto v:e[x]){
        if(v==fa)continue;
        set_val(v,x,tp,val);
    }
}
void merge(int _x,int _y,int val){
    int x=find(_x),y=find(_y);
    find(1);
    find(n);
    if(x==y)return;
   // cout<<"merge "<<x<<" "<<y<<" "<<fa[1]<<" "<<fa[n]<<endl;
    if(x==fa[1])set_val(y,0,0,val);
    if(y==fa[1])set_val(x,0,0,val);
    if(x==fa[n])set_val(y,0,1,val);
    if(y==fa[n])set_val(x,0,1,val);
    fa[x]=y;
    e[_x].push_back(_y);
    e[_y].push_back(_x);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    vector<pair<int,pair<int,int>>>s;
    int ans=2e9+5;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        if((x==1&&y==n)||(x==n&&y==1)){
            ans=min(ans,z);
        }
        s.push_back({z,{x,y}});
    }
    sort(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        merge(s[i].second.first,s[i].second.second,s[i].first);
    }
    for(int i=0;i<s.size();i++){
        int x=s[i].second.first,y=s[i].second.second;
        if(link[x][1]<=s[i].first&&link[y][0]<=s[i].first)ans=min(ans,s[i].first+max(link[x][1],link[y][0]));
        if(link[x][0]<=s[i].first&&link[y][1]<=s[i].first)ans=min(ans,s[i].first+max(link[x][0],link[y][1]));
    }
    cout<<ans;
}
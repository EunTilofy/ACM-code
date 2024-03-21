#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>a(m+1);
    vector<vector<int>>p(n+1);
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        p[i].resize(k+1);
        for(int j=1;j<=k;j++){
            int x;
            cin>>x;
            p[i][j]=x;
            a[x]=i;
     //       cout<<"set "<<x<<' '<<i<<endl;
        }
    }
 //   for(int i=1;i<=m;i++)cout<<a[i]<<" ";cout<<endl;
    vector<int>lim(n+1),loose(m+1);
    vector<vector<int>>ban(m+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<p[i].size();j++){
            if(a[p[i][j]]!=i){
                lim[i]++;
                ban[p[i][j]].push_back(i);
           //     cout<<"block "<<p[i][j]<<' '<<i<<endl;
            }
        }
    }
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i=1;i<=n;i++){
        if(!lim[i]){q.push(i);}
    }
    vector<int>res;
    while(!q.empty()){
        int x=q.top();
        res.push_back(x);
        q.pop();
        for(int j=1;j<p[x].size();j++){
            if(a[p[x][j]]==x&&!loose[p[x][j]]){
                loose[p[x][j]]=1;
                for(auto v:ban[p[x][j]]){
                    lim[v]--;
                    if(lim[v]==0){
                        q.push(v);
                    }
                }
            }
        }
    }
    reverse(res.begin(),res.end());

  //  for(auto v:res)cout<<v<<" ";cout<<endl;
    if(res.size()!=n){
        cout<<"No"<<'\n';
    }
    else{
        for(int i=0;i<n;i++){
            if(res[i]!=i+1){
                cout<<"Yes"<<'\n';
                for(auto v:res)cout<<v<<" ";
                cout<<'\n';
                return;
            }
        }
        cout<<"No"<<'\n';
    }
}
int main(){
    int T;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        solve();
    }
}
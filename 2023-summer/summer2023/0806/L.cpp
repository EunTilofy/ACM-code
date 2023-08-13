#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int res[N];
map<int,vector<int>>e;
int query(int x,int y){
  cout<<"? "<<x<<' '<<y<<endl;
  int v;
  cin>>v;
  return v;
}
void report(){
  vector<int>q;	    
  for(int i=1;i<=n;i++){
    if(res[i]==0)q.push_back(i);
  }
  cout<<"! "<<q.size()<<" ";
  for(auto v:q){
    cout<<v<<' ';
  }
  cout<<endl;
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<n;i++){
    int x=query(i,n);
    e[x].push_back(i);
  }
  int cur=0;
  for(auto [key,val]:e){
    if(val.size()>=e[cur].size())cur=key;
  }
  for(auto v:e[cur]){
    res[v]=1;
  }
  int p=-1;
  for(int i=1;i<n;i++){
    if(res[i]==0)p=i;
  }

  if(e[cur].size()==n-1-e[cur].size()){
    //n is truth
    int x=query(n,e[cur][0]);
    int y=query(p,e[cur][0]);
    if(x==y){
      for(int i=1;i<n;i++)res[i]^=1;
      res[n]=1;
    }
    else{
      res[n]=1;
    }
  }
  else{
    int x=query(n,e[cur][0]);
    int y=query(e[cur][1],e[cur][0]);
    if(x==y){
      res[n]=1;
    }
    else res[n]=0;
  }
  report();
}

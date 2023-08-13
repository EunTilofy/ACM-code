#include<bits/stdc++.h>
using namespace std;
const int mo=999983;
int vis[1000000];
vector<int>mul(vector<int>&a,vector<int>&b){
  vector<int>c(a.size()+b.size()-1);
  for(int i=0;i<a.size();i++){
    for(int j=0;j<b.size();j++){
      (c[i+j]+=1ll*a[i]*b[j]%mo)%=mo;
    }
  }
  return c;
}
int main(){
  int T;
  int indec=0;
  scanf("%d",&T);
  while(T--){
  ++indec;
    int n,k,l;
    scanf("%d%d%d",&n,&k,&l);
    vector<int>res(1);
    res[0]=1;
    for(int i=1;i<=l;i++){
      vector<int>s(2);
      int x;
      scanf("%d",&x);
      if(vis[x+400000]!=indec){
      vis[x+400000]=indec;
      s[0]=mo-x;
      s[1]=1;
      res=mul(res,s);
      }
    }
    while(res.back()==0)res.pop_back();
    if(res.size()-1>k){
      puts("0");
    }
    else{
      printf("%d\n",n);
      for(int i=1;i<=n;i++){
	printf("%lu ",res.size()-1);
	for(int j=res.size()-1;j>0;j--){
	  printf("%d ",1ll*res[j]*i%mo);
	}
	printf("%d\n",1ll*res[0]*i%mo);
      }
    }
  }
}

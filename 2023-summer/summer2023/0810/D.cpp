#include<bits/stdc++.h>
using namespace std;
vector<int> contore(int m){
  vector<int>a(7),b,f(10);
  int n=6;
  f[0]=1;
  int j;
  for(int i=1;i<=6;i++){
      f[i]=f[i-1]*i;
  }
  for(int i=1;i<=6;i++)a[i]=i;
  for(m--,j=1;j<n;j++){
    b.push_back(a[m/f[n-j]+1]);
    for(int i=m/f[n-j]+1;i<=n-j;i++){
      a[i]=a[i+1];
    }
  }
  b.push_back(a[1]);
  return b;
}
void encode(vector<int>s){
  sort(s.begin(),s.end());
  int ans=0;
  for(auto v:s){
    ans^=v;
  }
  auto b=contore(ans);
  vector<int>t(s.size());
  for(auto v:b){
    cout<<v<<" ";
  }
  assert(0);
  cout<<endl;

  for(int i=0;i<6;i++){
    t[i]=s[b[i]-1];
  }
  for(int i=6;i<12;i++){
    t[i]=s[b[i-6]-1];
  }
  for(int i=12;i<18;i++){
    t[i]=s[b[i-12]-1];
  }
  for(int i=18;i<s.size();i++){
    t[i]=s[i];
  }
  for(auto v:t){
    printf("%d ",v);
  }
}
int calc(vector<int>s){
  int n=6,t,j,ans=0;
  for(int i=0;i<n-1;i++){
    for(t=0,j=n-1;j>i;j--){
      if(s[j]<s[i])t++;
    }
    ans=(ans+t)*(n-i);
  }
  return ans+1;
}
void decode(vector<int>s){
  vector<int>t[10];
  for(int i=0;i<6;i++){
    t[0].push_back(s[i]);
  }
  for(int i=6;i<12;i++){
    t[1].push_back(s[i]);
  }
  for(int i=5;i<11;i++){
    t[2].push_back(s[i]);
  }
  for(int i=11;i<17;i++){
    t[3].push_back(s[i]);
  }
  for(int i=12;i<18;i++){
    t[4].push_back(s[i]);
  }
  vector<int>res(5);
  for(int i=0;i<5;i++){
    res[i]=calc(t[i]);
  }
  int ans=-1;
  if(res[0]==res[1]){
    ans=res[0];
  }
  if(res[2]==res[3]){
    ans=res[2];
  }
  if(res[0]==res[3]){
    ans=res[3];
  }
  for(auto v:s){
    ans^=v;
    printf("%d ",v);
  }
  printf("%d ",ans);
}
int main(){
  string s;
  cin>>s;
  if(s=="transmit"){
    int T;
    scanf("%d",&T);
    while(T--){
      int n;
      scanf("%d",&n);
      vector<int>a;
      for(int i=1;i<=n;i++){
	int x;
	scanf("%d",&x);
	a.push_back(x);
      }
      encode(a);
    }
  }
  else{
    int T;
    scanf("%d",&T);
    while(T--){
      int n;
      scanf("%d",&n);
      vector<int>a;
      for(int i=1;i<=n;i++){
	int x;
	scanf("%d",&x);
	a.push_back(x);
      }
      encode(a);
    }
  }

}

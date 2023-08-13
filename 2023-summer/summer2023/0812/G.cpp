#include<bits/stdc++.h>
using namespace std;
string s[10001];
set<int>S;
int DAY,ok;
void to_max(int,int,int);
void to_min(int,int,int);
void report(int x,int y){
  S.erase(x);
  S.insert(y);
  cout<<s[x]<<' '<<s[y]<<'\n';
//  for(auto v:S)cout<<v<<" ";
//  cout<<endl;
  DAY--;
  if(!DAY)ok=1;
}
void to_max(int mn,int len,int mx){
//  cout<<"to max "<<mn<<' '<<len<<' '<<mx<<endl;
  if(len==1){
    for(int i=mn;i<mx;i++){
      report(i,i+1);
      if(ok)return;
    }
  }
  else{
    for(int i=mn;i+len<=mx;i+=2){
      to_max(i+1,len-1,mx);
      if(ok)return;
      report(i,i+1);
      if(ok||i+len==mx)return;
      to_min(mx,len-1,i+2);
      if(ok)return;
      report(i+1,i+1+len);
      if(ok)return;
    }
  }
//  cout<<"ok max "<<mn<<' '<<len<<' '<<mx<<endl;
}
void to_min(int mx,int len,int mn){
//  cout<<"to min "<<mn<<' '<<len<<' '<<mx<<endl;
  if(len==1){
    for(int i=mx;i>mn;i--){
      report(i,i-1);
      if(ok)return;
    }
  }
  else{
    for(int i=mx;i-len>=mn;i-=2){
      to_min(i-1,len-1,mn);
      if(ok)return;
      report(i,i-1);
      if(ok||i-len==mn)return;
      to_max(mn,len-1,i-2);
      if(ok)return;
      report(i-1,i-1-len);
      if(ok)return;
    }
  }
//  cout<<"ok min "<<mn<<' '<<len<<' '<<mx<<endl;
}
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int g,a,n;
    scanf("%d%d%d",&g,&n,&a);
    for(int i=1;i<=a;i++){
      cin>>s[i];
    }
    map<string,int>mp;
    for(int i=1;i<=g;i++){
      string t;
      cin>>t;
      mp[t]=1;
      S.insert(a-i+1);
    }
    sort(s+1,s+1+a,[&](string a,string b){return mp[a]<mp[b];});
    DAY=n-1;
    ok=0;
    to_min(a,g,1);
    if(T)puts("");
  }

}

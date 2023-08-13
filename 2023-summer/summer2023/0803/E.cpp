#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int ex[N],rem[N];
int rex[N];
vector<int>ps[N];
char s[N];
void find(int x,int len){
//  cout<<"find "<<x<<" "<<len<<endl;
  if(len>=rex[x])
    ps[x].push_back(len);
  else if(rex[x]==len){
    return;
  }
  else {
    find(rex[rem[x]*2-x],len);
  }
}
map<int,pair<double,double>>res[N];
pair<double,double> cal(int x,int len){
//  cout<<"cal "<<x<<" "<<len<<endl;
  if(len>=rex[x]){
    return res[x][len];
  }
  else if(rex[x]==len){
    return res[x][len];
  }
  else {
    return cal(rex[rem[x]*2-x],len);
  }
}
int main(){
//freopen("palindromes.in","r",stdin);
//freopen("palindromes.out","w",stdout);
  scanf("%s",s+1);
  int n=strlen(s+1);
  s[0]='$';
  int r=0,m=0;
  for(int i=1;i<=n;i++){
    rem[i]=m;
    //cout<<"round "<<i<<endl;
 //   cout<<"curstate "<<m<<" "<<r<<endl;
    if(i<r){
      ex[i]=min(ex[m*2-i],r-i+1);
      find(m*2-i,ex[i]);
    }
    else ex[i]=1;
    rex[i]=ex[i];
    while(s[i+ex[i]]==s[i-ex[i]]||(s[i+ex[i]]=='?'&&s[i-ex[i]]!='$')||(s[i-ex[i]]=='?'&&i+ex[i]<=n))++ex[i];
    ps[i].push_back(ex[i]);
    if(i+ex[i]-1>r){
      r=i+ex[m=i]-1;
    }
  //  cout<<i<<" "<<ex[i]<<" "<<m<<" "<<r<<endl;
  }


  r=0,m=0;
  for(int i=1;i<=n;i++){
    ex[i]=rex[i];
    //cout<<"round "<<i<<endl;
//    cout<<"curstate "<<m<<" "<<r<<endl;
    if(i<r){
      res[i][ex[i]]=cal(m*2-i,ex[i]);
    }
    else{
      res[i][ex[i]]={1,1};
    }
  //  cout<<"put "<<i<<" "<<ex[i]<<" "<<res[i][ex[i]].first<<" "<<res[i][ex[i]].second<<endl;
    double p=res[i][ex[i]].first,f=res[i][ex[i]].second;
    double sp=1/26.0;
    sort(ps[i].begin(),ps[i].end());
    reverse(ps[i].begin(),ps[i].end());
    //cout<<"cur "<<i<<" "<<p<<' '<<f<<endl;
//	cout<<" aaaaa "<<" "<<s[i+ex[i]]<<" "<<s[i-ex[i]]<<endl;
    while(s[i+ex[i]]==s[i-ex[i]]||(s[i+ex[i]]=='?'&&s[i-ex[i]]!='$')||(s[i-ex[i]]=='?'&&i+ex[i]<=n)){
      if(i==6){
      }
      if(s[i+ex[i]]=='?'||s[i-ex[i]]=='?')p*=sp;
      f+=p*2;
      ++ex[i];
      while(!ps[i].empty()&&ex[i]==ps[i].back()){
	res[i][ps[i].back()]={p,f};
//	cout<<"put "<<i<<' '<<ps[i].back()<<" "<<p<<' '<<f<<endl;
	ps[i].pop_back();
      }
    }
    //cout<<"cur "<<i<<" "<<p<<' '<<f<<endl;


    if(i+ex[i]-1>r){
     r=i+ex[m=i]-1;
    }
  }
  double ans=0;
  for(int i=1;i<=n;i++){
  //cout<<res[i][ex[i]].second<<endl;
  }
  for(int i=1;i<=n;i++)
    ans+=res[i][ex[i]].second;
  
  ans/=n;
  printf("%.10lf",ans);
}


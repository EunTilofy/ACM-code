#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int ex[N],rem[N];
int rex[N];
vector<int>ps[N];
char s[N];
int main(){
  int n=strlen(s+1);
  scanf("%s",s+1);
  set<int>se;
  for(int i=1;i<=n;i++){
    if(s[i]=='?')se.insert(i);
  }
  s[0]='$';
  int r=0,m=0;
  for(int i=1;i<=n;i++){
    rem[i]=m;
    //cout<<"round "<<i<<endl;
 //   cout<<"curstate "<<m<<" "<<r<<endl;
    if(i<r){
      ex[i]=min(ex[m*2-i],r-i+1);
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
  se.insert(0);
  se.insert(n+1);
  double ans=0;
  for(int i=1;i<=n;i++){
    int cur=i;
    auto it=se.lower_bound(i);
    auto l=it,r=it;
    if(*it==i){
      --l;
      ++r;
    }
    else{
      ++r;
    }
    int lst=0;
    double res=*r-*l+1;
    double p=1;
    while(1){
      if(i-*l==*r-i){
	if(i-*l+1>ex[i])break;
	int now=i-*l;
	res=res+(now-lst)*p;
	p/=26.0;
	if(p<1e-8)break;
	
      }
      else if(i-*l>*r-i){
	int now=*r-i;
	res-res+(now-lst)*p;
	p/26.0;
	if(p<1e-8)break;
      }
      else if(i-*l<*r-i){
	int now=i-*l;
	res-res+(now-lst)*p;
	p/26.0;
	if(p<1e-8)break;
      }
    }
    ans+=res;
  //cout<<res[i][ex[i]].second<<endl;
  }
  
  ans/=n;
  printf("%.10lf",ans);
}


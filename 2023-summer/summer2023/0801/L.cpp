#include<bits/stdc++.h>
using namespace std;
const int N=1001;
int k;
int ret[N];
int x;
int m;
int tk,ttk;
int colx[N],coly[N],colz[N],resx[N],resy[N],resz[N];
int cnt[N],cc;
int main(){
  int n;
  cin>>n;
  int sz=0,cur=0;
  k=0;
  while(cur+sz<=n){
    ++k;
    ++sz;
    for(int i=cur+1;i<=cur+sz;i++){
      colx[i]=k;
      coly[i]=i-cur;
      colz[i]=1;
      tk=max(tk,coly[i]);
      ttk=max(ttk,colz[i]);
    }
    cur+=sz;
  }

  int p=cur+1;
  if(cur+k==n){
  for(int i=1;i<=n;i++){
  col[x]++;
  }
  }
  while(p<=n){
    for(int i=k;i>=1;i--){
      colx[p]=i;
      coly[p]=1;
      colz[p]=2;
      ttk=max(ttk,colz[p]);
      p++;
      if(p>n)break;
    }
  }



  cout<<k<<endl;
  for(int i=1;i<=n;i++){
    cout<<colx[i]<<" ";
    cnt[colx[i]]++;
  }
  cout<<endl;
  for(int i=1;i<=k;i++){
    ret[cnt[i]]=i;
  }
//  for(int i=1;i<=k;i++)cout<<cnt[i]<<" ";cout<<endl;
 // for(int i=1;i<=n;i++)cout<<ret[i]<<" ";cout<<endl;
//  cout<<endl; 
  for(int i=1;i<=k;i++){
  cin>>cc;
    for(int j=1;j<=cc;j++){
      cin>>x;
      resx[x]=ret[cc];
  //    cout<<cc<<" "<<ret[cc]<<" "<<x<<" "<<resx[x]<<endl;
    }
  }

//  for(int i=1;i<=n;i++){
//    cout<<resx[i]<<" "<<resy[i]<<" "<<resz[i]<<endl;
//  }



  cout<<tk<<endl;
  for(int i=1;i<=tk;i++)cnt[i]=0;
  for(int i=1;i<=n;i++){
    cout<<coly[i]<<" ";
    cnt[coly[i]]++;
  }
  for(int i=1;i<=tk;i++){
    ret[cnt[i]]=i;
  }
  cout<<endl; 
  for(int i=1;i<=tk;i++){
    cin>>cc;
    for(int j=1;j<=cc;j++){
      cin>>x;
      resy[x]=ret[cc];
    }
  }

  cout<<ttk<<endl;
  for(int i=1;i<=ttk;i++)cnt[i]=0;
  for(int i=1;i<=n;i++){
    cout<<colz[i]<<" ";
    cnt[colz[i]]++;
  }
  for(int i=1;i<=ttk;i++){
    ret[cnt[i]]=i;
  }
  cout<<endl; 
  for(int i=1;i<=ttk;i++){
    cin>>cc;
    for(int j=1;j<=cc;j++){
      cin>>x;
      resz[x]=ret[cc];
    }
  }

//  for(int i=1;i<=n;i++){
//    cout<<resx[i]<<" "<<resy[i]<<" "<<resz[i]<<endl;
//  }
  map<tuple<int,int,int>,int>s;
  for(int i=1;i<=n;i++){
    s[{resx[i],resy[i],resz[i]}]=i;
  }
  for(int i=1;i<=n;i++){
    cout<<s[{colx[i],coly[i],colz[i]}]<<" ";
  }
  cout<<endl;

}

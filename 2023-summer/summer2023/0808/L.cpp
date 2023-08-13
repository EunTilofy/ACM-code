#include<bits/stdc++.h>
using namespace std;
int n,x,y,z;
int Mx,My,Mz,M0;
vector<int>s;
const int N=1e6+5;
__int128 X[N],Y[N],Z[N];
struct asuka{
  int x,y,z,px,py,pz;
}a[N];
mt19937 rnd(114514);
int solve(int V){
  vector<long long>val(V);
  for(int i=0;i<V;i++)
    val[i]=rnd()%1000000;
  __int128 res=1;
  for(int i=1;i<V;i++)
    val[i]+=val[i-1];

  for(int i=1;i<=n;i++){
    X[i]=val[a[i].px]-val[a[i].x];
  }
  res=res*(val[Mx]-val[M0]);
  for(int i=0;i<V;i++)
    val[i]=rnd()%1000000;
  for(int i=1;i<V;i++)
    val[i]+=val[i-1];

  for(int i=1;i<=n;i++){
    Y[i]=val[a[i].py]-val[a[i].y];
  }
  res=res*(val[My]-val[M0]);
  for(int i=0;i<V;i++)
    val[i]=rnd()%1000000;
  for(int i=1;i<V;i++)
    val[i]+=val[i-1];

  for(int i=1;i<=n;i++){
    Z[i]=val[a[i].pz]-val[a[i].z];
  }
  res=res*(val[Mz]-val[M0]);
  __int128 ans=0;
  __int128 one=1;
  for(int i=1;i<=n;i++){
    ans+=one*X[i]*Y[i]*Z[i];
  }
  return res==ans;

}
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    s.resize(0);
    s.push_back(0);

    scanf("%d%d%d%d",&x,&y,&z,&n);
    for(int i=1;i<=n;i++){
    a[i].x=rand()%1000000000;
    a[i].y=rand()%1000000000;
    a[i].z=rand()%1000000000;
    a[i].px=rand()%1000000000;
    a[i].py=rand()%1000000000;
    a[i].pz=rand()%1000000000;
      scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
      scanf("%d%d%d",&a[i].px,&a[i].py,&a[i].pz);
      s.push_back(a[i].x);
      s.push_back(a[i].y);
      s.push_back(a[i].z);
      s.push_back(a[i].px);
      s.push_back(a[i].py);
      s.push_back(a[i].pz);
    }
    s.push_back(x);
    s.push_back(z);
    s.push_back(y);
    sort(s.begin(),s.end());
    s.erase(unique(s.begin(),s.end()),s.end());
    int l=s.size()+5;
    for(int i=1;i<=n;i++){
      a[i].x=lower_bound(s.begin(),s.end(),a[i].x)-s.begin()+1;
      a[i].y=lower_bound(s.begin(),s.end(),a[i].y)-s.begin()+1;
      a[i].z=lower_bound(s.begin(),s.end(),a[i].z)-s.begin()+1;
      a[i].px=lower_bound(s.begin(),s.end(),a[i].px)-s.begin()+1;
      a[i].py=lower_bound(s.begin(),s.end(),a[i].py)-s.begin()+1;
      a[i].pz=lower_bound(s.begin(),s.end(),a[i].pz)-s.begin()+1;
    }
    Mx=lower_bound(s.begin(),s.end(),x)-s.begin()+1;
    My=lower_bound(s.begin(),s.end(),y)-s.begin()+1;
    Mz=lower_bound(s.begin(),s.end(),z)-s.begin()+1;
    M0=lower_bound(s.begin(),s.end(),0)-s.begin()+1;
    int fl=1;
    for(int i=1;i<=100;i++){
      if(!solve(l)){
	puts("No");
	fl=0;
	break;
      }
    }
    if(fl) puts("Yes");
  }
}

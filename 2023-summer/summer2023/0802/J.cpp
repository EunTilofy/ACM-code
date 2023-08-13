#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],mn[N],mx[N],tag[N],c[N][2],v[N],w[N],s[N];
int n,i,x,y,ds,val,kth,p,q,z,rt,la,m,ans;
void pushup(int x){
  s[x]=s[c[x][0]]+s[c[x][1]]+1;
  mn[x]=tag[x];
  if(c[x][0])mn[x]=min(mn[x],mn[c[x][0]]);
  if(c[x][1])mn[x]=min(mn[x],mn[c[x][1]]);
}
void split_kth(int now,int &x,int &y){
  if(!now)return x=y=0,void();
  if(kth<=s[c[now][0]])split_kth(c[y=now][0],x,c[now][0]);
  else kth-=s[c[now][0]]+1,split_kth(c[x=now],c[now][1],y);
  pushup(now);
}
int merge(int x,int y){
  if(!(x&&y))return x|y;
  if(w[x]<w[y]){
    c[x][1]=merge(c[x][1],y);pushup(x);return x;
  }
  else {
    c[y][0]=merge(x,c[y][0]);
    pushup(y);
    return y;
  }
}
int del_kth(int x){
  kth=x;
  split_kth(rt,p,y);
  x=p;
  kth--;
  split_kth(x,p,q);
  rt=merge(p,y);
  return tag[q];
}
void ins_kth(int x,int val,int ori){
  kth=x-1;
  split_kth(rt,p,q);
  v[++ds]=ori;w[ds]=rand();s[ds]=1;tag[ds]=val;
  rt=merge(p,ds);
  rt=merge(rt,q);
}
void insert(int x,int v,int ori){
  v[++ds]=ori;w[ds]=rand();s[ds]=1;tag[ds]=v;
  rt=merge(rt,ds);
}
void query(int l,int r){
  kth=r;
  split_kth(rt,x,y);
  kth=l-1;
  split_kth(x,p,q);
  if(mn[q]==mx[q]){
    puts("YES");
  }
  else puts("NO");
  rt=merge(p,q);
  rt=merge(rt,y);
}
const int inf=2e9+10;
int main(){
  int n,Q;
  scanf("%d%d",&n,&Q);
  a[0]=-inf;
  multiset<int>s;
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }
  sort(a+1,a+1+n);
  for(int i=0;i<=n;i++){
    s.insert(a[i]);
    insert(a[i]-a[i-1],a[i]);
  }
  while(Q--){
    int oper,xx,yy;
    scanf("%d%d%d",&oper,&xx,&yy);
    if(oper==1){
      auto it=s.find(xx);
      int k=it-s.begin();
      int sum=0;
      sum+=del_kth(k);
      sum+=del_kth(k);
      ++it;
      ins_kth(k,sum,*it);

      it=s.lower_bound(yy);
      auto itt=--it;
       k=it-s.begin();
      del_kth(k);
      ins_kth(k,yy-*itt,yy);
      ins_kth(k,*it-yy,*it);
    }
    else{
      query(xx+1,yy);
    }
  }

}

#include<bits/stdc++.h>
#define N 505
#define ll long long
using namespace std;
typedef double NUM;
const NUM EPS = 1e-12, MAGIC = 2.71828e18;
NUM sqr(NUM a){
    return a*a;
}
NUM cmp(NUM a, NUM b){
    return fabs(a-b)>=EPS+fabs(a)*EPS?a-b:0;
}
struct VEC{
    NUM x,y;
    friend bool operator < (VEC a,VEC b){return a.x<b.x;}
}NOVEC={MAGIC,MAGIC};
struct RAY{
    VEC u,v;
}MORAY={NOVEC,NOVEC};
struct CIR{
    VEC u;
    NUM r;
}NOCIR={NOVEC,MAGIC};
inline VEC operator +(const VEC &a,const VEC &b){
    return (VEC){a.x+b.x,a.y+b.y};
}
inline VEC operator -(const VEC &a,const VEC &b){
    return (VEC){a.x-b.x,a.y-b.y};
}
inline NUM operator *(const VEC &a,const VEC &b){
    return a.x*b.y-a.y*b.x;
}
inline VEC operator *(NUM u, const VEC &a) {
 return (VEC) {u *a.x,u *a.y
};
}
inline NUM cmp(const VEC &a,const VEC &b){
    NUM at=cmp(a.x,b.x);
    return !at?cmp(a.y,b.y):at;
}
NUM cmp_side(const VEC &a,const VEC &b){
    return cmp(a.x*b.y,a.y*b.x);
}
VEC intersect(const RAY &a,const RAY &b){
    VEC s=a.u-a.v,t=b.u-b.v;
    NUM at=cmp_side(s,t);
    if (!at)    return NOVEC;
    return a.u+(b.u-a.u)*t/at*s;
}
bool collinear (const VEC &a,const VEC &b,const VEC &c){
  return !cmp_side(a-b,b-c);
}
struct line{
  VEC pos[N];
  int cnt,id;
  RAY tp;
}lin[N];
struct inter{
  VEC x;
  int u,v;
}pt[N*N];
int sum=0;
int idx=0,n,sx,sy;
ll k;
int aux[N],id[N*N];
string s[N];
struct zero{
  int nxt,to;
}edge[(N*N*2)];
int head[N*N],tot=0;;
void add_edge(int a,int b){edge[++tot]=(zero){head[a],b};head[a]=tot;cout<<a<<"->"<<b<<endl;}
int vis[N*N],sta[N*N];
int dfs(int x,int cnt){
  if(vis[x]){
    int siz=(cnt-vis[x]);
    int pl=(k-vis[x])%siz;
    return sta[pl+vis[x]];
  }
  else {vis[x]=cnt;sta[cnt]=x;}
  int flag=0;
  for(int i=head[x];i;i=edge[i].nxt){
    int to=edge[i].to;
    flag=1;
    return dfs(to,cnt+1);
  }
  if(!flag)return x;
}
int main(){
  scanf("%d%lld%d%d",&n,&k,&sx,&sy);
  srand(time(0));
  for(int i=1;i<=n;i++){
    cin>>s[i];
    double a,b,c,d;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    c+=rand()*1e-5;
    d+=rand()*1e-5;
    lin[i].tp=(RAY){(VEC){a,b},(VEC){c,d}};
  }
  for(int i=1;i<=n;i++)
  for(int r=1;r<i;r++){
     VEC cross=intersect(lin[i].tp,lin[r].tp);
     if(fabs(cross.x)>1e7||fabs(cross.y)>1e7)continue;
     pt[++sum]=(inter){cross,r,i};
     lin[i].pos[++lin[i].cnt]=cross;
     lin[r].pos[++lin[r].cnt]=cross;
     cout<<"inter:"<<i<<" "<<r<<" "<<cross.x<<" "<<cross.y<<endl;
  }
  for(int i=1;i<=n;i++){
    sort(lin[i].pos+1,lin[i].pos+lin[i].cnt+1);
  }
  aux[1]=0;
  for(int i=2;i<=n;i++){
    aux[i]=aux[i-1]+lin[i-1].cnt*2+2;
    cout<<"err:"<<lin[i].cnt<<" "<<aux[i]<<endl;
  }
  for(int i=1;i<=n;i++)
  for(int r=aux[i];r<=aux[i]+lin[i].cnt*2+2;r++)id[r]=i;
  for(int i=1;i<=sum;i++){
     int u=pt[i].u,v=pt[i].v;
     if((lin[u].tp.u.y-lin[u].tp.u.y)*(lin[v].tp.u.x-lin[v].tp.v.x)<(lin[v].tp.u.y-lin[v].tp.v.y)*(lin[u].tp.u.x-lin[u].tp.v.x))swap(u,v);
     int k1=lower_bound(lin[u].pos+1,lin[u].pos+lin[u].cnt+1,pt[i].x)-lin[u].pos;
     int k2=lower_bound(lin[v].pos+1,lin[v].pos+lin[v].cnt+1,pt[i].x)-lin[v].pos;
      add_edge(aux[u]+k1*2+1,aux[v]+k2*2+3);
      add_edge(aux[u]+k1*2+4,aux[v]+k2*2+2);
      add_edge(aux[v]+k2*2+1,aux[u]+k1*2+2);
      add_edge(aux[v]+k2*2+4,aux[u]+k1*2+3);
  }
  VEC st=(VEC){(double)sx,(double)sy};
  int start=0;
  for(int i=1;i<=n;i++){
    if(collinear(st,lin[i].tp.u,lin[i].tp.v)){
      int k=lower_bound(lin[i].pos+1,lin[i].pos+lin[i].cnt+1,st)-lin[i].pos;
      start=aux[i]+k*2+1;
      break;
    }
  }
  printf("%d\n",dfs(start,0));
}
/*
3 4 1 1
Broadway 0 0 0 1
Narrowlane 0 0 1 0
Homedrive 1 1 2 0

3 4 1 0
Broadway 0 0 0 1
Narrowlane 0 0 1 0
Homedrive 1 1 2 0
*/
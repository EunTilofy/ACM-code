#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
struct sett{
  int x,y,z;
}lib[5050];
int deg[15][15][15];
int vis[15][15][15];
int vis2[15][15][15];
int T;
int n;
queue<sett> q;
vector<sett>v;
int c1[6]={0,0,0,0,-1,1};
int c2[6]={0,0,1,-1,0,0};
int c3[6]={1,-1,0,0,0,0};
int main(){
 scanf("%d",&T);
 while(T--){
  scanf("%d",&n);
  v.clear();
  for(int i=0;i<=9;i++)for(int r=0;r<=9;r++)for(int p=0;p<=9;p++)vis[i][r][p]=deg[i][r][p]=vis2[i][r][p]=0;
  while(!q.empty())q.pop();
  for(int i=1;i<=n;i++){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    vis[a][b][c]=1;
    lib[i]=(sett){a,b,c};
    v.push_back(lib[i]);
  }

  for(int i=1;i<=n;i++){
    for(int p=0;p<6;p++){
      int tox=lib[i].x+c1[p],toy=lib[i].y+c2[p],toz=lib[i].z+c3[p];
      if(tox<0||toy<0||toz<0||tox>9||toy>9||toz>9)continue;
      if(!vis2[tox][toy][toz]){
        deg[tox][toy][toz]++;
      }
    }
  }
  for(int i=0;i<10;i++){
    for(int r=0;r<10;r++){
      for(int p=0;p<10;p++){
        if(deg[i][r][p]<=3&&(!vis[i][r][p])){
            q.push((sett){i,r,p});
            vis2[i][r][p]=1;
        }
      }
    }
  }
 while(!q.empty()){
  sett nw=q.front();q.pop();

     for(int p=0;p<6;p++){
         int tox=nw.x+c1[p],toy=nw.y+c2[p],toz=nw.z+c3[p];
         if(tox<0||toy<0||toz<0||tox>9||toy>9||toz>9)continue;
         if(!vis2[tox][toy][toz]){
          deg[tox][toy][toz]--;
          if(deg[tox][toy][toz]<=3){
            q.push((sett){tox,toy,toz});
            vis2[tox][toy][toz]=1;
          }
         }

   }
 }
 for(int i=0;i<=9;i++){
  for(int r=0;r<=9;r++){
    for(int p=0;p<=9;p++){
      if(!vis2[i][r][p])v.push_back((sett){i,r,p});
    }
  }
 }
 int ans=0;
 for(sett nw:v){
  // cout<<"v:"<<nw.x<<" "<<nw.y<<" "<<nw.z<<endl;
   int cnt=6; 
      for(int p=0;p<6;p++){
         int tox=nw.x+c1[p],toy=nw.y+c2[p],toz=nw.z+c3[p];
         if(tox<0||toy<0||toz<0)continue;
        if(vis[tox][toy][toz])cnt--;
      }

   ans+=cnt;
 }
 printf("%d\n",ans);
  }
}
/*
0 0 0
2 0 0
1 1 0
0 0 1
2 0 1
1 1 1
*/
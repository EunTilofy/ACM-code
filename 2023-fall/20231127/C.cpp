#include<bits/stdc++.h>
using namespace std;

const int N = 3005;
int n, m, k;
int dis[3005][3005];
string s[N];
int id[N][N];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool check(int x,int y){
return x<=n&&y<=m&&x>=1&&y>=1&&s[x][y]=='.';
}

vector<pair<int,int>>q[N*N*2];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    int X,Y;
    for(int i=1;i<=k;i++){
        int x,y;
        cin>>x>>y;
        if(i==1)X=x,Y=y;
        id[x][y]=k-i+1;
    }
    for(int i=1;i<=n;i++){
        cin>>s[i];
        s[i]=' '+s[i];
    }
    q[0].push_back({X,Y});
    memset(dis,0x3f,sizeof(dis));
    dis[X][Y]=0;
    for(int i=0;i<N*N*2;i++){
    for(auto [x,y]:q[i]){
      //  cout<<x<<" "<<y<<" "<<t<<endl;
        int t=i;
        if(dis[x][y]!=t)continue;
        for(int i=0;i<4;i++){
                int xx=x+dx[i],yy=y+dy[i];
                if(check(xx,yy)){
                    
           //     cout<<xx<<" "<<yy<<endl;
                    int extra=max(0,id[xx][yy]-(t+1));
                    if(t+extra+1<dis[xx][yy]){
                        dis[xx][yy]=t+extra+1;
                        q[dis[xx][yy]].push_back({xx,yy});
                    }
                }
        }
    }
    }
    unsigned long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
         //   cout<<dis[i][j]<<" ";
            if(dis[i][j]>=1e9)dis[i][j]=0;
            ans+=1ll*dis[i][j]*dis[i][j];
        }
     //   cout<<endl;
    }
    cout<<ans<<'\n';
}
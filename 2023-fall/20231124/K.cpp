#include<bits/stdc++.h>
using namespace std;
const int N=1000001;
int vis[N];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,cnt=0;
        scanf("%d",&n);
        for(int i=1;i<=n+1;i++)vis[i]=0;
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            if(vis[x+1]==1){
                vis[x]=1;
                vis[x+1]=0;
            }
            else {
                vis[x]=1;
                cnt++;
            }
            
        }
        printf("%d\n",cnt);
    }
}
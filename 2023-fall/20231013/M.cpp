#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
int res[N];
int vis[N];
vector<int>pri;
void euler(int n){
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            pri.push_back(i);
        }
        for(auto v:pri){
            if(i*v>=n)break;
            vis[i*v]=1;
            if(i%v==0)break;
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    euler(N-1);
    for(int i=2;i<N;i++){
        if(!vis[i])res[i]=1;
        else if(i%2==0)res[i]=2;
        else {
            if(vis[i-2]==0)res[i]=2;
            else res[i]=3;
        }
        res[i]+=res[i-1];
    }
    while(T--){
        int n;
        scanf("%d",&n);
        printf("%d\n",res[n]);
    }
}
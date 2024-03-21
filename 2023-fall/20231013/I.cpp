#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    scanf("%lld",&n);
    vector<tuple<int,int,int>>s;
    for(int i=1;i<=n;i++){
        int x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        s.push_back({x,y,z});
    }
    int ans=0;
    for(int i:{-1,1})for(int j:{-1,1})for(int k:{-1,1}){
        int res=0;
        for(auto [x,y,z]:s){
            x*=i;y*=j;z*=k;
            if(x+y+z>0)res+=(x+y+z);
        }
        ans=max(ans,res);
    }
    printf("%lld\n",ans);
}
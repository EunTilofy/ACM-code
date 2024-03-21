#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int cnt[13],sum[1<<13],f[1<<13];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,W;
    cin>>n>>W;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        cnt[x-1]++;
    }
    int S = 1 << 13;
    for(int i=0;i<S;i++){
        for(int j=0;j<13;j++){
            if(i>>j&1)sum[i]+=cnt[j];
        }
    }
    memset(f,127,sizeof(f));
    f[0]=0;
    for(int s=1;s<(1<<13);s++){
        for(int t=s;t&=s;t--){
            if(sum[t]<=W)f[s]=min(f[s],f[s^t]+1);
        }
    }
    cout<<f[(1<<13)-1];
}
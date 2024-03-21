#include<bits/stdc++.h>
using namespace std;
const int N=305,M=60005;
const int base=37,mod1=1e9+7;
char s[N][M];
char t[M];
int hsh[2][N][M];
int temp[2][M];
int pw[2][M];
int n,Q,m,K;
void build_hsh(){
    pw[0][0]=pw[1][0]=1;
    for(int i=1;i<=m;i++){
        pw[0][i]=1ll*pw[0][i-1]*base%mod1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
        hsh[0][i][j]=(1ll*hsh[0][i][j-1]*base%mod1+s[i][j]-'a'+1)%mod1;
    }
}
int get_hsh(int i,int l,int r){
    if(r < l) return 0;
    return (hsh[0][i][r]-1ll*hsh[0][i][l-1]*pw[0][r-l + 1]%mod1+mod1)%mod1;
}
int get_tmp(int l,int r){
    if(r < l) return 0;
    return (temp[0][r]-1ll*temp[0][l-1]*pw[0][r-l + 1]%mod1+mod1)%mod1;
}


int CNT = 0;
void solve(int i,int l,int r){
    int mid=(l+r)/2,res=0;
    if(CNT > K) return ;
   // cout<<"solve "<<i<<" "<<l<<" "<<mid<<" "<<get_hsh(i,l,mid).first<<" "<<get_tmp(l,mid).first<<endl;
  //  cout<<"solve "<<i<<" "<<mid+1<<" "<<r<<" "<<get_hsh(i,mid+1,r).first<<" "<<get_tmp(mid+1,r).first<<endl;
    if(l>r) return;
    else if(l==r){
   //     cout<<l<<" "<<r<<' '<<(s[i][l]!=t[l])<<endl;
        CNT += s[i][l]!=t[l];
    }
    else{
        if(get_hsh(i,l,mid)!=get_tmp(l,mid)){
            solve(i,l,mid);
        }
        if(CNT>K)return;
        if(get_hsh(i,mid+1,r)!=get_tmp(mid+1,r)){
            solve(i,mid+1,r);
        }
     //   cout<<l<<" "<<r<<' '<<res<<endl;
        return;    
    }
    
}
int main(){
    scanf("%d%d%d%d",&n,&Q,&m,&K);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    build_hsh();
    while(Q--){
        scanf("%s",t+1);
        for(int j=1;j<=m;j++){
            temp[0][j]=(1ll*temp[0][j-1]*base%mod1+t[j]-'a'+1)%mod1;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            // CNT = 0;
            int now = 0;
            for(int kk = 1; kk <= K; ++kk) {
                // cerr << kk << "\n";
                if(get_hsh(i, now+1, m) == get_tmp(now+1, m)) break;
                int l = now + 1, r = m, _ = m;
                while(l <= r) {
                    int mid = (l + r) >> 1;
                    // cerr << get_hsh(i, now+1, mid) << " " << get_tmp(now+1, mid) << "\n";
                    if(get_hsh(i, now+1, mid) == get_tmp(now+1, mid)) l = mid + 1;
                    else {
                        _ = mid, r = mid - 1;
                        // cerr << _ << "!\n";
                        // cerr << get_hsh(i, now+1, mid) << " " << get_tmp(now+1, mid) << "\n";
                    }
                }
                // cerr << kk << " " << _ << " " << now << "-----------\n";
                now = _;
            }
            // solve(i, 1, m);
            // if(CNT<=K)
            // cerr << Q << " " << s[i] << " " << t << " " << K << " " << now << "-------------------------------------------\n";
            if(get_hsh(i, now+1, m) == get_tmp(now+1, m)) ans++;
        }
        printf("%d\n",ans);

    }
    return 0;
}
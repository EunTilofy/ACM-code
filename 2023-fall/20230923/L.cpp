#include<bits/stdc++.h>
using namespace std;
const int N=5005;
char s[N];
int dp[5005][5005];
int nxt[N][N];
int n;
void init(){
    for(int beg=1;beg<=n;beg++){
        nxt[beg][beg]=beg-1;
        int j=beg-1;
        for(int i=beg+1;i<=n;i++){
            while((j-(beg-1))&&s[i]!=s[j+1])j=nxt[beg][j];
            nxt[beg][i]=j+=s[i]==s[j+1];
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s+1);
        n=strlen(s+1);
        int ans=0;
        init();
        for(int len=2;len<=n;len+=2){
            for(int i=1;i+len-1<=n;i++){
                int j=i+len-1;
                    dp[i][j]=0;
                    int pos=nxt[i][j];
                //    cout<<i<<" "<<j<<" "<<pos<<endl;
                    if(pos>=i){
                      //  while(2*(pos-i+1)>j-i+1)pos=nxt[i][pos];
                        if(2*(pos-i+1)>j-i+1)pos=(i+j-pos-1);
                        if(pos+1>i+j-pos-1){
                            dp[i][j]=1;
                        }
                        else dp[i][j]=dp[pos+1][i+j-pos-1];
                 //       cout<<i<<" "<<j<<" "<<pos<<" "<<i+j-pos<<"   "<<dp[i][j]<<endl;
                        if(dp[i][j])ans++;
                    }
                    
            }
        }
        printf("%d\n",ans);
    }
}
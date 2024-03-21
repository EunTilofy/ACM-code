#include<bits/stdc++.h>
using namespace std;
#define int long long
int p;
const int N=100005;
const int INF=1e17;
int f[N][19][27];
int val[26];
char s[N],t[N];
long long bs[N];
int n,m;
void dfs(int i,int len,int j){
    if(len==1){
        if(s[i]=='?'){
            for(int c=0;c<26;c++)f[i][j][c]=val[c],f[i][j][26]=max(f[i][j][26],f[i][j][c]);
        }
        else{
            for(int c=0;c<26;c++)f[i][j][c]=-INF;
            f[i][j][26]=f[i][j][s[i]-'A']=val[s[i]-'A'];
        }
    }
    else{
        for(int k=0;k<p;k++){
            dfs(i+k*(bs[j]),len/p,j+1);
        }
        for(int k=0;k<p;k++){
            f[i][j][26]+=f[i+k*bs[j]][j+1][26];
        }
        for(int c=0;c<26;c++){
            for(int k=0;k<p;k++){
                if(f[i+k*bs[j]][j+1][c]<=-INF){f[i][j][c]=-INF;break;}
                if(f[i][j][c]!=-INF)f[i][j][c]+=f[i+k*bs[j]][j+1][c];
            }
            if(f[i][j][c]!=-INF)f[i][j][c]+=len*val[c];
            f[i][j][26]=max(f[i][j][26],f[i][j][c]);
        }
        
    }
}
signed main(){
    scanf("%lld",&n);
    scanf("%s",s+1);
    scanf("%lld",&m);
    for(int i=1;i<=m;i++){
        int x;
        scanf("%s%lld",t,&x);
        val[t[0]-'A']=x;
    }
    if(n==1){
        int ans=0;
        if(s[1]=='?'){
            for(int i=0;i<26;i++)ans=max(ans,val[i]);
        }    
        else ans=val[s[1]-'A'];
        cout<<ans<<endl;
        return 0;
    }
    for(int i=2;i<=n;i++){
        if(n%i==0){
            p=n;
            while(p!=1)p/=i;
            p=i;break;
        }
    }
    bs[0]=1;
    for(int i=1;i<=20;i++){
        bs[i]=bs[i-1]*p;
        if(bs[i]==n)break;
    }
    dfs(1,n,0);
    printf("%lld\n",f[1][0][26]);
}
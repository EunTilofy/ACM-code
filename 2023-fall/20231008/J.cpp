#include<bits/stdc++.h>
using namespace std;
const int N=200;
int n,m;
int a[N][N],c[N],d[N],fac[N];
int f[2][2000005];
int contor(int c[]){
    int con=0;
    for(int i=1;i<n;i++){
        int t=0;
        for(int j=n;j>i;j--)if(c[j]<c[i])t++;
        con=(con+t)*(n-i);
    }
    return con;
}
using ll = long long;
const int mo=1e9+7;
const ll mo1=1000000000000000+37;
unordered_map<ll,int>vis;
ll hsh(int c[]){
    ll con=0;
    for(int i=1;i<n;i++){
        int t=0;
        for(int j=n;j>i;j--)if(c[j]<c[i])t++;
        con=(con+t)*(n-i)%mo1;
    }
    return con;
}
int main(){
    scanf("%d%d",&n,&m);
    int ans=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }
    if(m<=20){
        for(int st=0;st<(1<<m);st++){
         //   cout<<st<<endl;
            for(int i=1;i<=n;i++)c[i]=d[i]=0;
            for(int i=0;i<m;i++){
                if(st>>i&1){
                    if(c[1]==0){
                        for(int j=1;j<=n;j++)c[j]=a[i+1][j];
                    }
                    else{
                        for(int j=1;j<=n;j++)c[j]=d[a[i+1][j]];
                    }
                    for(int j=1;j<=n;j++)d[j]=c[j];
                }
            }
            if(c[1]){
                ll res=hsh(c);
             //   for(int i=1;i<=n;i++)cout<<c[i]<<" ";cout<<res<<" "<<endl;
                if(!vis[res])ans++;
                vis[res]=1;
            }
        }
        printf("%d\n",ans%mo);
    }
    else{
        fac[1]=1;
        int cnt=0;
        for(int i=2;i<=n;i++)fac[i]=fac[i-1]*i;
        f[0][0]=1;
        for(int day=1;day<=m;day++){
            memcpy(f[day&1],f[(day&1)^1],sizeof(f[day&1]));
            for(int i=0;i<fac[n];i++){
                if(!f[(day&1)^1][i])continue;
                for(int i=1;i<=n;i++)c[i]=i;
                int t=i,j;
                for(j=1;j<n;j++){
                    d[j]=c[t/fac[n-j]+1];
                    for(int i=t/fac[n-j]+1;i<=n-j;i++)c[i]=c[i+1];
                    t%=fac[n-j];
                }
                d[n]=c[1];                
           //     cout<<i<<"  ";for(int i=1;i<=n;i++)cout<<d[i]<<" ";cout<<endl;

                for(int j=1;j<=n;j++)c[j]=d[a[day][j]];
                int st=contor(c);
                if(st==0)cnt=1;
                f[day&1][st]=1;

            }
        }

        for(int i=0;i<fac[n];i++)if(f[m&1][i])ans++;
        printf("%d\n",(ans-1+mo+cnt)%mo);
        
    }

}
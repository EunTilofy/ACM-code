#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
#define N 2000005
using namespace std;
char s1[N],s2[N],s3[N],s4[N];
int ans[N];
int kmp[N];
bool vis[N];
int n,cnt=0,m;
int main(){
  char c=getchar();
  while(c>='a'&&c<='z')s1[++n]=c,c=getchar();
  c=getchar();n=0;
  while(c>='a'&&c<='z')s2[++n]=c,c=getchar();
  if(s1[1]!=s2[1]||s1[n]!=s2[n]){puts("-1");return 0;}
  for(int nw=2;nw<n;nw++){
    if(!vis[nw]){
      cnt++;
      int tp=nw;
      m=0;
      do{
         s3[++m]=s1[tp];
         s4[m]=s2[tp];
         vis[tp]=1;
         if(tp&1)tp=(tp+1)/2;
         else tp=tp/2+n/2;
      }while(tp!=nw);
      // cout<<"cnt:"<<cnt<<endl;
      // for(int i=1;i<=m;i++)putchar(s3[i]);putchar('\n');
      // for(int i=1;i<=m;i++)putchar(s4[i]);putchar('\n');
      for(int i=1;i<=m;i++)s4[i+m]=s4[i];
      int pos=0;
      for(int i=1;i<=m;i++)kmp[i]=0;
      for(int i=2;i<=m;i++){
        while(pos&&s3[pos+1]!=s3[i])pos=kmp[pos];
        if(s3[pos+1]==s3[i])pos++;
        kmp[i]=pos;
      }
      pos=0;
      for(int i=1;i<2*m;i++){
        while(pos&&s3[pos+1]!=s4[i])pos=kmp[pos];
        if(s3[pos+1]==s4[i])pos++;
        if(pos==m){
          for(int r=i-m;r<=n;r+=m)ans[r]++;
          // cout<<"complete:"<<i-m<<endl;
          pos=kmp[pos];
        }
      }
    }
  }
  for(int i=0;i<=n;i++){
    // cout<<i<<":"<<ans[i]<<endl;
    if(ans[i]==cnt){printf("%d\n",i);return 0;}
  }
  puts("-1");
}
#include<bits/stdc++.h>
using namespace std;
int s[6];
int main(){
  int n,k;
  scanf("%d%d",&n,&k);
  s[0]=k;
  s[1]=k<<7;
  s[2]=k<<14;
  s[3]=(k<<14)|k;
  s[4]=(k<<7)|k;
  s[5]=(k<<14)|(k<<7);
  for(int i=1;i<=n;i++){
    for(int j=0;j<6;j++){
      printf("%d ",s[j]);
    }
      puts("");
  }
  
}

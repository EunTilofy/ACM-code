#include<bits/stdc++.h>
using namespace std;
int ans[200][200];
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++)ans[i][j]=0;
    }
    if(k==1){

	  puts("YES"); 
      for(int i=1;i<n;i++){
	for(int j=0;j<n;j++){
	  if(i>j){
	    printf("%d ",1);
	  }
	}
	puts("");
      }
      continue;
    }
    if((n-1)<=k*2){
      if(n==5&&k==2){
	  puts("YES"); 
	  puts("1 "); 
	  puts("2 1 "); 
	  puts("2 2 1 "); 
	  puts("1 2 2 1 "); 
      }
      else if(n==4&&k==2){
	  puts("YES"); 
	  puts("1 "); 
	  puts("2 1 "); 
	  puts("2 2 1 "); 
      }
      else puts("NO");
    }
    else{
      puts("YES");
      int m=n-1;
      for(int i=0;i<m;i++){
	int id=i%k;
	ans[i][m]=ans[m][i]=id;
	for(int j=(id+1)*k;j<(id+2)*(k);j++){
	  int col=i%k; 
	  ans[i][j%m]=ans[j%m][i]=col;
	}
      }
      for(int i=1;i<n;i++){
	for(int j=0;j<n;j++){
	  if(i>j){
	    printf("%d ",ans[i][j]+1);
	  }
	}
	puts("");
      }
    }
  }
}

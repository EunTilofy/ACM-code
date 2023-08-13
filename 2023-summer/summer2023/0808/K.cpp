#include<bits/stdc++.h>
using namespace std;
char s[400][400];
int main(){
  int n,m,k;
  scanf("%d%d%d",&n,&m,&k);
  if(m>=k){
    puts("No");
  }
  else if(m==0){
    if(n>26){
      puts("No");
    }
    else{
      cout<<n<<endl;
      for(int i=1;i<=n;i++){
	for(int j=1;j<=k;j++){
	  putchar(i-1+'a');
	}
	puts("");
      }
    }

  }
  else if(m==1){
    for(int i=1;i<=n;i++){
      int x=i%26;
      int y=i/26;
      for(int j=1;j<=k;j+=2){
	s[i][j]=y+'a';
	s[i][j+1]=x+'a';
      }
    }
      cout<<n<<endl;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=k;j++){
	putchar(s[i][j]);
      }
      puts("");
    }

  }
  else{
    int id=0;
    for(int i=1;i<=n;i++){
      id++;
      for(int j=1;j<=k;j+=(m+1)){
	for(int pos=j;pos<=j+m-2;pos++){
	  s[i][pos]='a';
	}
	int x=id%25;
	int y=id/25;
	s[i][j+m-1]=y+'b';
	s[i][j+m]=x+'b';
      }
    }
      cout<<n<<endl;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=k;j++){
	putchar(s[i][j]);
      }
      puts("");
    }
  }
}

#include<bits/stdc++.h>
using namespace std;
void encode(vector<int>a,int n){
  a.resize(2*n+1);
  for(int i=2*n;i>0;i--){
    a[i]=a[i-1];
  }
  a[0]=1;
  int step=0;
  for(int i=0;i<2*n+1;i++){
    if(a[0]==1){
      int cnt=0,fl=1;
      for(int i=0;i<=2*n;i++){
	cnt+=a[i];
	if(cnt<=0){
	  fl=0;break;
	}
      }
      if(fl){
	for(int j=1;j<=2*n;j++){
	  if(a[j]==1)putchar('(');
	  else putchar(')');
	}
	puts("");
	printf("%d\n",step);
	return;
      }
      step++;
    }
    rotate(a.begin(),a.begin()+1,a.end());
  }
  assert(0);
}
void decode(vector<int>a,int n,int step){
  a.resize(2*n+1);
  for(int i=2*n;i>0;i--){
    a[i]=a[i-1];
  }
  a[0]=1;
  int pos=0;
  step=(n+2-step);
  for(int i=0;i<2*n+1;i++){
    if(a[i]==1)step--;
    if(step==0){
      pos=i;
      break;
    }
  }
  rotate(a.begin(),a.begin()+pos,a.end());
  for(int j=1;j<=2*n;j++){
    if(a[j]==-1){
      putchar('R');
    }
    else putchar('U');
  }
}
char s[1001];
int main(){
  string ty;
  cin>>ty;
  if(ty=="path"){
    int n;
    scanf("%d%s",&n,s);
    vector<int>a;
    for(int i=0;i<2*n;i++){
      if(s[i]=='U')a.push_back(1);
      else a.push_back(-1);
    }
    encode(a,n);
  }
  else{
    int n,k;
    scanf("%d%s%d",&n,s,&k);
    vector<int>a;
    for(int i=0;i<2*n;i++){
      if(s[i]=='(')a.push_back(1);
      else a.push_back(-1);
    }
    decode(a,n,k);
  }
}

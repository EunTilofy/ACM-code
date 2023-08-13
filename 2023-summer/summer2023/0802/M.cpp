#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  scanf("%d",&n);
    int min_x,max_x,min_y,max_y;
  for(int i=1;i<=n;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    if(i==1){
      min_x=max_x=x;
      min_y=max_y=y;
    }
    else{
      min_x=min(x,min_x);
      max_x=max(x,max_x);
      min_y=min(y,min_y);
      max_y=max(y,max_y);
    }
  }
  int resx,resy;
  if((min_x+max_x)%2==0){
    resx=(max_x-min_x)/2;
  }
  else{
    resx=(max_x-min_x+1)/2;
  }
  if((min_y+max_y)%2==0){
    resy=(max_y-min_y)/2;
  }
  else{
    resy=(max_y-min_y+1)/2;
  }
  printf("%d %d\n",resx,resy);
}

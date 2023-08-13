#include<bits/stdc++.h>
using namespace std;
int main(){
  int n=1e5,m=10,q=n;
  cout<<n<<' '<<m<<' '<<q<<endl;
  for(int i=1;i<=n;i++){
    int x=rand()%10000;
    cout<<x<<' ';
  }
  cout<<endl;
  for(int i=1;i<=m;i++){
    int x=rand()%n+1,y=rand()%n+1;
    cout<<x<<" "<<y<<endl;
  }
  for(int i=1;i<=q;i++){
    int x=rand()%n+1,y=rand()%n+1;
    cout<<"? "<<x<<" "<<y<<endl;
  }

}

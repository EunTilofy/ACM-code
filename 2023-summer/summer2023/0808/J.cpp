#include<bits/stdc++.h>
using namespace std;
const int N=1001;
int main(){
  int T;
    int n;
    cin>>n;
    set<string>mp;
    int ans=0;
    for(int i=1;i<=n;i++){
      string s;
      cin>>s; 
      int m=s.size();
      for(int i=0;i<m;i++){
	for(int j=i;j<m;j++){
	  if(mp.find(s.substr(i,j-i+1))!=mp.end()){
	    ans=max(ans,j-i+1);
	  }
	}
      }
      for(int i=0;i<m;i++){
	for(int j=i;j<m;j++){
	  mp.insert(s.substr(i,j-i+1));
	}
      }
    }
      cout<<ans<<endl;
}

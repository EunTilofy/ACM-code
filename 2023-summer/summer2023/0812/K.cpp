#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000001;
pair<int,int>a[N];
signed main(){
  int n;
  scanf("%lld",&n);
  for(int i=1;i<=n;i++){
    scanf("%lld",&a[i].second);
  }

  for(int i=1;i<=n;i++){
    scanf("%lld",&a[i].first);
  }
  sort(a+1,a+1+n);
  for(int i=1;i<n;i++){
    printf("%lld ",a[i].second);
  }
    printf("%lld",a[n].second);
}

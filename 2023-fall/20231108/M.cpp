#include<bits/stdc++.h>
const int N=1000001;
int a[N];
using namespace std;
int main(){
    int n,A;
    scanf("%d%d",&n,&A);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    vector<pair<int,int>>q;
    for(int i=0;i<n;i++){
        q.push_back({a[i]+a[(i+1)%n]+a[(i-1+n)%n],i});
    }
    sort(q.begin(),q.end());
    reverse(q.begin(),q.end());
    int b=0,ans=0;
    for(auto [v,id]:q){
        ++b;
      //  cout<<id<<" "<<v<<" "<<b<<endl;
        if(b<=A){
            ans+=v;
        }
        else ans+=3;
    }
    printf("%d\n",ans);


}
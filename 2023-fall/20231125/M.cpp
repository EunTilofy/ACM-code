#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int ans=max(ceil((double)2*n/(double)k),2.0);
    cout<<ans<<endl;
}
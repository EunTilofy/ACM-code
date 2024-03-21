#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,k;
    cin>>n>>k;
    vector<tuple<int,int,int>>t;
    for(int i=0;i<n;i++){
        int c,w,f;
        cin>>c>>w>>f;
        t.push_back({f,c,w});
    }
    sort(t.begin(),t.end());
    reverse(t.begin(),t.end());
    int sig=0,sum=0,ans=0;
    for(auto [f,cnt,w]:t){
     //   cout<<"floor: "<<f<<" cnt: "<<cnt<<" w "<<w<<"  sum "<<sum<<"  sig "<<sig<<endl;
        if(w==1){
            int t=min(cnt,sig);
            cnt-=t;
            sig-=t;
            t=min(cnt,sum);
            sum-=t;
            cnt-=t;
        }
        else{
            int p=sum/2;
            sum-=min(p,cnt)*2;
            cnt-=min(cnt,p);
        }
        if(sum%2==1){
            sum--;
            sig++;
        }
        if(cnt){
            int ele=(cnt*w-1)/k+1;
            sum+=(ele*k-cnt*w);
            ans+=ele*f;
            
            //cout<<cnt<<" "<<k<<" "<<ele<<" "<<sum<<" "<<ans<<endl;
        }
        if(sum%2==1){
            sum--;
            sig++;
        }
        
    }
    cout<<ans<<'\n';
}
signed main(){
    int T;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        solve();
    }
}
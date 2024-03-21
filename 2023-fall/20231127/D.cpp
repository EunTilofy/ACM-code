#include<bits/stdc++.h>
using namespace std;
int query(int x,int y){
    cout<<"? "<<x<<" "<<y<<endl;
    int res;
    cin>>res;
    return res;
}
void report(int x){
    cout<<"! "<<x+1<<endl;
}
void solve(){
    int n;
    cin>>n;
    int cnt=0,x=-1,y=-1,z=-1,w=-1;
    for(int i=1;i<n;i+=2){
        int res=query(i,i+1);
        if(res){
            cnt++;
            x=i,y=i+1;
        }
    }
    if(cnt>1){
        report(0);
    }
    else if(cnt==0){
        if(n%2==0){
            report(0);
        }
        else{
            int a1=query(1,n);
            int a2=query(2,n);
            int a3=query(3,n);
            if(a1&&a2&&a3){
                report(1);
            }
            else report(0);
        }
    }
    else{
        for(int i=1;i<=n;i++){
            
            if(z==-1&&i!=x&&i!=y){
                z=i;
            }
            if(i!=x&&i!=y&&i!=z){
                w=i;
                break;
            }
            
        }
        int p=query(x,z),q=query(y,z);
        if(!p&&!q){
            report(0);
        }
        else if(p){
            if(query(w,x)){
                report(1);
            }
            else report(0);
        }
        else if (q){
            if(query(w,y)){
                report(1);
            }
            else report(0);
        }
        else assert(0);
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
}
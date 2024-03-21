#include<bits/stdc++.h>
using namespace std;

string a,b;
vector<pair<int,int>>ans;

void report(int x,int y){
    ans.push_back({x,y});
 //   cout<<x<<' '<<y<<endl;
  //  cout<<a<<endl;
}
int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>a>>b;
        if(a.size()==1||b.size()==1){
            if(a==b){
                cout<<0<<endl;
            }
            else cout<<-1<<endl;
            continue;
        }


        ans.resize(0);
        for(int i=0;i<a.size();i++){
            if(a[i]=='0'){
                int j=i+1;
                while(a[j]=='0'&&j<a.size())j++;
                if(j>=a.size())j--;
                if(j>i){

                a.erase(i,j-i);
                report(i,j);
                }
            }
        }
        int n=a.size(),m=b.size();
        if(a[n-1]=='0'){
            a[n-1]='1';
            report(n-2,n-1);
        }
       // cout<<"ok"<<endl;
      //  return 0;
        if(a.size()>b.size()){
            for(int i=n-1;i>=m-1;i--){
              //  cout<<n<<" "<<m<<" "<<i<<" "<<a<<endl;
                a[i]='0';
                a+="0";
                report(i-1,i);
            }
            report(m-1,a.size()-1);
            a.erase(m-1,a.size()-m);
            n=a.size();
            a[n-1]='1';
            report(n-2,n-1);
        }

        while(a.size()<b.size()){
            if(a.size()==2){
                report(0,1);
                report(0,1);
                report(1,2);
                a+="1";
            }
            else{
                report(a.size()-3,a.size()-1);
                report(a.size()-2,a.size()-1);
                a+="1";
            }
        }

        for(int i=m-1;i>0;i--){
            if(b[i]=='0'){
                a[i]='0';
                report(i-1,i);
                report(i,i+1);
            }
        }
        cout<<ans.size()<<endl;
        for(auto [x,y]:ans){
            cout<<x+1<<" "<<y+1<<endl;
        }
    }
    
}
/*
1
110110000101000
10

*/
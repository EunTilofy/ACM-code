#include<bits/stdc++.h>
using namespace std;
int a[1001],res[1001];
int main(){
    srand(time(0));
    int n=10;
    int cnt=0,ans=0;
    for(int i=0;i<n;i++){
        a[i]=rand()%2;
        if(a[i]==0)cnt++;
        cout<<a[i]<<" ";
    }
    for(int i=0;i<n;i++){
        if(a[i]==1){
            for(int j=i+1;j<n;j++){
                if(a[j]==1)ans++;
                else break;
            }
            for(int j=i+1;j<n;j++){
                if(a[j]==0)ans++;
            }
            break;
        }
    }
    for(int day=0;day<n;day++){
        for(int i=day&1;i+1<n;i+=2){
            if(a[i]>a[i+1])swap(a[i],a[i+1]);
        }
      //  cout<<day<<" ";
        for(int i=0;i<n;i++){
            if(a[i]&&!res[i])res[i]=day;
        //    cout<<a[i]<<" ";
        }
      //  cout<<endl;
        int fl=0;
        for(int i=0;i<cnt;i++)if(a[i]==1)fl=1;
        if(fl)continue;
        else {
            
            cout<<ans<<" "<<day<<endl;
            assert(abs(ans - day) <= 10);
            return 0;
        }

    }

}
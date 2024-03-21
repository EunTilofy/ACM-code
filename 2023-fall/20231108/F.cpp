#include<bits/stdc++.h>
using namespace std;
int A[10001];
int C=0;
/*
int query(int l,int r){
    ++C;
    assert(l<=r);
    if(l==r)return 0;
    cout<<"? "<<l<<" "<<r<<endl;
    int cnt=0;
    for(int i=l;i<=r;i++){
        for(int j=i+1;j<=r;j++){
            if(A[i]>A[j])cnt++;
        }
    }
    cout<<cnt%2<<endl;
    return cnt%2;
}

*/
int query(int l,int r){
    assert(l<=r);
    if(l==r)return 0;
    cout<<"? "<<l<<" "<<r<<endl;
    int res;
    cin>>res;
    return res;
}

int main(){
 //   srand(time(0));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)A[i]=i;
    random_shuffle(A+1,A+1+n);
    vector<int>b(n);
    vector<int>pos(n+1);
    pos[1]=1;
    for(int i=2;i<=n;i++){
        int l=1,r=i-1,res=0;
        auto myque=[&](int lim){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(i<lim&&pos[i]>pos[lim])cnt++;
            }
            return cnt&1;
        };
        auto check=[&](int mid){
            int x=query(pos[mid],i);
            int y=query(pos[mid]+1,i);
            int z=myque(mid);
          /*  if(i>pos[mid]+1)cout<<"check "<<i<<" "<<pos[mid]<<" "<<(x^y^b[pos[mid]]^1)<<endl;
            else cout<<"check "<<i<<" "<<pos[mid]<<" "<<(x^y^1)<<endl;
            if(i>pos[mid]+1)return x^y^b[pos[mid]]^1;
            else return x^y^1;
            */
     //      cout<<"check "<<i<<" "<<pos[mid]<<" "<<(x^y^z^1)<<endl;
           return x^y^z^1;
        };
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid)){
                res=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        for(int j=i;j>res;j--){
            pos[j]=pos[j-1];
        }
        pos[res+1]=i;
        vector<int>a(n+1);
        for(int i=1;i<=n;i++){
            a[pos[i]]=i;

        }
   /*     cout<<"! ";
        for(int i=1;i<=n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;*/
    }
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        a[pos[i]]=i;
    }
    
   // for(int i=1;i<=n;i++)cout<<A[i]<<" ";cout<<endl;
    cout<<"! ";
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
  //  cout<<C<<endl;
}
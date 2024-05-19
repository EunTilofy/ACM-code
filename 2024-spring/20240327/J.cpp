#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
void cmax(int &x, int y) {x  = std::max(x, y);}
const int N=1e6+5;
int l[N],r[N],a[N];
#define ll long long
ll cross(int x,int y,int ux,int uy){
    return 1ll*x*uy-1ll*y*ux;
}
int check(int x,int y,int z){
    if(cross(x-y,r[x]-r[y],y-z,r[y]-r[z])>=0)return 1;
    else return 0;
}
int check2(int x,int y,int z){
    if(cross(x-y,r[x]-l[y],y-z,l[y]-r[z])>=0)return 1;
    else return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l[i];
    }
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    vector<int>s;
    s.push_back(1);
    s.push_back(2);
    for(int i=3;i<=n;i++){
        while(1){
            if(s.size()<2)break;
            auto it=s.end(),it2=s.end();
            --it;--it;--it2;
            if(!check(*it,*it2,i))s.pop_back();
            else break;
        }
        s.push_back(i);
    }
  //  for(auto v:s)cout<<v<<" ";
    for(int i=1;i<=n;i++){
        auto it=lower_bound(s.begin(),s.end(),i);
        if(*it!=i){
            if(!check2(*prev(it),i,*it)){
                cout<<"No";
                return 0;
            }
        }
    }
    cout<<"Yes";
    

    
}
#include<bits/stdc++.h>
using namespace std;
const int N=200005;
struct seg{
    int l,r,id;
}t[N];
int n,nn;
int c[2*N];
void modify(int x,int res){
    x=nn-x;
    for(;x<=nn;x+=x&(-x)){
        c[x]=max(c[x],res);
    }
}
int query(int x){
    int res=0;
    x=nn-x;
    for(;x;x-=x&(-x)){
        res=max(res,c[x]);
    }
    return res;
}
int res[N];
int main(){
    scanf("%d",&n);
    vector<int>s;
    for(int i=1;i<=n;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        r=l+r;
        s.push_back(l);
        s.push_back(r);
        t[i]={l,r,i};
    }
    sort(s.begin(),s.end());
    s.erase(unique(s.begin(),s.end()),s.end());
    nn=s.size()+1;
    for(int i=1;i<=n;i++){
        t[i].l=lower_bound(s.begin(),s.end(),t[i].l)-s.begin()+1;
        t[i].r=lower_bound(s.begin(),s.end(),t[i].r)-s.begin()+1;
       // cout<<t[i].l<<" "<<t[i].r<<endl;
    }
    
    sort(t+1,t+1+n,[&](seg a,seg b){
        if(a.l!=b.l)return a.l<b.l;
        else return a.r>b.r;
    });
    
    for(int i=1;i<=n;i++){
        res[t[i].id]=query(t[i].r);
        modify(t[i].r,res[t[i].id]+1);
    }
    for(int i=1;i<=n;i++){
        printf("%d ",res[i]);
    }
}
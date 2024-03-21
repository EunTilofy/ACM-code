#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int cnt;
int a[N];
struct seg{
    int mx,mn;
}t[N<<2];
int n,ans;
void pushup(int x){
    t[x].mx=max(t[x<<1].mx,t[x<<1|1].mx);
    t[x].mn=min(t[x<<1].mn,t[x<<1|1].mn);
}
void modify(int x,int l,int r,int pos,int d){
    if(l==r){
        t[x].mx=t[x].mn=d;
        return;
    }
    else{
        int mid=(l+r)/2;
        if(pos<=mid){
            modify(x<<1,l,mid,pos,d);
        }
        else modify(x<<1|1,mid+1,r,pos,d);
        pushup(x);
    }
}
void build(int x,int l,int r){
    if(l==r){
        t[x].mx=t[x].mn=a[l];
        return;
    }
    else{
        int mid=(l+r)/2;
        if(l<=mid)build(x<<1,l,mid);
        if(mid<r)build(x<<1|1,mid+1,r);
        pushup(x);
    }
}
int query_ge(int x,int l,int r,const int &L,const int &lim){
 //   cnt++;
    if(t[x].mx<lim)return n+1;
    if(l==r){
        return l;
    }
    else if(l>=L){
        if(t[x<<1].mx>=lim)return query_ge(x<<1,l,(l+r)/2,L,lim);
        else return query_ge(x<<1|1,(l+r)/2+1,r,L,lim);
    }
    int mid=(l+r)/2;
    int res=n+1;
    if(L<=mid){
        res=query_ge(x<<1,l,mid,L,lim);
    }
    if(res==n+1)res=query_ge(x<<1|1,mid+1,r,L,lim);
    return res;
    
}
int query_le(int x,int l,int r,const int &R,const int &lim){
   // cnt++;
    if(t[x].mn>lim)return 0;
    if(l==r){
        return l;
    }
    else if(r<=R){
        if(t[x<<1|1].mn<=lim)return query_le(x<<1|1,(l+r)/2+1,r,R,lim);
        else return query_le(x<<1,l,(l+r)/2,R,lim);
    }
    int mid=(l+r)/2;
    int res=0;
    if(R>mid){
        res=query_le(x<<1|1,mid+1,r,R,lim);
    }
    if(res==0)res=query_le(x<<1,l,mid,R,lim);
    return res;
}
void quicksort(int l,int r){
    if(l>=r)return;
    int mid=(l+r)/2;
    int piv=a[mid];
    int i=l-1,j=r+1,pos=mid;
        cnt++;
    if(r-l<=60){
        while(1){
            do{++i;}while(a[i]<piv);
            do{--j;}while(a[j]>piv);
            if(i>=j){
                pos=j;
                break;
            }
            modify(1,1,n,i,a[j]);
            modify(1,1,n,j,a[i]);
            swap(a[i],a[j]);
            ans++;
        }
        int fl=1;
        for(int i=l;i<r;i++){
            if(a[i]>a[i+1]){fl=0;break;}
        }
        if(fl)return;

    }
    else{
        while(1){
            i=query_ge(1,1,n,i+1,piv);
            j=query_le(1,1,n,j-1,piv);
            if(i>=j){
                pos=j;
                break;
            }
            modify(1,1,n,i,a[j]);
            modify(1,1,n,j,a[i]);
            swap(a[i],a[j]);
            ans++;
        }
    }
    quicksort(l,pos);
    quicksort(pos+1,r);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
    //    scanf("%d",&n);
       n=100000;
        ans=0;
        for(int i=1;i<=n;i++)a[i]=i;
        random_shuffle(a+1,a+1+n);
        
     //   for(int i=1;i<=n;i++){
    //        scanf("%d",&a[i]);
    //    }
        
        build(1,1,n);
        quicksort(1,n);
        printf("%d\n",ans);
        cout<<cnt<<endl;
    }
}
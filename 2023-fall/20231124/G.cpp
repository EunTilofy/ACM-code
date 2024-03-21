#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int cnt,ccnt;
int a[N];
int mx[N],mn[N];
int n,ans;
void modify(int x,int l,int r,int pos,int d){
    if(l==r){
        mx[x]=mn[x]=a[l];
        return;
    }
    else{
        int mid=(l+r)/2;
        if(pos<=mid){
            modify(x<<1,l,mid,pos,d);
        }
        else modify(x<<1|1,mid+1,r,pos,d);
        mx[x]=max(mx[x<<1],mx[x<<1|1]);
        mn[x]=min(mn[x<<1],mn[x<<1|1]);
    }
}
void build(int x,int l,int r){
    if(l==r){
        mx[x]=mn[x]=a[l];
        return;
    }
    else{
        int mid=(l+r)/2;
        if(l<=mid)build(x<<1,l,mid);
        if(mid<r)build(x<<1|1,mid+1,r);
        mx[x]=max(mx[x<<1],mx[x<<1|1]);
        mn[x]=min(mn[x<<1],mn[x<<1|1]);
    }
}
int query_ge(int x,int l,int r,const int &L,const int &R,const int &lim){
    cout<<x<<" "<<l<<" "<<r<<"  "<<L<<" "<<R<<endl;
    cnt++;
    if(mx[x]<lim)return n+1;
    int mid=(l+r)/2;
    if(l==r){
        return l;
    }
    if(L>mid){
        return query_ge(x<<1|1,mid+1,r,L,R,lim);
    }
    if(R<=mid){
        return query_ge(x<<1,l,mid,L,R,lim);
    }
    
    else if(l>=L&&r<=R){
        if(mx[x<<1]>=lim)return query_ge(x<<1,l,(l+r)/2,L,R,lim);
        else return query_ge(x<<1|1,(l+r)/2+1,r,L,R,lim);
    }
    int res=query_ge(x<<1,l,mid,L,R,lim);
    if(res==n+1)res=query_ge(x<<1|1,mid+1,r,L,R,lim);
    return res;
    
}
int query_le(int x,int l,int r,const int &L,const int &R,const int &lim){
    cnt++;
    if(mn[x]>lim)return 0;
    int mid=(l+r)/2;
    if(l==r){
        return l;
    }
    if(L>mid){
        return query_le(x<<1|1,mid+1,r,L,R,lim);
    }
    if(R<=mid){
        return query_le(x<<1,l,mid,L,R,lim);
    }
    
    else if(r<=R&&l>=L){
        if(mn[x<<1|1]<=lim)return query_le(x<<1|1,(l+r)/2+1,r,L,R,lim);
        else return query_le(x<<1,l,(l+r)/2,L,R,lim);
    }
    int res=query_le(x<<1|1,mid+1,r,L,R,lim);
    if(res==0)res=query_le(x<<1,l,mid,L,R,lim);
    return res;
}
void quicksort(int l,int r){
    cout<<"sort "<<l<<' '<<r<<endl;
    if(l>=r)return;
    int mid=(l+r)/2;
    int piv=a[mid];
    int i=l-1,j=r+1;
        cnt++;
    if(0){
        while(1){
            do{++i;}while(a[i]<piv);
            do{--j;}while(a[j]>piv);
            if(i>=j){
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
            ccnt+=2;
            i=query_ge(1,1,n,i+1,r,piv);
            j=query_le(1,1,n,l,j-1,piv);
            if(i>=j){
                break;
            }
            modify(1,1,n,i,a[j]);
            modify(1,1,n,j,a[i]);
            swap(a[i],a[j]);
            ans++;
        }
    }
    quicksort(l,j);
    quicksort(j+1,r);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
     //  n=1000;
        ans=0;
    //    for(int i=1;i<=n;i++)a[i]=i;
     //   random_shuffle(a+1,a+1+n);
        
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        
        build(1,1,n);
        quicksort(1,n);
        printf("%d\n",ans);
        cout<<cnt<<" "<<ccnt<<" "<<cnt/ccnt<<endl;
    }
}
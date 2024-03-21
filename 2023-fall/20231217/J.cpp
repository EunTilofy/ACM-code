#include<bits/stdc++.h>
#define ll long long
//#define int long long
using namespace std;
int n,a[410101];
struct SEG{
    int seg[410101];
    inline void pushup(int rt){
        seg[rt]=(seg[rt<<1]>=1)&&(seg[rt<<1|1]>=1);
    }
    #define mid ((lb+rb)>>1)
    void update(int rt,int lb,int rb,int pos,int w){
        if (lb==rb) return (void)(seg[rt]+=w);
        mid>=pos?update(rt<<1,lb,mid,pos,w):update(rt<<1|1,mid+1,rb,pos,w);
        pushup(rt);
    }
    int mex(int rt,int lb,int rb){
        if (lb==rb) return seg[rt]?-1:lb;
        if (seg[rt<<1]) return mex(rt<<1|1,mid+1,rb);
        else return mex(rt<<1,lb,mid);
    }
}S1;
struct SEG2{
    int seg[410101];
    inline void pushup(int rt){
        seg[rt]=max(seg[rt<<1],seg[rt<<1|1]);
    }
    #define mid ((lb+rb)>>1)
    void update(int rt,int lb,int rb,int pos,int w){
        if (lb==rb) return (void)(seg[rt]=w);
        mid>=pos?update(rt<<1,lb,mid,pos,w):update(rt<<1|1,mid+1,rb,pos,w);
        pushup(rt);
    }
    int mex(int rt,int lb,int rb,int R){
        if (lb==rb) return seg[rt]>R?lb:-1;
//		if (seg[rt]<=R) return -1;
        if (seg[rt<<1]<=R) return mex(rt<<1|1,mid+1,rb,R);
        else return mex(rt<<1,lb,mid,R);
    }
}S2;

int now[410101],pre[410101];
struct edge{
    int nxt,fi,se;
}g[30101021];
int head[410101],tot;
inline void made(int from,int fi,int se){
    g[++tot].fi=fi;g[tot].se=se;g[tot].nxt=head[from];head[from]=tot;
}
signed main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        now[i]=!a[i];
        S1.update(1,0,n+1,now[i],1);
    }
    cout << S1.mex(1,0,n+1) << " ";
    for (int i=0;i<=n+1;i++) pre[i]=n+1,S2.update(1,0,n+1,i,n+1);
    for (int i=n;i;i--){
        pre[a[i]]=i;
        int cnt=0;
        S2.update(1,0,n+1,a[i],i);
        for (int mx=now[i],j=i;;){
            cnt++;
            if (cnt==n) exit(-1);
            j=pre[mx];
            if (n-(j-i+1)+1<mx) break;
            if (j==n+1) break;
            mx=S2.mex(1,0,n+1,j);
            made(j-i+1,i,mx);
//    		que[j-i+1].push_back(make_pair(i,mx));
        }
    }
//	#define fi first
//	#define se second
    int flag=0;
    for(int i=2;i<=n;i++){
        if (flag) {
            cout << "0 ";
            continue;
        }
        S1.update(1,0,n+1,now[n-i+2],-1);
        for (int j=head[i];j;j=g[j].nxt){
            int fi=g[j].fi,se=g[j].se;
               S1.update(1,0,n+1,now[fi],-1);
            now[fi]=se;
               S1.update(1,0,n+1,now[fi],1);
        }
        int now=S1.mex(1,0,n+1);
        if (now==0){
            flag=1;
        }
        cout << now << " ";
    }
    return 0;
}

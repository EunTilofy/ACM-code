/*
f[i]=f[j] (j is the maximal element smaller than i
f[j]=f[j]+s-i (j<i)
f[j]=f[j]+j-i (j>i)
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int x = 0, f = 1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,a[100100],rt,cnt;
#define lson t[x].ch[0]
#define rson t[x].ch[1]
struct Treap{
	int key,rd,ch[2],sz;
	ll f,tagf,tagt,tms,mn;
}t[100100];
void pushup(int x){
	t[x].mn=t[x].tms,t[x].sz=1;
	if(lson)t[x].mn=min(t[x].mn,t[lson].mn),t[x].sz+=t[lson].sz;
	if(rson)t[x].mn=min(t[x].mn,t[rson].mn),t[x].sz+=t[rson].sz;
}
void ADDF(int x,ll y){if(x)t[x].tagf+=y,t[x].f+=y;}
void ADDT(int x,ll y=1){if(x)t[x].tagt+=y,t[x].tms-=y,t[x].mn-=y,t[x].f+=1ll*y*t[x].key;}
void pushdown(int x){
	ADDF(lson,t[x].tagf),ADDT(lson,t[x].tagt);
	ADDF(rson,t[x].tagf),ADDT(rson,t[x].tagt);
	t[x].tagf=t[x].tagt=0;
}
int merge(int x,int y){
	if(!x||!y)return x+y;
	if(t[x].rd>t[y].rd){pushdown(x),t[x].ch[1]=merge(t[x].ch[1],y),pushup(x);return x;}
	else{pushdown(y),t[y].ch[0]=merge(x,t[y].ch[0]),pushup(y);return y;}
}
void splitbykey(int x,int k,int &u,int &v){//u:<k.
	if(!x){u=v=0;return;}
	pushdown(x);
	if(t[x].key<k)u=x,splitbykey(rson,k,rson,v);
	else v=x,splitbykey(lson,k,u,lson);
	pushup(x);
}
void splitbysize(int x,int k,int &u,int &v){
	if(!x){u=v=0;return;}
	pushdown(x);
	if(t[lson].sz>=k)v=x,splitbysize(lson,k,u,lson);
	else u=x,splitbysize(rson,k-t[lson].sz-1,rson,v);
	pushup(x);
}
int Newnode(int key,ll f){
	int x=++cnt;
	t[x].f=f,t[x].key=key,t[x].rd=rand()*rand();
	pushup(x);
	return x;
}
ll flor(ll x,ll y){//the floor-rounded of x/y.
	if(x<=0)return 0;
	return (x-1)/y+1;
}
void func(int k,int pre){
	int a,b,c,d,e;
	splitbykey(rt,k,b,c);
	ADDF(b,pre);
	splitbysize(b,t[b].sz-1,a,b);
	splitbykey(c,k+1,c,d);
	if(!c)c=Newnode(k,0),t[c].f=t[b].f+k-pre;//because f[b] has already been added by pre.
	else t[c].f+=k;
	t[c].tms=flor(t[b].f-t[c].f,t[c].key-t[b].key);
	pushup(c);
	ADDT(d);
	splitbysize(d,1,d,e);
	if(d)t[d].tms=flor(t[c].f-t[d].f,t[d].key-t[c].key),pushup(d);
	rt=merge(merge(merge(merge(a,b),c),d),e);
}
int getmn(int x){
	pushdown(x);
	if(lson&&t[lson].mn<=0)return getmn(lson);
	if(t[x].tms<=0)return t[x].key;
	return getmn(rson);
}
void reset(){
	while(rt&&t[rt].mn<=0){
		int k=getmn(rt);
		int a,b,c,d,e;
		splitbykey(rt,k,b,c);
		splitbysize(b,t[b].sz-1,a,b);
		splitbykey(c,k+1,c,d);
		splitbysize(d,1,d,e);
		if(d)t[d].tms=flor(t[b].f-t[d].f,t[d].key-t[b].key),pushup(d);
		rt=merge(merge(a,b),merge(d,e));
	}
}
ll getres() {
	int a,b;
	splitbysize(rt,t[rt].sz-1,a,b);
	ll tmp=t[b].f;
	rt=merge(a,b);
	return tmp;
}
int main() {
    n = read();
	for(int i = 1; i <= n; ++i) a[i] = read();

	rt=Newnode(0,a[1]),t[rt].tms=0x3f3f3f3f;

    int pre = a[1];
    for(int i = 2; i <= n; ++i) {
        pre = max(pre, a[i]);
        func(a[i], j);
        reset();
    }

	ll ans = getres();
	for(int i = 1; i <= n; ++i) ans -= a[i];
	printf("%lld\n",ans);
	return 0;
}
/*
9
44 43 42 41 33 66 32 11 5
*/

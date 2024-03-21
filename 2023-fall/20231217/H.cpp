#include <bits/stdc++.h>

using namespace std;
const int maxn = 1000010;
int n ; 
char s[maxn];
int a[maxn],aval[maxn];
//queue<int> q[maxn];
int head[maxn * 23];
int listnxt[maxn * 23];
int q[maxn * 23];
int cnt;
//int fa[maxn],sz[maxn],r[maxn];
//int getf(int x){
//	if(fa[x] == x) return x;
//	return fa[x] = getf(fa[x]);
//} void del(int x){
//	if(x == n)
//	fa[x] = n + 1;
//	else {
//		int fy = getf(x + 1);
//		if(sz[x] < sz[fy]) fa[x] = fy;
//		else fa[fy] = x,r[x] = max(r[x],r[fy]);
//	}
//} int nxt(int x){
//	return r[getf(x)];
//}
int nxt[maxn],prv[maxn];
int tree[maxn];
void add(int x,int val){
    for(;x <= n;x += x & -x) tree[x] += val;
} int qry(int x){ int ret = 0;
    for(;x;x -= x & -x) ret += tree[x];
    return ret;
}
void del(int x){
    add(x,-1);
    aval[x] = 0;
    nxt[prv[x]] = nxt[x];
    prv[nxt[x]] = prv[x];
} void DelRecursion(int x,int len){
    if(x == n + 1) return;
    if(len == 1) {
        del(x);
        return;
    } DelRecursion(nxt[x],len - 1);
    del(x);
} 

void modify(int x,int len){
    int lstr = prv[x];
    DelRecursion(x,len);
    int pos = lstr;
    if(pos == 0) return;
    for(int i = 1;i < len && pos != 0;++i) pos = prv[pos];
    if(pos == 0) pos = nxt[pos];
    int r = pos;
    int nowval = a[pos];
//	cerr << "@@@" << lstr << " " << pos << endl;
    for(int i = 1;i < len && r != n + 1;++i) {
        r = nxt[r];
        nowval = nowval * 2 + a[r];
    } while(r != n + 1 && pos != lstr){
//		cerr << pos << " " << r << " " << nowval << endl;
        aval[pos] = nowval;
//		q[nowval].push(pos);
        listnxt[++cnt] = head[nowval];
        head[nowval] = cnt;
        q[cnt] = pos;
//		cerr << pos << " " << r << " " << nowval << endl;
        nowval -= (1 << (len - 1)) * a[pos];
        pos = nxt[pos],r = nxt[r];
        nowval = nowval * 2 + a[r];
    } 
    
    while(r == n + 1 && pos != lstr) {
//		cerr << pos << endl;
        aval[pos] = 0;
        pos = nxt[pos];
    } if(pos == lstr && r == n + 1) aval[pos] = 0;
    else {
        aval[pos] = nowval;
//		q[nowval].push(pos);
        listnxt[++cnt] = head[nowval];
        head[nowval] = cnt;
        q[cnt] = pos;
    }
} 
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> s + 1;
    for(int i = 1;i <= n;++i) a[i] = s[i] - '0';
    for(int i = 1;i <= n;++i) add(i,1);
    for(int i = 0;i <= n;++i) nxt[i] = i + 1;
    for(int i = 1;i <= n + 1;++i) prv[i] = i - 1;
    int bit = 0;
    for(int i = 1;i <= n;++i){
        cnt = 0;
//		cerr << "!!!" << i << endl;
//		for(int j = 1;j <= n;++j) cerr << aval[j] << " " ;
//		cerr << endl;
        if(i == (1 << bit)) {
//			cerr << "???" << endl;
//			cerr << bit << endl;
            ++bit;
            for(int j = 1;j <= n;++j) aval[j] = 0;
            int l = nxt[0],r = l,nowval = a[l];
            for(int j = 1;j < bit && r != n + 1;++j) {
                r = nxt[r];
                nowval = nowval * 2 + a[r];
            } 
//			cerr << r << " " << nowval << endl;
            while(r != n + 1) {
//				cerr << l << " " << r << " " << nowval << endl;
                aval[l] = nowval;
//				cerr << l << " " << r << endl;

//				q[nowval].push(l);
//				cerr << "Insertion " << nowval << " " << l << endl; 
                listnxt[++cnt] = head[nowval];
                head[nowval] = cnt;
                q[cnt] = l;
//				cerr << l << " " << r << endl;
                nowval -= (1 << (bit - 1)) * a[l];
                l = nxt[l],r = nxt[r];
                nowval = nowval * 2 + a[r];
            } 
            
            
//			for(int j = 1;j <= n;++j) cerr << aval[j] << " " ;
//			cerr << endl; 
//			cerr << "__________________" << endl;
        } 
//		cerr << "!!!" << endl;
        int minpos = n + 1,num = 0;
        int id = head[i];
        while(id != 0){
//			cerr << id << " " << q[id] << " " << listnxt[id] << endl;
            int x = q[id];
            id = listnxt[id];
            if(aval[x] == i) minpos = min(minpos,x),++num,aval[x] = 0;
        } 
//		cerr << "_____________________" << endl;

//		cerr << "!!!" << i << endl;
        if(minpos == n + 1) puts("-1 0");
        else {
            cout << qry(minpos) << " " << num << endl;
            modify(minpos,bit);
        }
        
    } 
    return 0;
    
}

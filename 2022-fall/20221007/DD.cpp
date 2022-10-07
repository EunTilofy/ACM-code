#include<bits/stdc++.h>
#define ll long long
//#define int long long
#define db double
#define ld long double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
#define inf 0x3f3f3f3f
#define infL 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
const int MN = 3e5 + 5;
int n, m;
struct edge {int x, y;} e[MN];
struct info {
	int sizid, size_ori;
	int faid;
	int block_ori;
} _[MN];
struct que {
	int S;
	int a[4];
	int ans;
} q[MN];
bool in[MN][2];
int block, siz[MN], fa[MN];

int getf(int x) {
	if(fa[x] == x) return x;
	return getf(fa[x]);
}

void _union(int id) {
	int x = e[id].x;
	int y = e[id].y;
//	dbg3(union); dbg1(x); dbg2(y);
	x = getf(x);
	y = getf(y);
	if(siz[x]>siz[y]) swap(x,y);
	if(x == y) {
		_[id] = (info) {
			0, 0, 0, block
		};
		return ;
	}
	_[id] = (info) {
		y, siz[y], x, block
	};
	siz[y] += siz[x];
	fa[x] = y;
	--block;
}

void _break(int id) {
//	dbg3(break); dbg1(e[id].x); dbg2(e[id].y);
	if(_[id].sizid) siz[_[id].sizid] = _[id].size_ori;
	if(_[id].faid) fa[_[id].faid] = _[id].faid;
	block = _[id].block_ori;
}

void solve(int l, int r) {
	if(l == r) {
		q[l].ans = block;
//		dbg1(l); dbg2(block);
		return;
	}
	int mid = (l + r) >> 1;
	REP(i, l, mid + 1) REP(j, 0, q[i].S) in[q[i].a[j]][0] = 1;
	REP(i, mid + 1, r + 1) REP(j, 0, q[i].S) in[q[i].a[j]][1] = 1;
	
	std::vector<int> addid;
	
	REP(i, l, mid + 1) REP(j, 0, q[i].S) {
		if(in[q[i].a[j]][0] && !in[q[i].a[j]][1])
			_union(q[i].a[j]), in[q[i].a[j]][0] = 0, addid.push_back(q[i].a[j]);
	}
	REP(i, l, mid + 1) REP(j, 0, q[i].S) in[q[i].a[j]][0] = 0;
	REP(i, mid + 1, r + 1) REP(j, 0, q[i].S) in[q[i].a[j]][1] = 0;
	solve(mid + 1, r);
	
	while(addid.size()) _break(addid.back()), addid.pop_back();
	
	REP(i, l, mid + 1) REP(j, 0, q[i].S) in[q[i].a[j]][0] = 1;
	REP(i, mid + 1, r + 1) REP(j, 0, q[i].S) in[q[i].a[j]][1] = 1;
	REP(i, mid + 1, r + 1) REP(j, 0, q[i].S) {
		if(in[q[i].a[j]][1] && !in[q[i].a[j]][0]) _union(q[i].a[j]), in[q[i].a[j]][1] = 0, addid.push_back(q[i].a[j]);
	}
	REP(i, l, mid + 1) REP(j, 0, q[i].S) in[q[i].a[j]][0] = 0;
	REP(i, mid + 1, r + 1) REP(j, 0, q[i].S) in[q[i].a[j]][1] = 0;
	
	solve(l, mid);
	
	while(addid.size()) _break(addid.back()), addid.pop_back();
}

bool inori[MN];

signed main() {
	freopen("disconnected.in", "r", stdin);
	freopen("disconnected.out", "w", stdout);
	n = read(), m = read();
	REP(i, 1, m + 1) {
		e[i].x = read();
		e[i].y = read();
	}
	int Q = read();
	REP(i, 1, Q + 1) {
		q[i].S = read();
		REP(j, 0, q[i].S) inori[q[i].a[j] = read()] = 1;
	}
	block = n;
	REP(i, 1, n + 1) fa[i] = i, siz[i] = 1;
	REP(i, 1, m + 1) if(!inori[i]) _union(i);
//	dbg3(---------------------);
	solve(1, Q);
	REP(i, 1, Q + 1) {
		if(q[i].ans == 1) printf("Connected\n");
		else printf("Disconnected\n");
	}
	return 0;
}
/*
4 5
1 2
2 3
3 4
4 1
2 4
3
1 5
2 2 3
2 1 2

4 6
1 2
2 3
3 4
4 1
1 3
2 4
4
1 1
2 5 6
3 1 4 5
4 1 3 5 6

7 9
6 2
3 7
3 5
5 7
5 6
4 6
3 2
1 4
1 3
3
2 4 9 
3 1 4 6 
4 6 7 9 8 
*/
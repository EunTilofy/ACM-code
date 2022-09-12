#include<bits/stdc++.h>
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define mod 998244353
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 6e5 + 10;
vector<int> g[MN], p[MN], b[MN], qx, qy, qz;
vector<pair<int, int>> q;
int a[MN], mk[MN], fa[MN];

void add(int pos, int x, int f) {
	for(int i = 0; i < b[x].size(); ++i) {
		int id = b[x][i];
		if(mk[id]) continue;
		mk[id] = 1;
//		printf("id = %d\n", id);
		if((a[id * 2] == x) ^ f) p[pos].push_back(id * 2 - 1), p[pos].push_back(id * 2);
		else p[pos].push_back(id * 2), p[pos].push_back(id * 2 - 1);
	}
}

int main() {
	int n = read();
	for(int i = 1; i <= 2 * n; ++i) a[i] = read();
	for(int i = 1; i <= 2 * n; i += 2) {
		if(a[i] == a[i + 1]) g[a[i]].push_back((i + 1) / 2);
		else b[a[i]].push_back((i + 1) / 2), b[a[i + 1]].push_back((i + 1) / 2);	
	}
//	puts("XXX");
	for(int i = 1; i <= 2 * n; ++i) {
		if(g[i].size()) q.push_back(make_pair(g[i].size(), i));
	}
	sort(q.begin(), q.end());
	
	int sum = 0, mxid = 0, res = 0;
	if(q.size()) {
		sum = 0, mxid = q[q.size() - 1].second;
		for(int i = 0; i < q.size(); ++i) sum += q[i].first;
		res = max(0, 2 * q[q.size() - 1].fi - sum);
//		puts("XXXX");
		int cnt = 0, sz = q.size();
		for(int i = 0; i < q[sz - 1].first; ++i) {
			p[++cnt].push_back(g[mxid][i]);
		}
	//	puts("??");
		int nw = 1;
		for(int i = 0; i < sz - 1; ++i) {
			for(int j = 0; j < q[i].first; ++j) {
				if(nw > cnt) nw = 1;
				int id = q[i].second;
				p[nw].push_back(g[id][j]);
				nw++;
			}
		}
	//	puts("!!!");
		for(int i = 1; i <= cnt - res; ++i) {
			for(int j = 0; j < p[i].size(); ++j) qx.push_back(p[i][j] * 2 - 1), qx.push_back(p[i][j] * 2);
		}
	//	printf("qx%d\n", qx.size());
		for(int i = 1; i <= res; ++i) fa[i] = p[cnt - i + 1][0];
	//	printf("res%d %d\n", res, fa[1]);
		for(int i = 1; i <= cnt; ++i) p[i].clear();
	}
	int pos = 0, flg = 0;
	for(int i = 1; i <= 2 * n; i += 2) {
		if(a[i] != a[i + 1] && !mk[i / 2 + 1]) {
//			printf("i = %d\n", i);
			mk[i / 2 + 1] = 1;
			++pos;
			add(pos, a[i], 1);
			if(a[i] == mxid && !flg) {
				flg = 1;
				for(int j = 0; j < qx.size(); ++j) p[pos].push_back(qx[j]);
			}
			p[pos].push_back(i), p[pos].push_back(i + 1);
//			printf("qy%d\n", qy.size());
//			for(int j = 0; j < qy.size(); ++j) printf("%d ", qy[j]);
//			puts("");
			add(pos, a[i + 1], 0);
			if(a[i + 1] == mxid && !flg) {
				flg = 1;
				for(int j = qx.size() - 1; j >= 0; --j) p[pos].push_back(qx[j]);
			}
//			printf("qy%d\n", qy.size());
//			for(int j = 0; j < qy.size(); ++j) printf("%d ", qy[j]);
//			puts("");
		}
	}
	
	for(int i = 1; i <= pos; ++i) 
		for(int j = 0; j < p[i].size(); ++j) qy.push_back(p[i][j]);
//	printf("qy%d\n", qy.size());
//	for(int i = 0; i < qy.size(); ++i) printf("%d ", qy[i]);
//	puts("");
	if(!flg) for(int j = 0; j < qx.size(); ++j) qy.push_back(qx[j]);
	for(int i = 0; i + 1 < qy.size(); i += 2) {
		qz.push_back(qy[i]), qz.push_back(qy[i + 1]);
		if(i + 2 >= qy.size() || a[qy[i + 1]] == mxid || a[qy[i + 2]] == mxid || !res) continue;
		qz.push_back(fa[res] * 2 - 1), qz.push_back(fa[res] * 2);
		res--;
	}
	if(res && qy.size() && a[qy[0]] != mxid && a[qy[qy.size() - 1]] != mxid) {
		qz.push_back(fa[res] * 2 - 1), qz.push_back(fa[res] * 2);
	}
	if(res && !qy.size()) qz.push_back(fa[res] * 2 - 1), qz.push_back(fa[res] * 2);
	printf("%d\n", qz.size() / 2);
	for(int i = 0; i < qz.size(); ++i) printf("%d ", qz[i]);
	puts("");
	return 0;
}
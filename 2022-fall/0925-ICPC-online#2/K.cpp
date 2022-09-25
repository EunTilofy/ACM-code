#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
#define ll long long
//#define int long long
#define dbg1(x) cerr<<#x<<'='<<(x)<<" "
#define dbg2(x) cerr<<#x<<'='<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define MN 1000005
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
int n;
bool sq[255][255], ci[255][255], fi[255][255];
#define P 998244353
int ans1, ans2;
int Add(int x, int y){return (x + y) % P;}
#define SQ(x,y) (sq[x+120][y+120])
#define CI(x,y) (ci[x+120][y+120])
int main() {
	n = read();
	REP(i, 1, n + 1) {
		// dbg3(xxxx);
		int op = read();
		int x = read();
		int y = read();
		if(op == 1) {
			sq[x + 120][y + 120] = 1;
			fi[x + 120][y + 120] = 1;
			fi[x + 120][y - 1 + 120] = 1;
			fi[x - 1 + 120][y + 120] = 1;
			fi[x - 1 + 120][y - 1 + 120] = 1;
		}
		else {
			ci[x + 120][y + 120] = 1;
		}
		// dbg3(yyyy);
	}
	// dbg3(---------);
	int inv3=332748118;
	int inv2=499122177;
	REP(i, -105, 105) REP(j, -105, 105) {
	// REP(i, -10, 10) REP(j, -10, 10) {
		if(!fi[i+120][j+120]) {
			if(CI(i,j)&&CI(i+1,j+1));
			else if(CI(i+1,j)&&CI(i,j+1));
			else{
				int nm = 0;
				nm += CI(i,j);
				nm += CI(i+1,j);
				nm += CI(i,j+1);
				nm += CI(i+1,j+1);
				if(nm == 1) ans2 = Add(ans2, inv2);// , dbg3(add2);
				if(nm == 2) ans2 = Add(ans2, inv3); //, dbg3(add3);
			}
		}
		//up
		if(!SQ(i,j)&&!SQ(i,j+1)&&!CI(i,j)&&!CI(i,j+1))
			ans1 = Add(ans1, (((SQ(i-1,j))|(SQ(i-1,j+1)))^((SQ(i+1,j))|(SQ(i+1,j+1))))); 
		//left
		if(!SQ(i,j)&&!SQ(i+1,j)&&!CI(i,j)&&!CI(i+1,j))
			ans1 = Add(ans1, (((SQ(i,j-1))|(SQ(i+1,j-1)))^((SQ(i,j+1))|(SQ(i+1,j+1))))); 
		//down
		if(!SQ(i+1,j)&&!SQ(i+1,j+1)&&!CI(i+1,j)&&!CI(i+1,j+1))
			ans1 = Add(ans1, (((SQ(i,j))|(SQ(i,j+1)))^((SQ(i+2,j))|(SQ(i+2,j+1))))); 
		//right
		if(!SQ(i,j+1)&&!SQ(i+1,j+1)&&!CI(i,j+1)&&!CI(i+1,j+1))
			ans1 = Add(ans1, (((SQ(i,j))|(SQ(i+1,j)))^((SQ(i,j+2))|(SQ(i+1,j+2))))); 
	}
	ans1 = 1ll * ans1 * inv2 % P;
	printf("%d %d\n", ans1, ans2);
	return 0;
}
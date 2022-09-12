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
//S:h1:m1:s1:h2:m2:s2
//123456789123456789
int h1,m1,s1,h2,m2,s2;
int main() {
    while(1) {
        int n = read();
        if(!n) break;
        int num = 0;
        while(n --) {
            // dbg2(num);
            if(getchar() == 'D') {
                // 9:30
                h1 = read(); m1 = read(); s1 = read();
                h2 = read(); m2 = read(); s2 = read();
                // dbg1(h1);dbg1(m1);dbg2(s1);
                // dbg1(h2);dbg1(m2);dbg2(s2);
                if(h1>9||(h1==9&&m1>30)||(h1==9&&m1==30&&s1>0)) {++num;continue;}
                if(h1<8||(h1==8&&m1<30)) {h1 = 8; m1 = 30; s1 = 0;}
                h1+=8;
                if(h1>h2||(h1==h2&&m1>m2)||(h1==h2&&m1==m2&&s1>s2)) {++num;continue;}
            }
            else {
                //12:30
                h1 = read(); m1 = read(); s1 = read();
                h2 = read(); m2 = read(); s2 = read();
                // dbg1(h1);dbg1(m1);dbg2(s1);
                // dbg1(h2);dbg1(m2);dbg2(s2);
                if(h1>12||(h1==12&&m1>30)||(h1==12&&m1==30&&s1>0)) {++num;continue;}
                if(h1<8||(h1==8&&m1<30)) {h1 = 8; m1 = 30; s1 = 0;}
                h1+=9;
                if(h1>h2||(h1==h2&&m1>m2)||(h1==h2&&m1==m2&&s1>s2)) {++num;continue;}
            }
        }
        if(num == 0) puts("All OK");
        else if(num <= 3) printf("%d Point(s) Deducted\n", num);
        else puts("Issue Show Cause Letter");
    }
    return 0;
}

/*
3
D:8:30:00:17:30:20
D:9:30:01:17:30:20
E:11:30:01:20:31:00
3
D:8:30:00:16:30:00
D:9:30:00:17:30:20
E:11:30:01:20:31:00
3
D:8:30:00:17:30:20
D:9:30:01:17:30:20
E:11:30:01:20:00:00
4
D:8:00:00:16:15:20
D:9:30:01:17:30:00
E:11:30:01:20:00:00
E:11:30:01:20:00:00
0
*/
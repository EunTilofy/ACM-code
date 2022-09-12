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
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define FOr(i,a,b) for(int i=(a);i>=(b);--i)
#define y1 y11111111111
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
const int MN = 1e6 + 5;
// int a[MN], b[MN], c[MN], n, m;
char s[MN];
int n;
string a[MN], b;
int nm[MN], c[MN];
int tot;
const string STR[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
string getstr(int x) {
    if(x < 16) return STR[x];
    return getstr(x / 16) + STR[x % 16];
}
signed main() {
    // freopen("H.in", "r", stdin);
    // freopen("H.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    while(scanf("%s", s + 1) != EOF) {
        // dbg2(s + 1);
        n = strlen(s + 1);
        tot = 0;
        REP(i, 1, n + 1) {
            int j = i;
            while(j + 1 <= n && s[j + 1] == s[i]) ++j;
            ++tot;
            a[tot] = s[i];
            int num = j - i + 1;
            if(num > 1) {
                a[tot] += getstr(num);
            }
            nm[tot] = num;
            i = j;
        }
        int mxdec = 0;

        REP(i, 1, tot + 1) {
            if(nm[i] == 1) c[i] = 1, b[0] = '\0';
            else {
                int num = nm[i] - 1;
                b = a[i][0];
                if(num > 1) b += getstr(num);
                c[i] = a[i].size() - b.size();
            }
            mxdec = max(mxdec, c[i]);
        }

        // REP(i, 1, tot + 1) dbg1(b[i]), dbg2(c[i]); 


        int id = -1;
        REP(i, 1, tot + 1) if(c[i] == mxdec){
            bool fl = 0;
            if(nm[i] == 1) b[0] = '\0';
            else {
                int num = nm[i] - 1;
                b = a[i][0];
                if(num > 1) b += getstr(num);
            }
            if(nm[i] > 1) {
                if(i < tot && mxdec > 0) fl |= (b + a[i + 1][0] < a[i]);
                else fl |= b < a[i];
            }
            else {
                fl |= (i == tot || (i < tot && a[i + 1][0] < a[i][0]));
            }
            if(fl) {id = i;break;}
        }
        if(id == -1) {
            DREP(i, tot, 0) if(c[i] == mxdec && mxdec > 0) {id = i; break;}
        }

        REP(i, 1, tot + 1) {
            if(id == i) {
                if(nm[i] > 1) {
                    b = a[i][0];
                    if(nm[i] - 1 > 1) b += getstr(nm[i] - 1);
                    cout<<b;
                }
            }
            else cout<<a[i];
        }
        std::cout<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
#define ll long long
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
const int MN = 1e7 + 1;
long long ans[MN], mi[MN], pr[MN], tot, aa[MN], bb[MN];
bool mk[MN];
void init()
{
	reg int i, j;
	for(i = 2; i < MN; ++i)
	{
		if(!mk[i]) {
            pr[++tot] = i;
            mi[i] = i;
        }
		for(j = 1; j <= tot && pr[j] * i <= MN; ++j)
		{
			mi[pr[j] * i] = pr[j];
            mk[pr[j] * i] = 1;
			if(i % pr[j] == 0) break;
		}
	}
}
bool pd(int x)
{
	if(!mk[x]) {
        aa[x] = x;
        bb[x] = 1;
        return true;
    }
	
	int p = mi[x];
    if(aa[x / p] % p == 0) {
        aa[x] = aa[x / p / p];
        bb[x] = bb[x / p / p] * p;
    }
    else if(bb[x / p] % p == 0) {
        aa[x] = aa[x / p / p / p];
        bb[x] = bb[x / p / p / p];
    }
    else {
        aa[x] = aa[x / p] * p;
        bb[x] = bb[x / p];
    }
	return aa[x] > bb[x];
}
int main()
{
	init();
	reg int i, j;
	ans[1] = aa[1] = bb[1] = 1;
    for(i = 2; i < MN; ++i) {
        ans[i] = ans[i - 1];
        ans[i] += pd(i);
    }
    for(i = 1; i < MN; ++i) ans[i] = ans[i - 1] ^ ans[i] * i;
	int T = read();
	while(T--)
	{
	    printf("%lld\n",ans[read()]);
	}
    return 0;
}

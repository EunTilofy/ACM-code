#include<bits/stdc++.h>
using namespace std;
const int MX = 2097152;
struct comp {
	double r, i; comp(double _r = 0, double _i = 0) {r = _r; i = _i;}
	comp operator+(const comp x) {return comp(r+x.r, i+x.i);}
	comp operator-(const comp x) {return comp(r-x.r, i-x.i);}
	comp operator*(const comp x) {return comp(r*x.r-i*x.i,r*x.i+i*x.r);}
}a[MX<<1], b[MX<<1], c[MX<<1];
const double pi = acos(-1.);
void FFT(comp a[], int n, int t) {
	for(int i = 1,j = 0; i < n - 1; ++i) {
		for(int s=n;j^=s>>=1,~j&s;);
			if(i<j)swap(a[i], a[j]);
	}
	for(int d=0;(1<<d)<n;d++){
		int m=1<<d,m2=m<<1;
		double o=pi/m*t; comp _w(cos(o), sin(o));
		for(int i = 0;i < n; i += m2) {
			comp w(1,0);
			for(int j=0;j<m;++j) {
				comp &A=a[i+j+m], &B=a[i+j],t=w*A;
				A=B-t;B=B+t;w=w*_w;
			}
		}
	}
	if(t==-1)for(int i=0;i<n;++i)a[i].r/=n;
}
const int MN = 1e6+6;
long long ans[MN], aa[MN], num[MN];
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n; cin>>n;
	for(int i = 1; i <= n; ++i) {
		cin>>aa[i];
		aa[i] += aa[i-1];
	}
	int q; cin>>q;
	std::vector<pair<long long, int>> que(q);
	for(int i = 0; i < q; ++i) cin>>que[i].first, que[i].second=i+1;
	std::sort(que.begin(), que.end());
	for(int i = 1;i <= n; ++i) {
		int j = i;
		while(aa[j]-aa[i-1]==0&&j<=n) ++j;
		int len = j - i;
		num[0] += 1ll * len * (len + 1) / 2;
		i = j;
	}
	for(int i = 0; i <= n; ++i) {
		a[aa[i]].r += 1.0;
		b[1000000-aa[i]].r += 1.0;
	}
	FFT(a, MX, 1);
	FFT(b, MX, 1);
	for(int i = 0; i < MX; ++i) c[i]=a[i]*b[i];
	FFT(c, MX, -1);
	for(int i = 1; i <= 1000000; ++i) {
		num[i] = (long long)(c[1000000+i].r+0.5);
//		cout<<i<<" "<<num[i]<<endl;
	}
	int val = 0;
	long long has = num[0];
	for(int i = 0; i < q; ++i) {
//		cout<<que[i].first<<" "<<que[i].second<<endl;
//		cout<<val<<" "<<has<<endl;
		while(has < que[i].first && val < 1000000) {
			++val;
			has += num[val];
		}
		ans[que[i].second] = val;
	}
	for(int i = 1; i <= q; ++i) cout<<ans[i]<<endl;
}
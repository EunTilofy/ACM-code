#include<bits/stdc++.h>
using namespace std;
int n, l, c;
const int Mod = 998244353;
const int MN = 1<<18;
int Add(int x,int y){return (x+y)%Mod;}
int Mul(int x,int y){return (1ll*x*y)%Mod;}
int fpow(int x, int y) {
	int r = 1;
	for(;y;y>>=1,x=Mul(x,x))if(y&1)r=Mul(r,x);
	return r;
}
int Inv(int x){return fpow(x, Mod-2);}
int Cal0(int x, int y) {
	if(x == 1) return Add(y, 1);
	return Mul(Add(fpow(x, y + 1), Mod-1), Inv(Add(x, Mod-1)));
}
int Cal1(int x, int y) {
	return Add(Cal0(x, y), Mod-1);
}
int f[MN], g[MN], h[MN], fac[MN], inv[MN], r[MN];

void dft(int *a, int n, int o){
	int i,j,k,p,x,y,w;
	for(int i = 1; i < n; ++i) if(i < r[i]) swap(a[i], a[r[i]]);
	for(i=1;i<n;i<<=1) {
		int wn=fpow(o==0?3:Inv(3), (Mod-1)/(i<<1));
		for(p=i<<1,j=0;j<n;j+=p) 
			for(k=0,w=1;k<i;++k,w=Mul(w,wn)){
			x=a[k+j];y=Mul(a[i+k+j],w);
			a[k+j]=Add(x,y);
			a[i+k+j]=Add(x,Mod-y);
		}
	}
	if(o){
		x=Inv(n);
		for(int i = 0;i < n; ++i) a[i]=Mul(a[i],x);
	}
}
void init() {
	int n = 1<<18;
	int b = __builtin_ctz(n)-1;
	for(int i = 1; i < n; ++i) r[i] = r[i>>1]>>1|(i&1)<<b; ++b;
	dft(f, n, 0);
	dft(g, n, 0);
	for(int i = 0; i < n; ++i) h[i] = Mul(f[i], g[i]);
	dft(h, n, 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> l >> c;
	if(c == 1) {
		for(int i = 1; i <= n; ++i) {
			cout << l << "\n";
		}
		return 0;
	}
	fac[0] = inv[0] = inv[1] = fac[1] = 1;
	for(int i = 2; i < MN; ++i) {
		fac[i] = Mul(fac[i-1], i);
		inv[i] = Mul(Mod-Mod/i, inv[Mod%i]);
	}
	for(int i = 2; i < MN; ++i) {
		inv[i] = Mul(inv[i-1], inv[i]);
	}
	f[0] = Cal1(c, l);
	f[1] = Mod - Cal1(1, l);
	for(int j = 2; j <= n; ++j) {
		f[j] = Cal1(Inv(fpow(c, j-1)), l);
		f[j] = Mul(f[j], inv[j]);
		if(j & 1) f[j] = Mod - f[j];
	}
	for(int i = 0; i <= n; ++i) g[i] = inv[i];
	for(int i = n+1; i; --i) f[i] = f[i-1], g[i]=g[i-1];f[0]=g[0]=0;

	init();

	int Pre = Mul(Add(fpow(c, l+1), Mod-c), Inv(Add(c, Mod-1)));

	for(int i = 1; i <= n; ++i) {
		int ans = Pre;
		ans = Add(ans, Mod - Mul(fac[i], h[i+2]));
		cout << ans << "\n";
	}

	return 0;
}

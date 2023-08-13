//#pragma GCC optimize("Ofast")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define all(n) n.begin(), n.end()
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<ll> vl;
typedef vector<vi> vvi;
inline ll read()
{
	int ch = getchar(), f = 1;
	ll x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar())
		if (ch == '-')
			f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		x = x * 10 + ch - '0';
	return f * x;
}

int solve();
int main()
{
	for (int t = 1; t--; solve())
		;
	return 0;
}

struct point
{
	int x, y;
	point operator-(const point &b) const
	{
		return {x - b.x, y - b.y};
	}
	point operator+(const point &b) const
	{
		return {x + b.x, y + b.y};
	}
	int operator*(const point &b) const
	{
		return x * b.x + y * b.y;
	}
	int operator^(const point &b) const
	{
		return x * b.y - y * b.x;
	}
};

struct hsh
{
	const static int maxn = 1000005;
	vector<int> hsh[1000005];
	void insert(long long x)
	{
		int pos = (x % maxn + maxn) % maxn;
		for (auto i : hsh[pos])
			if (i == x)
				return;
		hsh[pos].push_back(x);
	}
	int count(long long x)
	{
		int pos = (x % maxn + maxn) % maxn;
		for (auto i : hsh[pos])
			if (i == x)
				return 1;
		return 0;
	}
};
//hsh node;
unordered_set<long long> node;

const int maxn = 1005;
point a[maxn];

const double eps = 1e-8;
int toint(double x)
{
	if (fabs(x) < eps)
		return 0;
	if (x > 0)
		return (int)(x + eps);
	return (int)(x - eps);
}
int isint(double x)
{
	if (fabs(toint(x) - x) < eps)
		return 1;
	return 0;
}
int solve()
{
	int n = read();
	for (int i = 1; i <= n; ++i)
	{
		int x = read() * 2, y = read() * 2;
		a[i] = {x, y};
		node.insert(1ll * x * 100000 + y);
	}
	srand(time(0));
	// random_shuffle(a+1,a+n+1);
	if (n == 1)
	{
		return puts("0");
	}
	int ans = n;
	for (int i = 1; i <= 3; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			point mid_point = {(a[i].x + a[j].x) / 2, (a[i].y + a[j].y) / 2};
			int cnt = 0;
			for (int k = 1; k <= n; ++k)
			{
				if (k == i || k == j)
					continue;
				point symetric_point = mid_point + (mid_point - a[k]);
				int nx = toint(symetric_point.x);
				int ny = toint(symetric_point.y);
				if (node.count(1ll * nx * 100000 + ny))
					continue;
				++cnt;
				if(cnt>ans)break;
			}
			ans = min(ans, cnt);
			cnt = 0;
			point symetric_line = {a[i].y - a[j].y, a[j].x - a[i].x};
			for (int k = 1; k <= n; ++k)
			{
				if (k == i || k == j)
					continue;
				double len = (a[k] - a[i]) * symetric_line / sqrt(symetric_line * symetric_line);
				double x = mid_point.x + symetric_line.x * len / sqrt(symetric_line * symetric_line);
				if (!isint(x))
				{
					++cnt;
					continue;
				}
				double y = mid_point.y + symetric_line.y * len / sqrt(symetric_line * symetric_line);
				if (!isint(y))
				{
					++cnt;
					continue;
				}
				point symetric_point = {toint(x), toint(y)};
				point another_symetric_point = symetric_point + (symetric_point - a[k]);
				int nx = toint(another_symetric_point.x);
				int ny = toint(another_symetric_point.y);
				if (node.count(1ll * nx * 100000 + ny))
					continue;
				++cnt;
				if(cnt>ans)break;
			}
			ans = min(ans, cnt);
			
		}
	}
	cout << ans << endl;
	return 0;
}
/*


4
10 0
0 10
0 0
1 1

2
1 0
1010 -1010





*/

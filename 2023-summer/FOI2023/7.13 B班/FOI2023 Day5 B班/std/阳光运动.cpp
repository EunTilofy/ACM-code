#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 15, M = 210, mod = 998244353;
inline void inc(int& x,int y) {
    x = x + y >= mod ? x + y - mod : x + y;
}

int n, m, x, y, z, L, R;
typedef pair<int, int> pii;
vector<pii> e[N];
inline void adde(int x, int y, int z){
	e[x].push_back(pii(y, z));
}
int f[1<<N][M][N];
int main(){
	ios::sync_with_stdio(0);
	cin >> n >> m >> L >> R;
	for(int i = 1; i <= m; ++i)
        cin >> x >> y >> z, adde(x, y, z), adde(y, x, z);
	
    int all = (1<<(n+1)) - 1;
	f[1][0][0] = 1;
	for(int S = 1; S <= all; ++S)
		for(int i = 0; i <= R; ++i)
			for(int u = 0; u <= n; ++u) if(f[S][i][u])
				for(auto& [v,w] : e[u]) if(i + w <= R)
					inc(f[S|1<<v][i+w][v], f[S][i][u]);
	int ans = 0;
	for(int i = L; i <= R; ++i)
        inc(ans, f[all][i][0]);
	cout << ans << endl;
    return 0;
}
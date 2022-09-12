#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n;
struct Point{
    double x, y;
}p[145];
int cnt;
typedef double NUM;
const NUM EPS = 1e-12, MAGIC = 2.71828e18;

struct VEC{
    double x, y;
}NOVEC = {MAGIC, MAGIC}, ans;
inline NUM cmp(NUM a, NUM b) {
    return fabs(a - b) >= EPS + fabs(a) * EPS? a - b : 0;
}
inline NUM cmp(VEC a, VEC b) {
    NUM at = cmp(a.x, b.x);
    return !at ? cmp(a.y, b.y) : at;
}
VEC operator + (VEC a, VEC b){return (VEC){a.x + b.x, a.y + b.y};}
VEC operator - (VEC a, VEC b){return (VEC){a.x - b.x, a.y - b.y};}
VEC operator * (VEC a, NUM b){return (VEC){a.x * b, a.y * b};}
VEC operator / (VEC a, NUM b){return (VEC){a.x / b, a.y / b};}
NUM operator * (VEC a, VEC b){return a.x * b.y - a.y * b.x;}
bool operator == (VEC a, VEC b) {return !cmp(a, b);}
struct RAY{
    VEC u, v;
};
NUM cmp_side(const VEC &a, const VEC &b) {
    return cmp(a.x * b.y, +a.y * b.x);
}
VEC inter(const RAY &a, const RAY &b) {
    VEC s = a.u - a.v, t = b.u - b.v;
    NUM at = cmp_side(s, t);
    if(!at) return NOVEC;
    return a.u + s * ((b.u - a.u) * t / at);
}
bool in[145];
bool chk(int a, int b, int c, int d) {
    VEC v1 = (VEC){p[a].x, p[a].y};
    VEC v2 = (VEC){p[b].x, p[b].y};
    VEC v3 = (VEC){p[c].x, p[c].y};
    VEC v4 = (VEC){p[d].x, p[d].y};
    RAY l1 = (RAY){v1, v2};
    RAY l2 = (RAY){v3, v4};
    if(!cmp_side(v1-v2, v3-v4)) return 0; 
    VEC x = inter(l1, l2);
    int tot = 0;
        // printf("now_ (%.2lf, %.2lf)\n", x.x, x.y);
    if(cnt) {
        if(x == ans) return 0;
    }
    memset(in, 0, sizeof in);
    for(int i = 1; i <= n * 2; ++i) if(!in[i] && i != a && i != b && i != c && i != d){
        int flag = -1;
        VEC v5 = (VEC){p[i].x, p[i].y};
        for(int j = i + 1; j <= n * 2; ++j) if(!in[j] && j != a && j != b && j != c && j != d){
            VEC v6 = (VEC){p[j].x, p[j].y};
            RAY l3 = (RAY){v5, v6};
            if(cmp_side(v1-v2, v5 - v6)) {
                VEC y = inter(l1,l3);
                if(x == y) {
                    if(flag != -1) {return 0;}
                    flag = j; 
                }
            }
        }
        if(flag == -1) return 0;
        in[i] = in[flag] = 1; ++tot;
    }
    if(tot + 2 == n) {
        ans = x;
        // printf("(%.2lf %.2lf)\n", ans.x, ans.y);
        return 1;
    }
    return 0;
}
int main() {
    freopen("center.in", "r", stdin);
    freopen("center.out", "w", stdout);
    n = read();
    for(int i = 1; i <= n * 2; ++i) p[i].x = read(), p[i].y = read();
    for(int i = 3; i <= n * 2; ++i) for(int j = 3; j <= n * 2; ++j) if(i != j) {
        if(chk(1, i, 2, j)) {
            // printf("%d\n", cnt);
            if(cnt) {
                // printf(" == (%.2lf %.2lf)\n", ans.x, ans.y);
                return 0 * puts("Ambiguity");
            }
            else{
                // printf(" *** (%.2lf %.2lf)\n", ans.x, ans.y);
                ++cnt;
            }
        }
    }
    for(int j = 4; j <= n * 2; ++j) {
        if(chk(1, 2, 3, j)) {
            if(cnt) {
                // printf(" == (%.2lf %.2lf)\n", ans.x, ans.y);
                return 0 * puts("Ambiguity");
            }
            else {
                ++cnt;                    
            }
        }
    }
    if(cnt) {
        printf("Center of the universe found at (%.10lf, %.10lf)", ans.x, ans.y);
    }
    else puts("Impossible");
}
/*
2
0 0
1 1
1 0
0 1
*/
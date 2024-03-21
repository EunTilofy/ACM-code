#include<bits/stdc++.h>
using namespace std;

int W, H;
int a[100006];
int ID(int i, int j) {
    return (j-1)*W/2+i;
}
bool chk(int x, int y, int xi, int yi, int xj, int yj) {
    long long v1 = 1ll*x*yi-1ll*y*xi;
    long long v2 = 1ll*x*yj-1ll*y*xj;
    return (v1>0&&v2<0)||(v1<0&&v2>0);
}
bool check(int x, int y, int xx, int yy, int u, int v, int uu, int vv) {
    return chk(xx-x, yy-y, u-x, v-y, uu-x, vv-y) && chk(uu-u, vv-v, x-u, y-v, xx-u, yy-v);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> W >> H;
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    double ans = sqrt(1ll*(sx-ex)*(sx-ex)+1ll*(sy-ey)*(sy-ey));

    vector<pair<int,pair<int,int>>> s;
    for(int i = 1; i <= H/2; ++i) {
        for(int j = 1; j <= W/2; ++j) {
            cin >> a[ID(j, i)];
            if(check(sx, sy, ex, ey, 2*j-2, 2*i-2, 2*j, 2*i)
                || check(sx, sy, ex, ey, 2*j, 2*i-2, 2*j-2, 2*i)
                || (j == (sx+1)/2 && i == (sy+1)/2)
                || (j == (ex+1)/2 && i == (ey+1)/2)) {
                    s.push_back({abs(j*2-1-sx)+abs(i*2-1-sy), {j, i}});
                }
        }
    }
    sort(s.begin(), s.end());

    for(int i = 0; i < s.size()-1; ++i) {
        auto [w, o] = s[i]; auto [x, y] = o;
        // cerr << x << " " << y << "\n";
        auto [ww, oo] = s[i+1]; auto [xx, yy] = oo;
        if(x==xx||y==yy) ans += abs(a[ID(xx, yy)]-a[ID(x, y)]);
        else {
            int h1 = a[ID(xx, yy)], h2 = a[ID(x, y)];
            int h3 = min(a[ID(x, yy)], a[ID(xx, y)]);
            if(h3 > h1 && h3 > h2) ans += abs(h3-h2)+abs(h3-h1);
            else ans += abs(h2-h1);
        }
    }
    cout << fixed << setprecision(10) << ans;
    return 0;
}
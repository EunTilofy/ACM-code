#include<bits/stdc++.h>
using namespace std;
int n;
typedef double NUM;
const NUM EPS = 1e-12;
inline NUM sqr(NUM a) {return a*a;}
inline NUM cmp(NUM a, NUM b){
    return fabs(a-b)>=EPS+fabs(a)*EPS?a-b:0;
}
struct VEC {NUM x, y;};
inline NUM cmp(VEC a, VEC b){
    NUM at = cmp(a.x, b.x);
    return !at?cmp(a.y,b.y):at;
}
NUM cmp_side(VEC &a, VEC &b){
    return cmp(a.x*b.y, +a.y*b.x);
}
VEC operator + (VEC x, VEC y){return (VEC){x.x+y.x, x.y+y.y};}
VEC operator - (VEC x, VEC y){return (VEC){x.x-y.x, x.y-y.y};}
bool operator < (VEC x, VEC y){return cmp(x, y)<0;}
bool operator == (VEC x, VEC y){return !cmp(x, y);}
vector<VEC> convex_hull(vector<VEC> u) {
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    vector<VEC> c;
    for(size_t i=0,o=1,m=1;~i;i+=o){
        while(c.size()>m){
            VEC a=c.back()-c[c.size()-2];
            VEC b=c.back()-u[i];
            if(cmp_side(a,b)<0) break;
            c.pop_back();
        }
        c.push_back(u[i]);
        if(i+1==u.size()) m=c.size(), o-=1;
    }
    c.pop_back();return c;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if(n==1) {
        cout << 4 << endl;
        return 0;
    }
    vector<VEC> a,b;
    vector<pair<int,int>> _a;
    NUM ans = 0;
    for(int i=1;i<=n;++i){
        int x,y;
        cin >> x >> y;
        _a.push_back({x, y});
        a.push_back((VEC){x+1.0, y*1.0});
        a.push_back((VEC){x-1.0, y*1.0});
        a.push_back((VEC){x*1.0, y-1.0});
        a.push_back((VEC){x*1.0, y+1.0});
    }
    for(int i = 1; i < _a.size(); ++i) _a[i] = {_a[i].first-_a[0].first, _a[i].second-_a[0].second};
    bool fl = 1, _1, _2;
    for(int i = 1; i < _a.size(); ++i) {
        if(!fl) break;
        fl &= abs(_a[i].first) == abs(_a[i].second);
        if(i == 1) _1 = _a[i].first>0, _2 = _a[i].second>0;
        fl &= ((_1^_2) == ((_a[i].first>0)^(_a[i].second>0)));
    }
    if(fl) ans += 1;
    b=convex_hull(a);
    for(int i=0;i<b.size();++i){
        int j=i-1;if(j<0)j+=b.size();
        ans+=max(fabs(b[j].x-b[i].x), fabs(b[j].y-b[i].y));
    }
    cout << fixed << setprecision(0) << ans << endl;
    return 0;
}
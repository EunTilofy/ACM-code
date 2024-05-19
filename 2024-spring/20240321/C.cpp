#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MN = 1e3 + 5;

namespace G {
    typedef long double db;
    typedef long long ll;
    #define T long long
    const db eps = 1e-10;
    #define all(x) (x).begin(), (x).end()
    inline int sgn (const ll &x) {
        if(x < 0) return -1;
        return x > 0;
    }
    inline int sgn (const db &x) {
        if(fabs(x) < eps) return 0;
        return x > 0 ? 1 : -1;
    }
    struct point {
        T x, y;
        point() {}
        point(T a, T b) : x(a), y(b) {}
        point operator + (const point &o) const {return point(x + o.x, y + o.y);}
        point operator - (const point &o) const {return point(x - o.x, y - o.y);}
        point operator / (const T o) const {return point(x / o, y / o);}
        T operator * (const point &o) const {return x*o.y - y*o.x;}
        T operator % (const point &o) const {return x*o.x + y*o.y;}
        db len() const {return sqrt((db)len2());}
        T len2() const {return x*x+y*y;}
        bool operator!=(const point &o) const {
            return x!=o.x||y!=o.y;
        }
        bool operator==(const point &o) const {
            return x==o.x&&y==o.y;
        }
    };
    bool operator<(const point& a, const point& b) {
        int s = sgn(a*b);
        return s>0||s==0&&sgn(a.len2()-b.len2())<0;
    }
    T dis2(const point& a, const point& b) {return (a-b).len2();}
    struct convex{
        vector<point> p;
        convex(vector<point> a);
        tuple<db, db, db> C() {
            T r = 0;
            db cx, cy;
            int n = p.size(), i, j;
            if(n<=2){
                for(i=0;i<n;++i)for(j=i+1;j<n;++j)r=max(r,dis2(p[i],p[j]));
                return {sqrt((double)r)/2.0, (p[0].x+p[1].x)/2.0, (p[0].y+p[1].y)/2.0};
            }
            p.push_back(p[0]);
            for (i=0,j=1;i<n;++i) {
                while((p[i+1]-p[i])*(p[j]-p[i])<=(p[i+1]-p[i])*(p[j+1]-p[i])) if(++j==n) j = 0;
                if(dis2(p[i], p[j]) > r) {
                    r = dis2(p[i], p[j]);
                    cx = (p[i].x+p[j].x)/2.0;
                    cy = (p[i].y+p[j].y)/2.0;
                }
                if(dis2(p[i+1], p[j]) > r) {
                    r = dis2(p[i+1], p[j]);
                    cx = (p[i].x+p[j].x)/2.0;
                    cy = (p[i].y+p[j].y)/2.0;
                }
            }
            p.pop_back();
            return {sqrt((db)r)/2.0, cx, cy};
        }
    };
    convex::convex(vector<point> a) {
        sort(all(a));
        a.erase(unique(a.begin(), a.end()), a.end());
        if(a.size()==1) {
            // cerr << "!!!\n";
            cout << "0 " << a[0].x << " " << a[0].y << "\n";
            exit(0);
        }
        if(a.size()==2) {
            cout << sqrt((db)dis2(a[0], a[1])) << " "<< (a[0].x+a[1].x)/2.0 << " " << (a[0].y+a[1].y)/2.0 << "\n";
            exit(0);
        }
        int n = a.size(), i;
        if(!n) return ;
        p = a;
        for(i=1;i<n;++i)if(p[i].x<p[0].x||p[i].x==p[0].x&&p[i].y<p[0].y) swap(p[0], p[i]);
        a.resize(0); a.reserve(n);
        for(i=1;i<n;++i) if(p[i]!=p[0]) a.push_back(p[i]-p[0]);
        sort(all(a));
        for(i=0;i<a.size();++i) a[i]=a[i]+p[0];
        point* st=p.data()-1;
        int tp=1;
        for(auto &v: a) {
            while(tp>1&&sgn((st[tp]-st[tp-1])*(v-st[tp-1]))<=0) --tp;
            st[++tp]=v;
        }
        p.resize(tp);
    }
};

using G::convex, G::point;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;
    vector<G::point> a(n);
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a[i] = G::point(x, y);
    }
    cin >> m;
    vector<G::point> b(m);
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        b[i] = G::point(x, y);
    }
    vector<point> _;
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
        _.push_back(b[j]-a[i]);
    }
    // if(n == 1 && m == 1) {
    //     cout << 0 << " " << b[0].x - a[0].x << " " << b[0].y - a[0].y << "\n";
    //     return 0;
    // }
    auto CX = G::convex(_);
    auto [_1, _2, _3] = CX.C();

    cout << fixed << setprecision(14) << _1 << " " << _2 << " " << _3 << "\n";
    return 0;
}
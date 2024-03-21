#include<bits/stdc++.h>
using namespace std;

const double eps=1e-10;

inline bool zero(double x) {
    return (x>0?x:-x)<eps;
}
inline int sgn(double x) {
    return (x>eps?1:(x+eps<0?-1:0));
}
inline double sqr(double x) {
    return x*x;
}
struct point3{
    double x, y, z;
    point3(double x, double y, double z) : x(x), y(y), z(z) {}
    point3() {}
    point3 operator+(const point3 &a) const {
        return point3(x+a.x, y+a.y, z+a.z);
    }
    point3 operator-(const point3 &a) const {
        return point3(x-a.x, y-a.y, z-a.z);
    }
    point3 operator*(const double &a) const {
        return point3(x*a, y*a, z*a);
    }
    point3 operator/(const double &a) const {
        return point3(x/a, y/a, z/a);
    }
    point3 operator*(const point3 &a) const {
        return point3(y*a.z-z*a.y, z*a.x-x*a.z, x*a.y-y*a.x);
    }
    double operator ^ (const point3 &a) const {
        return x*a.x+y*a.y+z*a.z;
    }
    double sqrlen() const {return sqr(x) + sqr(y) + sqr(z);}
    double len() const {return sqrt(sqrlen());}
};
ostream& operator<< (ostream& o, const point3 &x) {
    // o<<"(" <<x.x<<" "<<x.y<<" "<<x.z<<")";
    return o;
}
inline point3 pvec(const point3 &a, const point3 &b, const point3 &c) {
    // cerr << a << " " << b << " " << c << "pvec\n";
    // cerr << (point3)((a-b)*(b-c)) << "\n";
    return (a-b)*(b-c);
}
inline bool dotInplaneIn(const point3 &p, const point3 &a, const point3 &b, const point3 &c) {
    return zero(((a-b)*(a-c)).len()-((p-a)*(p-b)).len()-((p-b)*(p-c)).len()-((p-c)*(p-a)).len());
}
inline bool parallel(const point3 &u1, const point3 &u2, const point3 &v1, const point3& v2) {
    return zero(((u1-u2)*(v1-v2)).len());
}
inline bool parallel(const point3 &l1, const point3 &l2, const point3 &a, const point3 &b, const point3 &c) {
    return zero((l1-l2)^pvec(a, b, c));
}
point3 intersection(const point3 &u1, const point3 &u2, const point3 &v1, point3 &v2) {
    point3 p0=(u1-v1)*(v1-v2), p1=(u1-u2)*(v1-v2);
    return u1+(u2-u1)*(sgn(p0^p1)*sqrt(p0.sqrlen()/p1.sqrlen()));
}

point3 intersection(const point3 &l1, const point3 &l2, const point3 &a, const point3 &b, const point3 &c) {
    // cerr << l1 << " " << l2 << " " << a << " " << b << " " << c << "\n";
    point3 temp=pvec(a, b, c);
    // cerr << temp << "\n";
    // cerr << (temp^(a-l1)) << " " << (temp^(l2-l1)) << "\n";
    return l1+(l2-l1)*((temp^(a-l1))/(temp^(l2-l1)));
}
inline bool dotsOnplane(const point3 &a, const point3 &b, const point3 &c, const point3 &d) {
    return zero(pvec(a, b, c)^(d-a));
}
inline bool dotOnlineIn(const point3 &p, const point3 &l1, const point3 &l2) {
    return zero(((p-l1)*(p-l2)).len()) && (l1.x-p.x)*(l2.x-p.x)<eps && (l1.y-p.y)*(l2.y-p.y)<eps && (l1.z-p.z)*(l2.z-p.z)<eps;
}
vector<tuple<point3, point3, point3>> tri;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    tri.resize(n);
    for(auto &[a, b, c] : tri) cin>>a.x>>a.y>>a.z>>b.x>>b.y>>b.z>>c.x>>c.y>>c.z;
    point3 _(0,0,0);
    for(int i = 1; i <= m; ++i) {
        point3 vv,v; cin>>v.x>>v.y>>v.z;
        int id=-1;
        for(int j = 0; j < n; ++j) {
            auto [x, y, z] = tri[j];
            if(parallel(_, v, x, y, z)) {
                // if(dotsOnplane(_, v, x, y) && dotsOnplane(_, v, x, z) && dotsOnplane(_, v, y, z)) {
                //     vector<point3> tmp;
                //     if(!parallel(_, v, x, y)) {
                //         point3 xx = intersection(_, v, x, y);
                //         if(dotOnlineIn(xx, x, y)) if((v^xx)>=0) tmp.push_back(xx);
                //     }
                //     if(!parallel(_, v, x, z)) {
                //         point3 xx = intersection(_, v, x, z);
                //         if(dotOnlineIn(xx, x, z)) if((v^xx)>=0) tmp.push_back(xx);
                //     }
                //     if(!parallel(_, v, y, z)) {
                //         point3 xx = intersection(_, v, y, z);
                //         if(dotOnlineIn(xx, y, z)) if((v^xx)>=0) tmp.push_back(xx);
                //     }
                //     sort(tmp.begin(), tmp.end(), [&](const point3 &p, const point3 &q)->bool {
                //         return p.len() < q.len();
                //     });
                //     if(tmp.size() >= 1) {
                //         if(id==-1) id=j, vv=tmp[0];
                //         else if(vv.len() > tmp[0].len()) id=j, vv=tmp[0];
                //     }
                // }
            } else {
                // cerr << i << " " << j << "\n";
                point3 tmp = intersection(_, v, x, y, z);
                // cerr << tmp.x << " " << tmp.y << " " << tmp.z << "\n";
                // cerr << "find intersection : " << tmp << "\n";
                if((tmp^v)>=0 && dotInplaneIn(tmp, x, y, z)) {
                    if(id==-1) id=j, vv=tmp;
                    else if(vv.len() > tmp.len()) id=j, vv=tmp;
                }
            }
        }
        cout << id+1 << "\n";
    }
    return 0;
}
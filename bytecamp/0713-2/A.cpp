#include<bits/stdc++.h>
using namespace std;
const double O = 20106.1929829747;
double d(int x1, int y1, int x2, int y2) {
    return sqrt((double)(x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
#define db double
const db Pi = acos(-1);
db tri(db x1, db y1, db x2, db y2) {
    return fabs(x1 * y2 - x2 * y1) * 0.5;
}
double cal(db x1, db y1, db x2, db y2, db x3, db y3, db r) {
    db a = d(x1, y1, x2, y2);
    db b = d(x1, y1, x3, y3);
    db S = tri(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
    return 0.5 * r * r * asin(S * 2 / a / b) - S; 
}
double cal2(db x1, db y1, db x2, db y2, db x3, db y3, db r, db _) {
    if(max(y2, y3) <= _) return cal(x1, y1, x2, y2, x3, y3, r);
    else if (min(y2, y3) > r) return 0.0;
    if(y2 > y3) swap(x2, x3), swap(y2, y3);
    db x5, x6; // !!
    return tri(x6 - x5, 0, x2 - x5, y2 - _) + cal(x1, y1, x2, y2, x6, _, r); 
}
double cross_circle(int x1, int y1, int r1, int x2, int y2, int r2) {
    if(d(x1, y1, x2, y2) > (double) r1 + r2) return 0;
    double x3, y3, x4, y4;
    return cal(x1, y1, x3, y3, x4, y4, r1) + cal(x2, y2, x3, y3, x4, y4, r2);
}

double cross_circle_2(int x1, int y1, int r1, int x2, int y2, int r2) {
    if(d(x1, y1, x2, y2) > (double) r1 + r2) return 0;
    if(not_in(x2- r2, y2, x1, y1, r1) && not_in(x2 + r2, y2, x1, y1, r1)) {
        if(y2 < y1 - r1) 
    }
    double x3, y3, x4, y4; // !!
    return cal2(x1, y1, x3, y3, x4, y4, r1, y2) + cal2(x2, y2, x3, y3, x4, y4, r2, y2);
}
double cross_circle_3(int x1, int y1, int r1, int x2, int y2, int r2) {
    if(d(x1, y1, x2, y2) > (double) r1 + r2) return 0;
}
int main() {
    int x1, x2, y1, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    double ans = 2 * O - cross_circle(x1, y1, 100, x2, y2, 100);
    ans += cross_circle(x1, y1, 100, x2 - 40, y2 + 30, 30);
    ans += cross_circle(x1, y1, 100, x2 + 40, y2 + 30, 30);
    ans += cross_circle(x2, y2, 100, x1 - 40, y1 + 30, 30);
    ans += cross_circle(x2, y2, 100, x1 + 40, y1 + 30, 30);
    ans += cross_circle_2(x1, y1, 100, x2, y2 - 20, 60);
    ans += cross_circle_2(x2, y2, 100, x1, y1 - 20, 60);
    ans -= cross_circle(x1 - 40, y1 + 30, 30, x2 - 40, y2 + 30, 30);
    ans -= cross_circle(x1 + 40, y1 + 30, 30, x2 - 40, y2 + 30, 30);
    ans -= cross_circle(x1 - 40, y1 + 30, 30, x2 + 40, y2 + 30, 30);
    ans -= cross_circle(x1 + 40, y1 + 30, 30, x2 + 40, y2 + 30, 30);
    ans -= cross_circle_2(x1 - 40, y1 + 30, 30, x2, y2 - 20, 60);
    ans -= cross_circle_2(x1 + 40, y1 + 30, 30, x2, y2 - 20, 60);
    ans -= cross_circle_2(x2 - 40, y2 + 30, 30, x1, y1 - 20, 60);
    ans -= cross_circle_2(x2 + 40, y2 + 30, 30, x1, y1 - 20, 60);
    ans -= cross_circle_3(x2, y2 - 20, 60, x1, y1 - 20, 60);
    return 0 * printf("%lf\n", ans);
}
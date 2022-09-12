#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch <='9' && ch >='0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
#define int long long
int n, m; double S;
const double eps = 1e-12;
std::vector<pair<int, int> > A;
#define mkp make_pair
signed main() {
    n = read(), m = read();
    scanf("%lf", &S);
    long long SS = (long long)(S + 0.50000001);
    if(n * m < SS) return 0 * puts("-1");
    if(fabs(S - (int)S) < eps) {
        if(SS <= m) {
            A.push_back(mkp(0,0));
            A.push_back(mkp(0,SS));
            A.push_back(mkp(1,SS));
            A.push_back(mkp(1,0));
        }
        else {
            int Wid = SS / m; // Wid >= 1
            if(SS % m == 0) {
                A.push_back(mkp(0,0));
                A.push_back(mkp(0,m));
                A.push_back(mkp(Wid,m));
                A.push_back(mkp(Wid,0));
            }
            else {
                int R = m - SS % m;
                A.push_back(mkp(0,m));
                if(Wid + 1 > n) return 0 * puts("-1");
                A.push_back(mkp(Wid + 1, m));
                A.push_back(mkp(Wid + 1, R));
                A.push_back(mkp(Wid - 1,0));
                if(Wid > 1) A.push_back(mkp(0, 0));
            }
        }
    }
    else if(fabs(S - (int)S - 0.5) < eps) {
        if(SS <= m) {
            A.push_back(mkp(0,1));
            if(SS > 1) A.push_back(mkp(0,SS));
            A.push_back(mkp(1,SS));
            A.push_back(mkp(1,0));
        }
        else {
            int Wid = SS / m; // Wid >= 1
            if(SS % m == 0) {
                A.push_back(mkp(0,1));
                if(m > 1) A.push_back(mkp(0,m));
                A.push_back(mkp(Wid,m));
                A.push_back(mkp(Wid,0));
                if(Wid > 1) A.push_back(mkp(1,0));
            }
            else {
                int R = m - SS % m;
                if(Wid == 1) {
                    if(Wid + 1 > n) return 0 * puts("-1");
                    A.push_back(mkp(0,0));
                    A.push_back(mkp(0,m));
                    A.push_back(mkp(Wid, m));
                    A.push_back(mkp(Wid + 1, m - 1));
                    if(R != m - 1) A.push_back(mkp(Wid + 1, R));             
                }
                else {
                    if(Wid + 1 > n) return 0 * puts("-1");
                    A.push_back(mkp(0,1));
                    if(m > 1) A.push_back(mkp(0,m));
                    A.push_back(mkp(Wid + 1, m));
                    A.push_back(mkp(Wid + 1, R));
                    if(Wid > 2) A.push_back(mkp(Wid - 1,0));
                    A.push_back(mkp(1, 0));  
                }
            }
        }
    }
    else return 0 * puts("-1");
    printf("%lld\n", A.size());
    for(int i = 0; i < A.size(); ++i) printf("%lld %lld\n", A[i].first, A[i].second);
    return 0;
}
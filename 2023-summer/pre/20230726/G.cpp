#include<bits/stdc++.h>
using namespace std;

int n;
double x[1005], y[1005];

const double pi = acos(-1.);

double solve(int o) {
    double cir = (2*pi)/o;
    double beta = (pi - cir) / 2.0;

    double mn = 1e60, mx = 0;

    for(int i = 1; i <= n; ++i) {
        double lenn = sqrt(x[i]*x[i]+y[i]*y[i]);
        double alpha = atan2(y[i], x[i]);
        if(alpha < 0) alpha += 2 * pi;
        for(int j = 0; j <= o; ++j) if(j * cir >= alpha) {
            alpha = j * cir - alpha;
            break;
        }
        // cerr << alpha << "\n";
        if(alpha >= cir) alpha -= cir;
        double len = lenn / sin(beta) * sin(beta + alpha);


        mn = min(mn, len);
        mx = max(mx, len);
    }
    
    return (mn/mx)*(mn/mx);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }

    int ans = 3;
    double num = 0;
    for(int i = 3; i <= 8; ++i) {
        double res = solve(i);
        if(res >= num) ans = i, num = res;
    }
    cout << ans << " ";
    cout << fixed << setprecision(10) << num << "\n";
    return 0;
}
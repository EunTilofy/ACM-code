#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    double h, r, dw, da;
    cin >> h >> r >> dw >> da;
    double pos = sqrt(dw / da);
    double tmp = pos / (pos + 1.0) * h;
    cout << fixed << setprecision(10) << tmp << "\n";
    return 0;
}
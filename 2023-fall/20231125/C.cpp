#include<bits/stdc++.h>
using namespace std;

#define ll long long
long long solve(long long x, long long y) {
    if(x == 0 && y == 0) return 0;
    if(x == 0) {
        return 6ll*(ll)(y/3)+(ll)(y%3==2?4ll:0);
    } else if(y == 0) {
        return (ll)(x/3)*3ll+(ll)(x%3==2?1ll:0);
    }
    if(x>y) return 2ll*y+solve(x-y, 0);
    else return 2ll*x+solve(0, y-x);
}

int main() {
    int _, x, y;
    cin >> x >> y;
    cout << solve(x, y) << "\n";
    return 0;
}
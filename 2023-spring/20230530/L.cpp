#include<bits/stdc++.h>
using namespace std;
#define cin std::cin
#define cout std::cout
#define cerr std::cerr

typedef pair<int, int> pii;
#define ll long long

int n, x, y;

vector<pair<pair<int,int>,pair<int,int>>> ans;

void sol(int x, int y, int r) {
    int posx = (x == 0) ? 1 : n;
    int posy = (y == 0) ? 1 : n;
    int _x = n - posx + 1;
    int _y = n - posy + 1;
    int dy = (y == 0) ? 1 : -1;
    int dx = (x == 0) ? 1 : -1;
    for(int i = 0; i < r; ++i) {
        ans.push_back({{posx + i * dx, posy + i * dy}, {_x - posx- i * dx, _y - posy- i * dy}});
        // ans.push_back({{_x, posy + i * dy}, {posx + i * dx, _y}});
    } 
}

void sol2(int x, int y, int r, int p) {
    int posx = (x == 0) ? 1 : n;
    int posy = (y == 0) ? 1 : n;
    int dy = (y == 0) ? 1 : -1;
    int dx = (x == 0) ? 1 : -1;
    int _x = n - posx + 1 - dx * p;
    int _y = n - posy + 1 - dy * p;
    for(int i = 0; i < r; ++i) {
        ans.push_back({{posx + i * dx, posy + i * dy},{_x - posx - i * dx, _y - posy - i * dy}});
        // ans.push_back({{_x, posy + i * dy}, {posx + i * dx, _y}});
    } 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> x >> y;

    int a = x - 1, b = n - x, c = y - 1, d = n - y;

    if(a <= b) {
        if(c <= d) {
            sol(0, 0, min(a, c));
            sol2(1, 1, min(b, d), min(a, c));
            int ac = min(a, c), bd = min(b, d);
            a -= ac;
            c -= ac;
            b -= bd;
            d -= bd;
        }
        else{
            sol(0, 1, min(a, d));
            sol2(1, 0, min(b, c), min(a, d));
            int ad = min(a, d), bc = min(b, c);
            a -= ad;
            d -= ad;
            b -= bc;
            c -= bc;
            // cerr << "!!!" << b << " " << c << endl;
        }
    }
    else {
        if(c <= d) {
            sol(1, 0, min(b, c));
            sol2(0, 1, min(a, d), min(b, c));
            int ad = min(a, d), bc = min(b, c);
            a -= ad;
            d -= ad;
            b -= bc;
            c -= bc;
        }
        else {
            sol(1, 1, min(b, d));
            sol2(0, 0, min(a, c), min(b, d));
            int ac = min(a, c), bd = min(b, d);
            a -= ac;
            c -= ac;
            b -= bd;
            d -= bd;
        }
    }

    // for(auto &[x, y] : ans) {
    //     cout << x.first << " " << x.second << " " << y.first << " " << y.second << "\n";
    // }
    // cerr << a << b << c << d << endl;
    if(a != 0) {
        if(c != 0) {
            // right down
            assert(a == c);
            for(int i = 1; i <= c; ++i) {
                ans.push_back({{x-i, y-i},{i, i}});
                // ans.push_back({{x, y-i},{x-i, y}});
            }
        } else {
            // left down
            assert(a == d);
            for(int i = 1; i <= d; ++i) {
                ans.push_back({{x-i, y+i},{i, -i}});
                // ans.push_back({{x, y+i},{x-i, y}});
            }
        }
    } else if(b != 0) {
        if(c != 0) {
            assert(b == c);
            for(int i = 1; i <= c; ++i) {
                ans.push_back({{x+i, y-i},{-i, i}});
                // ans.push_back({{x, y-i},{x+i, y}});
            }
        } else {
            assert(b == d);
            for(int i = 1; i <= d; ++i) {
                ans.push_back({{x+i, y+i},{-i, -i}});
                // ans.push_back({{x, y+i},{x+i, y}});
            }
        }
    }

    cout << "Yes\n" << ans.size() << "\n";
    for(auto &[x, y] : ans) {
        cout << x.first << " " << x.second << " " << y.first << " " << y.second << "\n";
    }
    return 0;
}
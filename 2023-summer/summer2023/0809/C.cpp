#include<bits/stdc++.h>
using namespace std;

void print(int x) {
    if(x < 10) cout << "0" << x;
    else cout << x;
}

const int N = 3010;
struct node {
    int x, y, id;
}a[N];

bool cmp(node A, node B) {
    return (A.x == B.x) ? A.y < B.y : A.x < B.x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        n *= 3;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i].x >> a[i].y;
            a[i].id = i;
        }
        sort(a + 1, a + 1 + n, cmp);
        for(int i = 1; i <= n; i += 3) {
            cout << a[i].id << " " << a[i + 1].id << " " << a[i + 2].id << "\n";
        }
    }
}
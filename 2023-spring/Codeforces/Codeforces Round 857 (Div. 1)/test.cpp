#include<bits/stdc++.h>
using namespace std;
long long a[203][203];
long long get(int x, int y){
    return a[x][y]^a[x+1][y]^a[x][y+1]^a[x+1][y+1];
}
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; ++i, cout << endl) for(int j = 1; j < m; ++j) cout << (a[i][j]^a[i][j+1]) << " ";
    for(int i = 1; i < n; ++i, cout << endl) for(int j = 1; j <= m; ++j) cout << (a[i][j]^a[i+1][j]) << " ";
    bool chk = 1;
    for(int i = 1; i+3 <= n; ++i)for(int j=1;j+3<=m;++j){

        chk&=get(i,j)==get(i+2,j+2);
        chk&=get(i,j+2)==get(i+2,j);
    }
    cout << endl << chk << endl;
    return 0;
}
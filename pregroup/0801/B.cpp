#include<bits/stdc++.h>
using namespace std;
bool _[200000015];
char a[2][5][3];
int main() {
    freopen("beaver.in","r",stdin);
    freopen("beaver.out","w",stdout);
    int now = 100000004, mood = 0;
    for(int j = 0; j < 5; ++j)
    for(int i = 0; i < 2; ++i) scanf("%s", a[i][j]);

    for(int i = 1; i <= 77000000; ++i) {
        bool tree = _[now];
      //  printf("%d %d\n", tree, mood);
        _[now] = a[tree][mood][0] - '0';
        if(a[tree][mood][1] == 'R') ++now;
        else --now;
        if(a[tree][mood][2] == 'H') return 0 * puts("happy beaver");
        mood = a[tree][mood][2] - 'A';
    }
    return 0 * puts("unhappy beaver");
}
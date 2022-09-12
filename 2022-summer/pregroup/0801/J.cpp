#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int xx[1005], yy[1005], num[1005];

int main() {
    freopen("knights.in", "r", stdin);
    freopen("knights.out", "w", stdout);
    int n = read();
    while(n != 0) {
        int cnt1 = 0, cnt3 = 0, cnt4 = 0;
        int num1 = 1000000;
        int num2 = 1000000;
        int a = 0, b = 0, c = 0;
        for(int i = 1; i <= n; ++i) {
            xx[i] = read(); yy[i] = read();
            int x = xx[i], y = yy[i];
            if(x < 2 || y < 1) ++cnt3;
            if(x < 1 || y < 2) ++cnt4;
            if(x >= 2 && y >= 1 && (x - 2 < 1 || y - 1 < 2)) ++cnt1;
            int num = min(x / 3, y / 3);
            x -= 3 * num;
            y -= 3 * num;
            if(x == 1 && y > 1) {++b; num1 = min(num1, num);}
            else if(y == 1 && x > 1) ++a;
            else if(x > 1 && y > 1) ++c;
        }
        if(cnt3) puts("Peter wins the game");
        else if(cnt4 || cnt1) puts("Andrew wins the game");
        else {
            int A = a + (c + 1) / 2;
            int B = b + c / 2;
            if(A >= B) puts("Andrew wins the game");
            else puts("Peter wins the game");
        }
        n = read();
    }
    return 0;
}
//Andrew wins the game
//Peter wins the game
/*
2
2 2
2 3
1
4 4
0
*/
#include<bits/stdc++.h>
using namespace std;

const int MN = 1e6 + 3;

int n, ton[1000003], mx[1000003];

int main() {
    // freopen("1.txt", "r", stdin);
    // freopen("2.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    if(n==1) {
        int x;
        cin >> x;
        cout << x;
        return 0;
    }
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x, ton[x] ++;
    }

    int pre = 0;
    mx[MN-1]=MN-1;
    for(int i = MN-2; ~i; --i) {
        if(ton[i]>ton[mx[i+1]]) mx[i] = i;
        else mx[i] = mx[i+1];
    }
    int j1 = 0, j2 = 0;
    while(ton[j1]==0&&j2+1<MN)++j1;
    j2=j1+1;
    while(ton[j2]==0&&j2+1<MN)++j2;
    // if(ton[j2]==0) {
    //     cout << "-1";
    //     return 0;
    // }
    if(ton[mx[0]] * 2 - 1 > n) {
        cout << "-1";
        return 0;
    }
    for(int i = 1; i <= n; ++i) {
        if(j2+1<MN){
            if(ton[mx[j2+1]] > ton[mx[pre]]) mx[pre]=mx[j2+1];
        }
        if(ton[mx[pre]]*2-1==n-i+1) {
            for(int j=i,jj=j1;j<=n;++j){
                if((j-i)%2==0){
                    cout<<mx[pre]<<" ";
                    --ton[mx[pre]];
                }
                else{
                    while(ton[jj]==0&&jj+1<MN){
                        ++jj;
                    }
                    if(jj==mx[pre]){
                        ++jj;
                        while(ton[jj]==0&&jj+1<MN){
                            ++jj;
                        }
                    }
                    cout<<jj<<" ";
                    --ton[jj];
                }
            }
            return 0;
        }

        while(ton[j1]==0&&j2+1<MN)++j1;
        if(j2<=j1) j2=j1+1;
        while(ton[j2]==0&&j2+1<MN)++j2;
        if(pre==j1)cout<<j2<<" ",pre=j2,--ton[j2];
        else cout<<j1<<" ",pre=j1,--ton[j1];
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool yes[2004];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        int l=(i-1+n)%n,r=(i+1)%n;
        while(a[l].second == a[i].second) l = (l - 1 + n) % n;
        if(a[l].second < a[i].second ) continue;
        while(a[r].second == a[i].second) r = (r + 1) % n;
        if(a[r].second < a[i].second) continue;

        bool FL = 1;
        for(int j=(l+1)%n;j!=r;j=(j+1)%n) if(yes[j]) FL = 0;
        if(FL == 0) continue;

        if((l+1)%n == (r+n-1)%n) {
            if((ll)(a[l].first-a[i].first)*(a[r].second-a[i].second)-(ll)(a[l].second-a[i].second)*(a[r].first-a[i].first) < 0) {
                yes[i] = 1; ++ans;
            }
        } else if(a[(l+1)%n].first < a[(r+n-1)%n].first) {
            yes[i] = 1; ++ans;
        }

        // int cnt = 0;
        // long double x3, y3;
        // int ID1 = i, ID2;
        // if(a[(i+n-1)%n].first!=a[i].first&&a[(i+n-1)%n].second==a[i].second){
        //     if(a[(i+n-1)%n].first<a[i].first) x3=(double)a[i].first-0.5;
        //     else x3=(double)a[i].first+0.5;
        //     y3=(double)(a[(i+n-1)%n].second-a[i].second)/(double)(a[(i+n-1)%n].first-a[i].first)*(x3-a[i].first)+(double)a[i].second;
        //     ID2 = (i+n-1)%n;
        // }else if(a[(i+1)%n].second == a[i].second){
        //     if(a[(i+1)%n].first<a[i].first) x3=(double)a[i].first-0.5;
        //     else x3=(double)a[i].first+0.5;
        //     y3=(double)(a[(i+1)%n].second-a[i].second)/(double)(a[(i+1)%n].first-a[i].first)*(x3-a[i].first)+(double)a[i].second;
        //     ID2 = (i+1)%n;
        // } else if(a[(i+n-1)%n].first!=a[i].first){
        //     if(a[(i+n-1)%n].first<a[i].first) x3=(double)a[i].first-0.5;
        //     else x3=(double)a[i].first+0.5;
        //     y3=(double)(a[(i+n-1)%n].second-a[i].second)/(double)(a[(i+n-1)%n].first-a[i].first)*(x3-a[i].first)+(double)a[i].second;
        //     ID2 = (i+n-1)%n;
        // }else{
        //     if(a[(i+1)%n].first<a[i].first) x3=(double)a[i].first-0.5;
        //     else x3=(double)a[i].first+0.5;
        //     y3=(double)(a[(i+1)%n].second-a[i].second)/(double)(a[(i+1)%n].first-a[i].first)*(x3-a[i].first)+(double)a[i].second;
        //     ID2 = (i+1)%n;
        // }
        // // cerr << x3 << " " << y3 << "\n";
        // for(int j=0;j<n;++j){
        //     int id1=j,id2=(j+1)%n;
        //     if(!(id1 == ID1 && id2 == ID2)&&!(id1==ID2 && id2==ID1)) {
        //         if(min(a[id1].first,a[id2].first)<x3 && max(a[id1].first,a[id2].first)>x3) {
        //             if(a[id2].first < a[id1].first) swap(id1, id2);
        //                 // cerr << (a[i].first-a[id1].first)*(a[id2].second-a[id1].second) << "\n";
        //                 // cerr << (a[id2].first-a[id1].first)*(a[i].second-a[id1].second) << "\n";
        //             if((double)(x3-a[id1].first)*(a[id2].second-a[id1].second)
        //                 > (double)(a[id2].first-a[id1].first)*(y3-a[id1].second)) {
        //                     ++cnt;
        //                         // cerr << "add!" <<endl;
        //                 }
        //         }
        //     } 
        // }
        // if(cnt%2==1) yes[i]=1, ++ans;
        // cerr << cnt << "\n";
    }
    cout << ans << "\n";
}
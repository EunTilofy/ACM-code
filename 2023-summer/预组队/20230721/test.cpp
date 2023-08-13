#include<bits/stdc++.h>
using namespace std;
int c[16],tmp[16];
int a[16],b[16];
bool vis[16];
int found=-1;
void solve(int now){
    // cerr<<now<<endl;
    if(now == 15) {
        if(found==-1){
            found=1;
            for(int i =1;i<=15;++i)c[i]=tmp[i];
            // for(int i = 1; i <= 10; ++i) cerr<<c[i]<<" ";cerr<<"\n";
        }
        else {
            for(int i = 1; i <= 15; ++i) {
                if(tmp[i]>c[i]) return;
                if(tmp[i]<c[i]) break;
            }
            for(int i =1;i<=15;++i)c[i]=tmp[i];
        }
        // for(int i = 1; i <= 10; ++i) cerr<<c[i]<<" ";cerr<<"\n";
        return;
    }
    for(int i=1;i<=15;++i)if(vis[i]==0){
        if(now==0||a[i]!=tmp[now]){
            if(vis[i]==1)continue;
            vis[i]=1;
            tmp[now+1]=a[i];
            solve(now+1);
            vis[i]=0;
        }
    }
}
int main() {
    srand(time(NULL));
    system("g++ G.cpp -o G --std=c++20");
    while(1){
        ofstream out; out.open("1.txt");
        out << 15 << "\n";
        for(int i = 1; i <= 15; ++i) out << (a[i]=rand()%6+1) << " ";
        out.close();
        system("./G < 1.txt > 2.txt");
        ifstream in; in.open("2.txt");
        int ans=1;
        for(int i = 1; i <= 15; ++i){
            in>>b[i];
            if(b[i]==-1){
                ans=-1;
                break;
            }
        }
        in.close();
        found=-1;
        for(int i=1;i<=15;++i) vis[i]=0;
        solve(0);
        if(found==-1&&ans!=-1) {
            cout<<"NO";
            break;
        } else if(found!=-1&&ans==-1){
            cout<<"NO";
            break;
        }
        if(found==-1&&ans==-1);
        else {
        for(int i=1;i<=15;++i)if(b[i]!=c[i]){
            cout<<"NO"<<endl;
            for(int j=1;j<=15;++j)cout<<a[j]<<" ";cout<<"\n";
            for(int j=1;j<=15;++j)cout<<c[j]<<" ";cout<<"\n";
            for(int j=1;j<=15;++j)cout<<b[j]<<" ";cout<<"\n";
            return 0;
        }}
        cout<<"Pass!"<<"\n";
    }
}
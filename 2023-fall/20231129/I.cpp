#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&m,&n);
        vector<pair<int,int>>a(n+1);
        for(int i=1;i<=n;i++){
            scanf("%d%d",&a[i].first,&a[i].second);
        }
            sort(a.begin()+1,a.begin()+1+n);
            int fl=1;
            for(int i=1;i<=n;i++){
                if(i==1){
                    if(a[i].first<a[i].second){
                        fl=0;
                        break;
                    }
                }
                else{
                    if(a[i].first-a[i].second!=a[i-1].first-a[i-1].second){
                        if(a[i-1].second==0){
                            if(a[i].first-a[i].second<a[i-1].first){
                                fl=0;
                                break;
                            }
                        }
                        else{
                            if(a[i].first-a[i].second<=a[i-1].first){
                            //    cout<<i<<" no "<<endl;
                                fl=0;
                                break;
                            }
                        }
                    }
                }
            }
            if(fl){
                puts("Yes");
            }
            else puts("No");

        }
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        vector<double>s;
        for(int i=1;i<=n;i++){
            double a,b,p;
            scanf("%lf%lf%lf",&a,&b,&p);
            double x=a+b*p;
            s.push_back(x);
        }
        sort(s.begin(),s.end());
        double cur=0,ans=0;
        for(auto v:s){
            cur+=v;
            ans+=cur;
        }
        printf("%.10lf\n",ans);
    }
}
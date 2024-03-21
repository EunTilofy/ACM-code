#include<bits/stdc++.h>
using namespace std;
void print(vector<int>&a){
    for(auto v:a){
        cout<<v<<" ";
    }
    cout<<endl;
}
void brute(vector<int>a){
    int n=a.size();
    int T=20;
    while(T--){
        for(int i=0;i<n;i++){
            if(a[i]==0&&a[(i+1)%n]==1)swap(a[i],a[i+1]);
        }
    }
}
const int N=1e7+5;
char s[N];
int main(){
    int T;
    while(T--){
        scanf("%s",s);
        int n=strlen(s);
        vector<int>a(n);
        for(int i=0;i<n;i++)a[i]=s[i]=='1';
        int cnt=0;
        for(auto v:a)cnt+=v;
        if(cnt<(n-cnt)){
            for(auto &v:a)v^=1;
            reverse(a.begin(),a.end());
        }
        pair<int,int> pos={n+1,-1};
        int cur=0;
        for(int i=0;i<n;i++){
            if(a[i]==0)a[i]--;
            else a[i]++;
            pos=min(pos,{cur,i});

        }
        rotate(a.begin(),a.begin()+pos.first,a.end());
        int cur_len=0,mx=0,cnt_0=0,cnt_1=0,res=0;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                cnt_0++;
                if(i!=0&&a[i]!=a[i-1]){
                    res=max(res,min(cnt_0,cnt_1));
                    if(cnt_0>cnt_1){
                        vector<int>b;
                        while(cnt_0&&cnt_1){
                            b.push_back(0);
                            b.push_back(1);
                            

                        }
                    }
                }
            }
            else if(a[i]==1){
                cnt_1++;
            }
        }

    }
    
}
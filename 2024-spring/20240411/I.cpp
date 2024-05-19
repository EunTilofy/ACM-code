#include<bits/stdc++.h>
using namespace std;
const int N=5003;
int cnt[N],cnt2[N];
vector<int>s[N];
int vis[N];
int n,a[N];
int b[N];
char d[N];
int c[N];
vector<string>t;
int get(char c){
    if(c>='a'&&c<='z')return c-'a';
    else return c-'A'+26;
}
bool check(){
    for(int i=1;i<n*n;i++)c[i]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)c[i*j]++;
    }
    for(int i=0;i<n;i++)b[a[i]]=i;
    for(auto v:t){
        int x=get(v[0]),y=get(v[1]);
        c[b[x]*n+b[y]]--;
    }
    for(int i=0;i<n*n;i++)if(c[i]!=0)return 0;
    for(int i=0;i<n;i++){
        if(i<26)d[b[i]]=i+'a';
        else d[b[i]]=i-26+'A';
    }
    for(int i=0;i<n;i++)putchar(d[i]);puts("");
    return 1;
}
int dfs(int cur){
    if(cur==n){
        if(check())return 1;
    }
    for(auto x:s[cnt[cur]]){
        if(!vis[x]){
            vis[x]=1;
            a[cur]=x;
            if(dfs(cur+1)){
                vis[x]=0;
                return 1;
            }
            vis[x]=0;
        }

    }
    return 0;
}
int cnt0[N];
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        t.clear();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cnt[i*j/n]++;
            }
        }
        for(int i=1;i<=n*n;i++){
            string s;
            cin>>s;
            t.push_back(s);
            if(s.size()==1)cnt0[get(s[0])]++;
        }
        int mx=0;
        for(int i=0;i<n;i++)mx=max(mx,cnt0[i]);
        char zero=0;
        for(int i=0;i<n;i++)if(cnt0[i]==mx){
            if(i<26)zero=i+'a';
            else zero=i-26+'A';
        }
        for(auto &s:t){
            if(s.size()==1)s=zero+s;
            int x=get(s[0]),y=get(s[1]);
            cnt2[x]++;
        }
        for(int i=0;i<n;i++){
            s[cnt2[i]].push_back(i);
        }
        dfs(0);
        for(int i=0;i<n;i++){
            s[cnt2[i]].clear();
        }
        for(int i=0;i<n;i++){
            cnt[i]=0,cnt0[i]=0;cnt2[i]=0;vis[i]=0;a[i]=b[i]=c[i]=d[i]=0;
        }
        t.clear();
    }

}
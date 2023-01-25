#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pli pair<long long,int>
#define pll pair<long long,long long>
#define pil pair<int, long long>
#define inf 1023456789
#define linf 1023456789123456789

using namespace std;

inline int read(){
    int ret=0,ff=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') ff=-1;ch=getchar();}
    while(isdigit(ch)){ret=ret*10+(ch^48);ch=getchar();}
    return ret*ff;
}

struct node{
    int son[15];
}tre[1000005];

int t, a[50004][15], n, m, cnt, b[105];

inline void insert(int p[]){
    int now = 1;
    for(int i = 1; i <= m; i++){
        if(tre[now].son[p[i]]){
            now = tre[now].son[p[i]];
        }
        else {
            tre[now].son[p[i]] = ++cnt;
            now = tre[now].son[p[i]];
        }
    }
}

inline void get(int p[]){
    int now = 1;
    for(int i = 1; i <= m; i++){
        if(tre[now].son[p[i]]){
            now = tre[now].son[p[i]];
        }
        else {
            printf("%d ",i-1);
            return;
        }
    }
    printf("%d ",m);
    return ;
}

inline void del(int p){
    for(int i = 1; i <= m; i++) {
        if(tre[p].son[i]){
            del(tre[p].son[i]);
            tre[p].son[i] = 0;
        }
    }
}

int main(){
    t = read();
    while(t--){
        cnt = 1;
        n = read();
        m = read();
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                a[i][read()] = j;
            }
            insert(a[i]);
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                b[a[i][j]] = j;
                
            }
            get(b);
        }
        del(1);
        puts("");
    }
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
struct node {
    int x, y, id;
} c[N];
int n;
vector<int> p[N];
int a[N], b[N];

bool cmp(node A, node B) {
    return (A.x != B.x) ? (A.x < B.x) : (A.y < B.y);
}
int id(int x,int tp){
    return (tp-1)*(n-1)+x;
}
int lst[N];
vector<int>e[4*N];
void add(int x,int y){
   // cout<<"add "<<x<<" "<<y<<endl;
    e[x].push_back(y);
}
int indec=0,dfn[4*N],low[4*N],f[4*N];
int in[4*N],st[4*N],top=0,cc=0;
void tarjan(int x){
   // cout<<"tarjan "<<x<<endl;
    dfn[x]=low[x]=++indec;
    in[x]=1;st[++top]=x;
    for(auto v:e[x]){
        if(dfn[v]){
            if(in[v])low[x]=min(low[x],low[v]);
        }
        else {
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }
    }
    if(dfn[x]==low[x]){
        ++cc;
      //  cout<<"cc! "<<cc<<" "<<st[top]<<endl;
        do{
            f[st[top]]=cc;
            in[st[top]]=0;

        }while(st[top--]!=x);
    }
  //  cout<<"col "<<x<<" "<<dfn[x]<<" "<<low[x]<<"  "<<f[x]<<endl;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        if(i > 1) c[i - 1] = {a[i - 1], a[i], i - 1};
    }
    
    sort(c + 1, c + n, cmp);
    int pos = 0;
    for(int i = 1; i < n; ++i) {
        if(i == 1) b[c[i].id] = i;
        else if((c[i - 1].x == c[i].x) && (c[i - 1].y == c[i].y)) b[c[i].id] = b[c[i - 1].id];
        else b[c[i].id] = i;
    }
   // for(int i=1;i<n;i++)cout<<b[i]<<" ";cout<<endl;
  //  for(int i=1;i<n;i++)b[i]=1;
  //  n=3;
    for(int i = 1; i < n; ++i) p[b[i]].push_back(i);
    
    // add(id(1,2),id(1,1));
    // add(id(n-1,2),id(n-1,1));
    // add(id(1,2),id(1,4));
    // add(id(n-1,2),id(n-1,3));
    for(int i = 2; i < n; ++i) add(id(1, 2), id(i, 2));
    for(int i = 1; i < n - 1; ++i) add(id(n - 1, 2), id(i, 2));
    for(int i = 1; i < n; ++i) {
        if(i - 1) add(id(i, 2), id(i - 1, 1));
        if(i + 1 < n) add(id(i, 2), id(i + 1, 1));
    }
    for(int i=1;i<n;i++){
        if(lst[b[i]]){
            add(id(i,3),id(lst[b[i]],3));
            add(id(i,1),id(lst[b[i]],3));
        }
        // if(i-1){
        //     add(id(i,2),id(i-1,1));
        //     add(id(i-1,2),id(i,1));
        // }
        add(id(i,3),id(i,2));
        
        lst[b[i]]=i;
    }
    for(int i=1;i<=n;i++)lst[i]=n+1;
    for(int i=n-1;i>=1;i--){
        if(lst[b[i]]<=n){
            add(id(i,4),id(lst[b[i]],4));
            add(id(i,1),id(lst[b[i]],4));
        }
        // if(i+1<n){
        //     add(id(i,2),id(i+1,1));
        //     add(id(i+1,2),id(i,1));
        // }
        
        add(id(i,4),id(i,2));
        lst[b[i]]=i;
    }
    for(int i=1;i<=4*n;i++){
        if(!dfn[i])tarjan(i);
    }
    vector<int>ans;
 //   for(int i=1;i<4*n;i++){
 //       cout<<i<<" "<<f[i]<<endl;
 //   }
    for(int i=1;i<n;i++){
        if(f[id(i,1)]==f[id(i,2)]){
            puts("NO");
            return 0;
        }
        else{
            if(f[id(i,1)]<f[id(i,2)]){
                ans.push_back(i);
            }
        }
    }
    printf("%d\n",ans.size());
    for(auto v:ans){
        printf("%d ",v);
    }
    return 0;
}
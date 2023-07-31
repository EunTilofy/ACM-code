#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;
char s[100005];
ll readInt(char* &p,int v)
{
    int flg = 1 , led = 0;
    ll num = 0;
    int num_dig = 0;
    char* q = p;
    for(int i = 0; 1;i++) {
        if(p[i] == '-') {
            if(i == 0 && flg == 1) flg = -1;
            else break;
            q = p + i;
        }
        else if(('0' <= p[i] && p[i] <= '9') || p[i] == '?') {
            int nv;
            if('0' <= p[i] && p[i] <= '9') nv = p[i] - '0';
            else nv = v;
            if(nv == 0 && num == 0) led += 1;
            num = num * 10 + nv;
            q = p + i;
            num_dig++;
        }
        else break;
    }
    p = q + 1;
    if(led > 1) p = NULL;
    if(num != 0 && led >= 1) p = NULL;
    if(flg == -1 && led >= 1) p = NULL;
    return num * flg;
}
void solve()
{
    scanf("%s",s+1);
    bool ff = 0;
    bool in[10];
    for(int i = 0; i < 10; ++i) in[i]=0;
    int len = strlen(s+1);
    for(int i = 1; i <= len; ++i) if(s[i]<='9'&&s[i]>='0') in[s[i]-'0']=1;
    for(int i = 0;i <= 9;i++) if(!in[i]){
        char *p = s + 1;
        ll n1,n2,n3;
        char op;
        n1 = readInt(p , i);
        if(!p) continue ;
        op = p[0] ; p++;
        n2 = readInt(p , i);
        if(!p) continue;
        p++;
        n3 = readInt(p , i);
        if(!p) continue;
        if(op == '+' && n1 + n2 == n3) {
            ff = 1; printf("%d\n",i) ; break;
        }
        if(op == '-' && n1 - n2 == n3) {
            ff = 1; printf("%d\n",i) ; break;
        }
        if(op == '*' && n1 * n2 == n3) {
            ff = 1; printf("%d\n",i) ; break;
        }
    }
    if(!ff) {
        printf("-1\n") ; return;
    }
}
int main() {
  //  freopen("in.txt","r",stdin);
  //  freopen("out2.txt","w",stdout);
    //ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0);
    int t;scanf("%d",&t);
    while(t--) solve();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch <='9' && ch >='0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
const int N = 1e6 + 5;
int f[10005], id[10005];
class AC_automaton {
    private:
        int tr[N][26],cnt,e[N],fail[N];
    public:
        void insert(char *s, int id)
        {
            int p=0;
            for(int i=0;s[i];i++)
            {
                int k=s[i]-'a';
                if(!tr[p][k])tr[p][k]=++cnt;
                p=tr[p][k];
            }
            e[p] = id;
        }
        void build()
        {
            queue<int>q;
            memset(fail,0,sizeof(fail));
            for(int i=0;i<26;i++)if(tr[0][i])q.push(tr[0][i]);
            while(!q.empty())
            {
                int k=q.front();q.pop();
                for(int i=0;i<26;i++)
                    if(tr[k][i])
                        fail[tr[k][i]]=tr[fail[k]][i],q.push(tr[k][i]);
                    else tr[k][i]=tr[fail[k]][i];
            }
        }
        int query(char *t, int len, int id)
        {
            static bool v[10005];
            memset(v, 0, sizeof v);
            f[id] = 1; int p = 0;
            for(int i = 0; i < len; i++)
            {
                p = tr[p][t[i] - 'a'];
                for(int j = p; j && (!v[e[j]] || e[j] == 0); j = fail[j]) {
                    if(e[j] && e[j] != id) f[id] = max(f[id], f[e[j]] + 1);
                    if(e[j]) v[e[j]] = 1;
                }
            }
            return f[id];
        }
}ac;
char s[N];
int l[N], r[N];
bool cmp(int x, int y){return r[x] - l[x] < r[y] - l[y];}
int main() {
    int N;
    N = read();
    for(int i = 1; i <= N; ++i) {
        l[i] = r[i - 1];
        scanf("%s", s + l[i]);
        r[i] = l[i] + strlen(s + l[i]);
        ac.insert(s + l[i], i);
    }
    ac.build();
    for(int i = 1; i <= N; ++i) id[i] = i;
    std::sort(id + 1, id + N + 1, cmp);
    int ans = 1;
    for(int i = 1; i <= N; ++i) {
        ans = max(ans, ac.query(s + l[id[i]], r[id[i]] - l[id[i]], id[i]));
        // printf("f[%d] = %d\n", id[i], f[id[i]]);
    }
    printf("%d\n", ans);
    return 0;
}
/*
7
metrostroitelei
metro
beschenko
stroi
metrostroitel
stroitel
metr
*/
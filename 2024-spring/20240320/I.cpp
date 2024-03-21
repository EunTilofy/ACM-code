#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")


#include<bits/stdc++.h>
using namespace std;

#define MN 4000005

class SA
{
    #define M(x) memset(x, 0, sizeof (x))
    private:
        int M = 27,p, q, sa[2][MN], rk[2][MN], num[MN];
    public:
        int height[MN],id[MN],pos[MN];;
        SA() {M(height); M(sa); M(rk); M(num);}
        inline void init() {M(height); M(sa); M(rk); M(num);}
        inline int get_sa(int x){
            return sa[p][x];
        }
        inline void build_sa(int *s, int n)
        {
            int i, j, k, mx;
            for(i = 1; i <= n; ++i) num[s[i]] ++;
            for(int i = 1; i <= M; ++i) num[i] += num[i - 1];
            for(i = 1; i <= n; ++i) sa[1][num[s[i]]--] = i;
            for(i = 1; i <= n; ++i) rk[1][sa[1][i]] = rk[1][sa[1][i-1]] + (s[sa[1][i-1]]!=s[sa[1][i]]);
            mx = rk[1][sa[1][n]];
            for(p=1,q=0,k=1;k<=n;k<<=1,p^=1,q^=1)
            {
                if(mx == n) break;
                for(i = 1; i <= n; ++i) num[rk[p][sa[p][i]]]=i;
                for(i=n;i;--i) if(sa[p][i]>k)
                    sa[q][num[rk[p][sa[p][i]-k]]--] = sa[p][i] - k;
                for(i = n-k+1; i <= n; ++i) sa[q][num[rk[p][i]]--] = i;
            // cerr << "!!!\n";
                for(i = 1; i <= n; ++i)
                {
                    rk[q][sa[q][i]] = rk[q][sa[q][i-1]]+
                                    (rk[p][sa[q][i]]!=rk[p][sa[q][i-1]]||
                                     rk[p][sa[q][i]+k]!=rk[p][sa[q][i-1]+k]);
                }
                mx = rk[q][sa[q][n]];
            }    
            for(i=k=1;i<=n;++i)
            {
                if(rk[p][i]==1) continue; if(k) k--;
                for(j = sa[p][rk[p][i]-1]; j+k<=n&&i+k<=n&&s[i+k]==s[j+k]; ++k);
                height[rk[p][i]] = k;
            }
            for(int i=1;i<=n;i++){
                height[i]=min(height[i],min(pos[sa[p][i]],pos[sa[p][i-1]]));
            }
        }
}sa;

string str[MN];
int s[MN],len,n;
int t[MN];
int fa[MN];
int find(int x){
    return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> str[i];
        fa[i]=i;
        if(i > 1) s[++len] = 27;
        for(int j = 0; j < str[i].size(); ++j) {
            s[++len] = str[i][j] - 'a' + 1;
            sa.id[len]=i;
            sa.pos[len]=str[i].size()-j;
        }
    }
    int ans=0;
    sa.build_sa(s, len);
    for(int i=1;i<=len;i++)t[i]=i;
    sort(t+1,t+1+len,[&](int a,int b){return sa.height[a]>sa.height[b];});
    for(int i=1;i<=len;i++){
        int x=sa.get_sa(t[i]),y=sa.get_sa(t[i]-1);
        if(sa.id[x]==sa.id[y])continue;
        else {
            int rx=sa.id[x],ry=sa.id[y];
            rx=find(rx),ry=find(ry);
            if(rx!=ry){
                fa[ry]=rx;
                ans+=sa.height[t[i]];
            }
        }
    }
    cout<<ans;
    
    

    return 0;
}

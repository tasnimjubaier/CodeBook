#include <bits/stdc++.h>
using namespace std;

#define pi acos(-1.0)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define pii pair<int, int>
#define pll pair<long long>
#define ff first
#define ss second
#define eps 1e-9
#define INF INT_MAX
#define ll long long
#define MX 100002
#define MOD 1000000007
#define cs(x) printf("Case %d: ", ++x)

vector<int> adj[MX];
int tim;
bool vis[MX];
int st[MX], nd[MX];

void dfs(int n)
{
    vis[n] = 1;
    int i, l = adj[n].size();
    st[n] = tim++;
    for(i = 0; i < l; i++)
    {
        if(!vis[adj[n][i]]) dfs(adj[n][i]);
    }
    nd[n] = tim++;
}

struct Tmp{
    int ti, no;
    Tmp() {}
    Tmp(int a, int b) : ti(a), no(b) {}
    bool operator<(const Tmp &TT) const
    {
        return ti > TT.ti;
    }
};
Tmp T[MX];

void top_sort(int n)
{
    int i,j;
    for(i = 1; i <= n; i++) T[i-1] = Tmp(nd[i], i);
    sort(T, T+n);
}

int main()
{
    int t, tc=0, i, j;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        for(i = 0; i < m; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a].pb(b);
        }
        int cnt = 0;
        for(i = 1; i <= n; i++)
        {
            if(!vis[i]) dfs(i);
        }
        top_sort(n);
        CLR(vis);
        for(i = 0; i < n; i++) if(!vis[T[i].no]) dfs(T[i].no), cnt++;

        printf("Case %d: %d\n", ++tc, cnt);
        for(i = 0; i <= n; i++) adj[i].clear();
        CLR(vis);
        CLR(st); CLR(nd); tim = 0;
    }
}

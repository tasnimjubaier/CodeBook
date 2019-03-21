#include <bits/stdc++.h>
using namespace std;

#define pi acos(-1.0)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define pii pair<int, int>
#define pll pair<long long, long long>
#define ff first
#define ss second
#define eps 1e-9
#define INF 1000000000
#define ll long long
#define MX 100002
#define MOD 1000000007


vector<int> adj[MX];
int dis[MX];
int nw[MX];
bool vis[MX];

int weit(int u, int v)
{
    return (nw[v] - nw[u])*(nw[v] - nw[u])*(nw[v] - nw[u]);
}

int main()
{
    int t, tc = 0, i, j;
    cin >> t;
    while(t--)
    {
        int n, m, q;
        cin >> n;
        for(i = 1; i <= n; i++) scanf("%d", &nw[i]);
        cin >> m;
        while(m--)
        {
            int a, b;
            cin >> a >> b;
            adj[a].pb(b);
        }
        cin >> q;
        printf("Case %d:\n", ++tc);
        for(i = 1; i <= n ; i++) dis[i] = INF;

        dis[1] = 0;
        for(i = 0; i < n-1; i++)
        {
            int u, v;
            queue<int> Q;
            Q.push(1);
            CLR(vis);
            while(!Q.empty())
            {
                u = Q.front(); Q.pop();
                vis[u] = 1;
                for(j = 0; j < adj[u].size(); j++)
                {
                    v = adj[u][j];
                    if(dis[v] > dis[u] + weit(u,v)) dis[v] = dis[u] + weit(u,v);
                    if(!vis[v]) Q.push(v);
                }
            }
        }

        while(q--)
        {
            int a;
            cin >> a;
            if(dis[a] < 3 || dis[a] > 100000000) cout << "?" << endl;
            else cout << dis[a] << endl;
        }

        for(i = 0; i <= n; i++) adj[i].clear();
        CLR(dis);
    }
}

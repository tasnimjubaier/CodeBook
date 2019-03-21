#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9
#define MX 30009
#define pii pair<int,int>


vector<int> adj[MX];
int n,m,s,d;
int dis1[MX],dis2[MX];
bool vis[MX];

void bfs1(int u)
{
    int i;
    vis[u] = 1;
    dis1[u] = 0;
    queue<int> Q;
    Q.push(u);
    while(!Q.empty())
    {
        int y = Q.front(); Q.pop();
        for(i=0;i<adj[y].size();i++)
        {
            if(vis[adj[y][i]]) continue;
            vis[adj[y][i]] = 1;
            dis1[adj[y][i]] = dis1[y] + 1;
            Q.push(adj[y][i]);
        }
    }
    return ;
}
void bfs2(int u)
{
    int i;
    vis[u] = 1;
    dis2[u] = 0;
    queue<int> Q;
    Q.push(u);
    while(!Q.empty())
    {
        int y = Q.front(); Q.pop();
        for(i=0;i<adj[y].size();i++)
        {
            if(vis[adj[y][i]]) continue;
            vis[adj[y][i]] = 1;
            dis2[adj[y][i]] = dis2[y] + 1;
            Q.push(adj[y][i]);
        }
    }
    return ;
}

int main()
{
    int t,tc=0,i,j;
    cin>>t;
    while(t--)
    {
        int u,v,w, maxx=0;
        cin>>n>>m;
        for(i=0;i<m;i++)
        {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cin>>s>>d;
        memset(dis1,0,sizeof(dis1));
        memset(vis,0,sizeof(vis));
        bfs1(s);
        memset(dis2,0,sizeof(dis2));
        memset(vis,0,sizeof(vis));
        bfs2(d);
        for(i=0;i<n;i++) maxx = max(maxx, dis1[i]+dis2[i]);
        printf("Case %d: %d\n",++tc,maxx);
        for(i=0;i<n;i++) adj[i].clear();
    }
}


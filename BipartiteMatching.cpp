#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define SET(a) memset(a, -1, sizeof(a))

vector<int> g[10005];
int match[10005], seen[10005];
int n, instance;

bool Match(int u)
{
	if(seen[u] == instance) return 0;
	seen[u] = instance;
    for(auto v : g[u]){
        if(match[v] == -1 || Match(match[v])){
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int i, m;
    cin >> n >> m;
    while(m--){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
	}
	SET(match);
	for(i = 0; i < n; i++){
		instance++;
		if(!Match(i)) break;
	}
	if(i == n) cout << "YES";
	else cout << "NO";
}


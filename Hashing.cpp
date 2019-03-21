#include <bits/stdc++.h>
using namespace std;

#define pi acos(-1.0)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define rep(i,n) for(i = 0; i < n; i++)
#define REP(i,n) for(i = 1; i <= n; i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define ff first
#define ss second
#define pii pair<int, int>
#define eps 1e-9
#define ll long long
#define MX 100003
#define MOD 1000000007
#define INF 1000000000
#define cs(t) printf("Case %d: ", t)

ll bm(ll n, ll p)
{
    if(p == 0) return 1;
    ll ans = bm(n, p/2);
    ans *= ans; ans %= MOD;
    if(p&1) ans *= n, ans %= MOD;
    return ans;
}
int INV(int n)
{
    return bm(n, MOD - 2);
}
char a[1000002], b[1000002];
ll chash[1000002];

ll bhash(int n)
{
    ll i, bb = 104729, hs = 0;
    for(i = 0; i < n; i++)
    {
        hs *= bb; hs %= MOD;
        hs += (b[i] - 'a'); hs %= MOD;
    }
    return hs;
}
void fhash(int n)
{
    ll i, b = 104729, hs = 0;
    for(i = 0; i < n; i++)
    {
        hs *= b; hs %= MOD;
        hs += (a[i] - 'a'); hs %= MOD;
        chash[i] = hs;
    }
}
int countMatch(ll hs, int n, int m)
{
    ll ret = 0, i, b = 104729;
    if(chash[m - 1] == hs)
        ret++;
    for(i = 1; i + m - 1 < n; i++)
    {
        ll now = chash[i + m - 1];
        now -= (chash[i - 1] * bm(b, m)) % MOD;
        now %= MOD;
        if(now < 0) now += MOD;
        if(now == hs) ret++;
    }
    return ret;
}

int main(){
    int t, i, j, tc = 0;
    cin >> t;
    while(t--)
    {
        scanf("%s %s", a, b);
        int n = strlen(a), m = strlen(b);
        fhash(n);
        int hs = bhash(m);
        cout << "Case " << ++tc << ": " << countMatch(hs, n, m) << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

typedef long long            ll;
typedef pair<ll, ll>         pl;
typedef pair<int, int>       pi;

#define ff          first
#define ss          second
#define pb          push_back
#define all(a)      a.begin(), a.end()
#define CLR(a)      memset((a), 0, sizeof(a))

/// BIT -- Peter M. Fenwick
const int MX = 100000 + 5;
const ll MOD = 1000000007;

vector<pl> p;

ll a[MX], fenwick[MX];
//ll csum[MX];
int n;

// void build()
// {
//     int i;
//     for(i = 0; i < n; i++)
//         csum[i] = (i == 0 ? 0 : csum[i-1]) + a[i];
//     for(i = 1; i <= n; i++)
//         fenwick[i] = csum[i-1] - csum[i - (i&-i) - 1];
// }
ll query(int pos)
{
    ll sum = 0;
    for(int i = pos; i > 0; i -= i & -i)
        sum += fenwick[i] % MOD, sum %= MOD;
    return sum % MOD;
}
void update(int pos, ll x)
{
    for(int i = pos; i <= n; i += i & -i)
        fenwick[i] += x % MOD;
}

bool cmp(pl a, pl b)
{
    if(a.ff == b.ff) return a.ss > b.ss;
    return a.ff < b.ff;
}

int main()
{
    int t, i, j, tc = 0;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
        {
            ll v;
            cin >> v;
            p.pb(pi(v, i+1));
        }
        sort(all(p), cmp);
        ll res = 0;
        for(i = 0; i < n; i++)
        {
            ll ans = query(p[i].ss-1) + 1;
            a[p[i].ss] = ans;
            update(p[i].ss, ans);
            res += ans % MOD; res %= MOD;
        }
        cout << "Case " << ++tc << ": " << res << endl;
        CLR(a); CLR(fenwick);
        p.clear();
    }
}

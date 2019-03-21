#include <bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef vector<int>       vi;
typedef vector<ll>        vl;
typedef pair<int, int>    pii;
#define ill __int128
typedef pair<ill, ill>	  pll;
typedef long double		  ld;


#define read        freopen("in.txt", "r", stdin)
#define write       freopen("out.txt", "w", stdout)
#define all(a)      a.begin(), a.end()
#define mp          make_pair
#define ff          first
#define ss          second
#define pb          push_back
#define eps         1e-9
#define inf         (1000000000)
#define infl        (1000000000000000000LL)
#define cs(p)       printf("Case %d:", (p)++)
#define SET(a)      memset((a), -1, sizeof(a))
#define CLR(a)      memset((a), 0, sizeof(a))
#define dbg(x)      cout << #x << " = " << x << endl
#define ill			__int128


void Print(ill x)
{
	string s = "";
	while(x > 0) s += (char)(x % 10 + '0'), x /= 10;
	reverse(all(s));
	cout << s << endl;
}

struct Matrix{
	vector< vector <pll> > v;
	int m;
	Matrix() {}
	Matrix(int mm){
		m = mm;
		v.resize(m);
		for(int i = 0; i < m; i++) v[i].resize(m);
	}
	Matrix reduce()
	{
		Matrix ret(m - 1);
		for(int i = 1; i < m; i++)
			for(int j = 1; j < m; j++)
				ret.v[i - 1][j - 1] = v[i][j];
		return ret;
	}
}M;
int n, m;

void makeMat(){
	int i, j;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < m; j++){
			int x = min(i, j), y = max(i, j);
			if(i == j){
				if(i == 0 || i == n - 1 || i == m - n || i == m - 1) M.v[i][j].ff = 3;
				else if(i % n == 0 || i % n == n - 1 || i < n - 1 || i > m - n) M.v[i][j].ff = 5;
				else M.v[i][j].ff = 8;
			}
			else if(abs(i - j) == n || (i == j + 1 && i % n != 0) || (j == i + 1 && j % n != 0)) M.v[i][j].ff = -1;
			else if((x < m-n && x % n != n-1 && y == x + n + 1) || (x < m-n && x % n != 0 && y == x + n - 1))
				M.v[i][j].ff = -1;
			else M.v[i][j].ff = 0;
			M.v[i][j].ss = 1;
		}
	}
}

ill gcd(ill a, ill b)
{
	if(a == 0) return b;
	return gcd(b%a, a);
}

pll relax(pll a)
{
	ill g = gcd(a.ff, a.ss);
	a.ff /= g, a.ss /= g;
	return a;
}

pll subt(pll a, pll b){
	pll ret;
	ret.ss = a.ss * (b.ss / gcd(a.ss, b.ss));
	ret.ff = a.ff * (ret.ss / a.ss) - b.ff * (ret.ss / b.ss);
	ill g = gcd(ret.ff, ret.ss);
	ret.ff /= g, ret.ss /= g;
	return ret;
}

pll mult(pll a, pll b)
{
	pll ret(1, 1);
	ill g = gcd(a.ff, b.ss);
	a.ff /= g, b.ss /= g;
	g = gcd(a.ss, b.ff);
	a.ss /= g, b.ff /= g;
	ret.ff = a.ff * b.ff, ret.ss = a.ss * b.ss;
	return ret;
}

pll divide(pll a, pll b)
{
	pll ret(1, 1);
	ill g = gcd(a.ff, b.ff);
	a.ff /= g, b.ff /= g;
	g = gcd(a.ss, b.ss);
	a.ss /= g, b.ss /= g;
	ret.ff = a.ff * b.ss, ret.ss = a.ss * b.ff;
	return ret;
}

ill gaussianEllimination()
{
	int i, j, k;
	pll ret(1, 1), x;
	for(i = 0; i < m; i++){
		ret = mult(ret, M.v[i][i]);
		for(j = i + 1; j < m; j++) {
			x = divide(M.v[j][i], M.v[i][i]);
			for(k = i; k < m; k++)
				M.v[j][k] = subt(M.v[j][k], mult(M.v[i][k], x));
		}
	}
	return ret.ff;
}

int main()
{
	int t, i, j;
	cin >> t;
	while(t--)
	{
		cin >> n;
		m = n * n;
		M = Matrix(m);
		makeMat();
		M = M.reduce();
		m--;
		ill xD = gaussianEllimination();
		ill ans = (ill)(xD);
		Print(ans);
	}
}


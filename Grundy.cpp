#include <bits/stdc++.h>
using namespace std;


#define pi acos(-1.0)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define eps 1e-9
#define INF (1<<20)
#define ll long long
#define MX 10002
#define MOD 1000000007


void print(set<int> S){
    set<int> :: iterator I;
    for(I = S.begin(); I != S.end(); I++)
        printf("%d ", *I);
    cout << endl;
}

int mex(set<int> S)
{
    if(S.empty()) return 0;
    int i = 0;
    set<int> :: iterator I = S.begin();

    for(i = 0; ; i++){
        if(I == S.end()) { I--; return *(I) + 1; }

        if(*I == i)
            I++;
        else return i;
    }
}

int gnd[MX];

void make()
{
    int i,j;

    for(i = 2; i < MX; i++){
        set<int> S;

        for(j = 1; j < i/2; j++) S.insert(gnd[j] ^ gnd[i-j]);
        if(i&1) S.insert(gnd[j] ^ gnd[i-j]);
        gnd[i] = mex(S);
    }
}


int main()
{
    int t, tc = 0,i,j;
    set<int> S;
    make();

    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        for(i = 0; i < n; i++){
            cin >> j;
            ans ^= gnd[j];
        }
        printf("Case %d: %s\n", ++tc, ans != 0 ? "Alice" : "Bob");
    }
}


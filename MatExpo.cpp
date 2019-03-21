#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

struct mat{
    ll a[4];
    mat() { a[3]=0, a[0]=1, a[1]=1, a[2]=1; }
};

mat mul(mat A,mat B)
{
    mat C;
    C.a[0]=(A.a[0]*B.a[0]+A.a[1]*B.a[2])%mod;
    C.a[1]=(A.a[0]*B.a[1]+A.a[1]*B.a[3])%mod;
    C.a[2]=(A.a[2]*B.a[0]+A.a[3]*B.a[2])%mod;
    C.a[3]=(A.a[2]*B.a[1]+A.a[3]*B.a[3])%mod;
    return C;
}
mat mat_exp(mat Ar,ll n)
{
    if(n==0) { mat m; m.a[1]=m.a[2]=m.a[3]=0; return m; }
    if(n==1) return Ar;
    mat p=mat_exp(Ar,n/2);
    p=mul(p,p);
    if(n&1) return mul(p,Ar);
    return p;
}
int main()
{
    int t,q=0;
    cin>>t;
    while(t--)
    {
        ll N,X,M,Y,K;
        cin>>N>>X>>M>>Y>>K;
        mat A,B,C;
        B=mat_exp(A,N); C=mat_exp(A,M);
        if(((B.a[0]*C.a[1]!=C.a[0]*B.a[1]))&&((X*C.a[1]-Y*B.a[1])%(B.a[0]*C.a[1]-C.a[0]*B.a[1])==0)&&((X*C.a[0]-Y*B.a[0])%(C.a[0]*B.a[1]-B.a[0]*C.a[1])==0)&&((X*C.a[1]-Y*B.a[1])/(B.a[0]*C.a[1]-C.a[0]*B.a[1])>=0)&&((X*C.a[0]-Y*B.a[0])/(C.a[0]*B.a[1]-B.a[0]*C.a[1])>=0))
        {
            ll b=(X*C.a[1]-Y*B.a[1])/(B.a[0]*C.a[1]-C.a[0]*B.a[1]), a=(X*C.a[0]-Y*B.a[0])/(C.a[0]*B.a[1]-B.a[0]*C.a[1]);
            mat D=mat_exp(A,K);
            printf("Case %d: %lld\n",++q,(D.a[0]*b+D.a[1]*a)%mod);
        }
        else
        {
            printf("Case %d: Impossible\n",++q);
        }
    }
}

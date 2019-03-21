#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD = 1000000007;

ll mul[400003], add[400002], a[100003], tree[400003];

void relax(int l, int r, int pos){
    tree[pos] *= mul[pos]; tree[pos] %= MOD;
    tree[pos] += ((r - l + 1) * add[pos]) % MOD; tree[pos] %= MOD;
    if(l != r){
		mul[2 * pos] *= mul[pos]; mul[2 * pos] %= MOD;
		add[2 * pos] *= mul[pos]; add[2 * pos] %= MOD;
		add[2 * pos] += add[pos]; add[2 * pos] %= MOD;
		mul[2 * pos + 1] *= mul[pos]; mul[2 * pos + 1] %= MOD;
		add[2 * pos + 1] *= mul[pos]; add[2 * pos + 1] %= MOD;
		add[2 * pos + 1] += add[pos]; add[2 * pos + 1] %= MOD;
    }
	mul[pos] = 1;
	add[pos] = 0;
}

void build(int l, int r, int pos){
	if(l > r) return ;
	mul[pos] = 1;
	if(l == r) {
		tree[pos] = a[l];
		return ;
	}
	int mid = (l + r) / 2;
	build(l, mid, 2 * pos);
	build(mid + 1, r, 2 * pos + 1);

	tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
	tree[pos] %= MOD;
}


void update(int l, int r, int pos, int x, int y, int v, int ty)
{
    relax(l, r, pos);
    if(y < l || x > r) return ;
    if(x <= l && r <= y){
        if(ty == 1){
            add[pos] += v; add[pos] %= MOD;
        }
        else if(ty == 2){
            add[pos] *= v; add[pos] %= MOD;
            mul[pos] *= v, mul[pos] %= MOD;
        }
        else if(ty == 3){
            mul[pos] = 0, add[pos] = v;
        }
        relax(l, r, pos);
        return ;
    }
    int mid = (l + r) / 2;
    update(l, mid, 2 * pos, x, y, v, ty);
    update(mid + 1, r, 2 * pos + 1, x, y, v, ty);
    tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
    tree[pos] %= MOD;
    return ;
}

ll query(int l, int r, int pos, int x, int y){

    relax(l, r, pos);
    if(y < l || x > r) return 0;

    if(x <= l and r <= y){
        return tree[pos];
    }
    int mid = (l + r) / 2;
    return (query(l, mid, 2 * pos, x, y) + query(mid + 1, r, 2 * pos + 1, x, y)) % MOD;
}


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, q, i, j;
    cin >> n >> q;
    for(i = 0; i < n; i++){
        cin >> a[i];
    }
    build(0, n-1, 1);

    while(q--){
        int ty, x, y, v;
        cin >> ty >> x >> y;
        if(ty == 4){
            cout << query(0, n-1, 1, x-1, y-1) << endl;
        }
        else{
            cin >> v;
            update(0, n-1, 1, x - 1, y - 1, v, ty);
        }
    }
    return 0;
}

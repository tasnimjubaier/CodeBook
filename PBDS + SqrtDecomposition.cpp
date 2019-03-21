

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define pii pair<int, int>
#define inf 1000000000
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ordered_set S;
///wanna do something better?
/*

#include<ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

ordered_map<int, int> my_map;
*/
/// trie ...
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef trie<
string,
null_type,
trie_string_access_traits<>,
pat_trie_tag,
trie_prefix_search_node_update>
pref_trie;
*/

int n, a[20003], bs, ans[20002];
map<int, int> M, D;

struct Qry{
	int l, r, ind, ans;
	Qry() {}
	Qry(int ll, int rr, int i){
		l = ll; r = rr; ind = i;
	}
	bool operator<(const Qry &q) const{
		if(l / bs == q.l / bs) return r < q.r;
		return l / bs < q.l / bs;
	}
}Q[20003];

int main()
{
	int i, j;
	cin >> n;
	for(i = 0; i < n; i++) cin >> a[i];

	int qr;
	cin >> qr;
	for(i = 0; i < qr; i++){
		int l, r;
		cin >> l >> r;
		Q[i] = Qry(l - 1, r - 1, i+1);
	}
	bs = sqrt(n);
	sort(Q, Q + qr);
	int l = 0, r = -1, ansNow = 0, siz = 0;

	for(i = 0; i < qr; i++){
		while(r < Q[i].r){
			r++;
			ansNow += (siz - S.order_of_key({a[r], inf}));
			S.insert({a[r], M[a[r]]++});
			siz++;
		}
		while(l > Q[i].l){
			l--;
			ansNow += S.order_of_key({a[l] - 1, inf});
			S.insert({a[l], M[a[l]]++});
			siz++;
		}
		while(r > Q[i].r){
			S.erase({a[r], D[a[r]]++});
			siz--;
			ansNow -= (siz - S.order_of_key({a[r], inf}));
			r--;
		}
		while(l < Q[i].l){
			S.erase({a[l], D[a[l]]++});
			siz--;
			ansNow -= S.order_of_key({a[l] - 1, inf});
			l++;
		}
		ans[Q[i].ind - 1] = ansNow;
		Q[i].ans = ansNow;
	}
	for(i = 0; i < qr; i++)
		cout << ans[i] << endl;
}


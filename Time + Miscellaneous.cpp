#include <bits/stdc++.h>
using namespace std;

#define ill __int128
#define ll long long

void iprint(ill x){
	string s = "";
	int i;
	while(x) s += (char) (x % 10 + '0'), x /= 10;
	reverse(s.begin(), s.end());
	cout << s << endl;
}

int main()
{
	ill x = (ill)(1000000000000000ll) * (1000000000000000ll);
	iprint(x);
	auto start = chrono::steady_clock::now();

	auto End = chrono::steady_clock::now();
	auto diff = End - start;
	auto diffs = chrono::duration_cast<chrono::milliseconds>(diff);
	assert(diffs.count() < 1000);
}

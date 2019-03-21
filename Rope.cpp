#include <iostream>
#include <cstdio>
#include <ext/rope> //заголовочный файл с rope
using namespace std;
using namespace __gnu_cxx; //пространство имен, в котором находится класс rope и все, что с ним связано
int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    rope <int> v(n, 0); //rope <int> v(n) просто построит rope из одного элемента n!!
    for(int i = 0; i < n; ++i)
        v.mutable_reference_at(i) = i + 1;
    int l, r;
    for(int i = 0; i < m; ++i)
    {
        cin >> l >> r;
        --l, --r;
        rope <int> cur = v.substr(l, r - l + 1);
        v.erase(l, r - l + 1);
        v.insert(v.mutable_begin(), cur);
    }
    for(int i = 0; i < n; ++i)
        cout << v[i] << " ";
    return 0;
}

#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std; using ll = long long; using ld = long double;
#define nl "\n"

template <typename A, typename B>ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ' ' << p.second << ')'; }
template <typename X, typename T = typename enable_if<!is_same<X, string>::value, typename X::value_type>::type>  ostream& operator<<(ostream& o, const X& v) { string s;  for (const T& x : v) o << s << x, s = " ";  return o; }
void deb() { cout << "\n"; }
template <typename Head, typename... Tail>void deb(Head H, Tail... T){cout << H << ' ', deb(T...);}
#ifdef LOCAL
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", deb(__VA_ARGS__)
#else
#define dbg(...)
#endif


const int N = 2e6 + 10;
void solve() {
    int n;
    cin >> n;
    vector<int> ia(n),ib(n);
    for(int i = 0;i < n;i++) cin >> ia[i];
    for(int i = 0;i < n;i++) cin >> ib[i];
    sort(ia.begin(),ia.end());
    sort(ib.begin(),ib.end());
    vector<int> a,b;
    int suma = 0,sumb = 0;
    for(int i = n/4;i < n;i++) suma += ia[i],sumb += ib[i],a.push_back(ia[i]),b.push_back(ib[i]);
    int k = n;
    int bp = n/4-1;
    int res = 0;
    while(suma < sumb){
        res++;
        if(bp >= 0) sumb += ib[bp];
        bp--;
        k++;
        if(k % 4 == 0){
            bp++;
            if(bp >= 0) sumb -= ib[bp];
        }
        suma += 100;       
    }
    deb(res);
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
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
#define int ll

const int N = 2e6 + 10;
void solve() {
    int n, suma = 0, sumb = 0;
    cin >> n;
    vector<int> ia(n),ib(n);
    for(int i = 0;i < n;i++) cin >> ia[i], suma += ia[i];
    for(int i = 0;i < n;i++) cin >> ib[i], sumb += ib[i];
    sort(ia.begin(),ia.end());
    sort(ib.begin(),ib.end());
    vector<int> prefa, prefb;
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += ia[i];
        prefa.push_back(s);
    }
    s = 0;
    for (int i = 0; i < n; i++) {
        s += ib[i];
        prefb.push_back(s);
    }
    int round = 0;
        while (true) {
            int tempa = suma, tempb = sumb;
            int required_mins = (n+round)/4;
            if (required_mins > 0)
                tempa -= prefa[required_mins-1];
            
            if (required_mins - round > 0) {
                tempb -= prefb[required_mins - round - 1];
            }
            if (tempa >= tempb) break;
            round++;
            prefa.push_back(prefa.back()+100);
            prefb.push_back(prefb.back());
            suma += 100;
        }
    deb(round);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
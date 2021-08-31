#include <bits/stdc++.h>
using namespace std; using ll = long long;
#define nl "\n"

template <typename A, typename B>ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ' ' << p.second << ')'; }
template <typename X, typename T = typename enable_if<!is_same<X, string>::value, typename X::value_type>::type>  ostream& operator<<(ostream& o, const X& v) { string s;  for (const T& x : v) o << s << x, s = " ";  return o; }
void deb() { cout << "\n"; }
template <typename Head, typename... Tail>void deb(Head H, Tail... T){cout << H; if (sizeof...(T) > 0) cout << ' '; deb(T...);}
#ifdef LOCAL
#define dbg(...) cout << "[" << #_VA_ARGS_ << "]:", deb(_VA_ARGS_)
#else
#define dbg(...)
#endif

const int N = 2e6 + 10;
void solve() {
    int n, k;
    cin >> n >> k;
    int AandB,AorB,BandC,BorC,AandC,AorC;
    cout << "and 1 2" << endl;
    cin >> AandB;
    cout << "or 1 2" << endl;
    cin >> AorB;
    cout << "and 2 3" << endl;
    cin >> BandC;
    cout << "or 2 3" << endl;
    cin >> BorC;
    cout << "and 1 3" << endl;
    cin >> AandC;
    cout << "or 1 3" << endl;
    cin >> AorC;

    int ab = AandB + AorB, bc = BandC + BorC, ac = AandC + AorC;
    int a = (ab + ac - bc) / 2, b = ab - a, c = ac - a;
    vector<int> res;
    res.push_back(a);
    res.push_back(b);
    res.push_back(c);
    for (int i = 4; i <= n;i++){
        int andi, ori, sumi;
        cout << "and 1 " << i << endl;
        cin >> andi;
        cout << "or 1 " << i << endl;
        cin >> ori;
        sumi = andi + ori;
        res.push_back(sumi - a);
    }
    sort(res.begin(), res.end());
    cout << "finish " << res[k-1] << endl;
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
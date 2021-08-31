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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    vector<int> count(2);
    for (auto& x : a)
        count[x % 2]++;
    if(n%2 == 0){
        if(count[0] != count[1])
            return deb(-1);
        int ind1 = 0,ind2 = 1;
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n;i++){
            if(a[i]%2)
                c1 += abs(i - ind1), c2 += abs(i - ind2), ind1+=2, ind2+=2;
        }
        return deb(min(c1, c2));
    }
    int ind = 0;
    if(abs(count[0] - count[1]) > 1)
        return deb(-1);
    if(count[0] > count[1])
        ind = 1;
    int c = 0;
    for (int i = 0; i < n;i++){
        if(a[i] % 2)
            c += abs(i - ind),ind += 2;
    }
    deb(c);
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
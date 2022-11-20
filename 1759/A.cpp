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
    string s;
    cin >> s;
    for(int i = 0;i < s.length()-1;i++)
        if((s[i] != 'Y' and s[i] != 'e' and s[i] != 's') or (s[i] == 'Y' and s[i+1] != 'e') or (s[i] == 'e' and s[i+1] != 's') or (s[i] == 's' and s[i+1] != 'Y')) return deb("NO");
    if(s.back() != 'Y' and s.back() != 'e' and s.back() != 's') return deb("NO");
    deb("YES");
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
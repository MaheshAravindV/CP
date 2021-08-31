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
    int a, b;
    cin >> a >> b;
    if(a == b){
        cout << 0 << endl;
        return;
    }
    bitset<64> p(a), q(b);
    string ab, bb;
    int flag = 0;
    if(a == 0)
        flag = 1,ab = "1";
    else
        ab = p.to_string().substr(p.to_string().find('1'));
    bb = q.to_string().substr(q.to_string().find('1'));
    int index = 0;
    for (; index < ab.length();index++){
        if(ab[index] != bb[index])
            break;
    }
    int cost = (index != ab.length());
    if(cost)
        index++;
    cost += flag;
    for (int i = index; i < ab.length();i++){
        cost++;
        if(ab[i] == '1')
            cost++;
    }
    for (int i = index; i < bb.length();i++){
        cost++;
        if(bb[i] == '1')
            cost++;
    }
    cout << cost << endl;
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
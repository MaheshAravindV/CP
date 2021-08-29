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
    int k;
    cin >> k;
    string inp;
    cin >> inp;
    for (int i = 0; i < k;i++){
        if(inp[i] == '1' || inp[i] == '4' || inp[i] == '6' || inp[i] == '8' || inp[i] == '9'){
            deb(1);
            return deb(inp[i]);
        }
    }
    for (int i = 1; i < k;i++){
        if(inp[i] == '2' || inp[i] == '5'){
            deb(2);
            cout << inp[i - 1] << inp[i] << endl;
            return;
        }
    }
    int seen2 = 0, seen3 = 0, seen5 = 0, seen7 = 0;
    for (int i = 0; i < k;i++){
        if(seen2 && inp[i] == '7'){
            deb(2);
            return deb("27");
        }
        if(seen5 && inp[i] == '7'){
            deb(2);
            return deb("57");
        }
        if(seen3 && inp[i] == '3'){
            deb(2);
            return deb("33");
        }
        if(seen7 && inp[i] == '7'){
            deb(2);
            return deb("77");
        }
        if(inp[i] == '2') seen2 = 1;
        if(inp[i] == '3') seen3 = 1;
        if(inp[i] == '5') seen5 = 1;
        if(inp[i] == '7') seen7 = 1;
    }
    deb(2);
    cout << inp[0] << "7\n";
}

int main() {
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
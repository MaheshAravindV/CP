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

int diff(string s1,string s2){
    int count = 0;
    for(int i = 0;i < s1.size();i++) if(s1[i] != s2[i]) count++;
    return count;
}

const int N = 2e6 + 10;
void solve() {
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    for(auto &_ : a) cin >> _;
    string s1 = "",s2 = "";
    for(int i = 0;i < n;i++){
        for(int j = i+1;j < n;j++){
            if(diff(a[i],a[j]) > 2) return deb(-1);
            if(diff(a[i],a[j]) == 2){
                s1 = a[i];
                s2 = a[j];
                break;
            }
        }
    }
    if(s1.size() == 0) return deb(a[0]);
    vector<int> ind;
    for(int i = 0;i < m;i++) if(s1[i] != s2[i]) ind.push_back(i);

    string x = s1;
    x[ind[1]] = s2[ind[1]];
    bool sol = true;
    for(int i = 0;i < n and sol;i++) if(diff(a[i],x) > 1) sol = false;

    if(sol) return deb(x);

    x = s1;
    x[ind[0]] = s2[ind[0]];
    sol = true;
    for(int i = 0;i < n and sol;i++) if(diff(a[i],x) > 1) sol = false;

    if(sol) return deb(x);

    return deb(-1);
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
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

string s;
void solve() {
    cin >> s;
    int n = (int)s.length();
    string removal_order = "";
    for (int i = n - 1; i >= 0; i--) {
        if (removal_order.find(s[i]) == string::npos)
            removal_order += s[i];
    }
    reverse(removal_order.begin(), removal_order.end());
    int m = (int)removal_order.length();
    vector<int> cost(26);
    map<char, int> f;
    for (char c : s) {
        f[c]++;
    }
    for (int i = 0; i < m; i++) {
        cost[removal_order[i]-'a'] = f[removal_order[i]] / (i + 1);
    }
    int stop = -1;
    for (int i = 0; i < n; i++)
    {
        cost[s[i] - 'a']--;
        if (cost[s[i] - 'a'] < 0) {
            cost[s[i]-'a']++;
            stop = i;
            break;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (cost[i] > 0 or cost[i] < 0)
            return deb(-1);
    }
    string taken = s.substr(0, stop), r = s;
    for (int i = 0; i < m; i++) {
        if (s.find(taken) != 0) {
            return deb(-1);
        }
        s = s.substr(taken.length());
        taken.erase(std::remove(taken.begin(), taken.end(), removal_order[i]), taken.end());
    }
    if (s.length() > 0) return deb(-1);
    deb(r.substr(0, stop), removal_order);
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

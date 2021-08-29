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
    string inp;
    cin >> inp;
    vector<int> a(n);
    for (int i = 0; i < n;i++)
        a[i] = inp[i] - '0';
    stack<int> need0, need1;
    int size = 1;
    vector<int> ans;
    for (auto& x : a) {
        if(x == 0){
            if(need0.size() == 0){
                ans.push_back(size);
                need1.push(size++);
            }
            else{
                int x = need0.top();
                ans.push_back(x);
                need0.pop();
                need1.push(x);
            }
        }
        else{
            if(need1.size() == 0){
                ans.push_back(size);
                need0.push(size++);
            }                
            else{
                int x = need1.top();
                ans.push_back(x);
                need1.pop();
                need0.push(x);
            }
        }
    }
    deb(size-1);
    for (auto& x : ans)
        cout << x << ' ';
    deb();
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
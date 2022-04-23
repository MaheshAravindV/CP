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
    int n,d;
    cin >> n >> d;
    vector<int> days(n);
    for(auto &_ : days) cin >> _;
    vector<int> distances = {days[0]-1};
    for(int i = 1;i < n;i++){
        distances.push_back(days[i] - days[i-1]-1);
    }
    distances.push_back(d-days[n-1]);
    int mind = INT_MAX,count = 0;
    vector<int> indices;
    for(int i = 0;i < n;i++){
        if(distances[i] == mind) count++,indices.push_back(i);
        else if(distances[i] < mind) mind = distances[i],count = 1,indices = {i};
    }
    // deb();
    // deb(mind,count);
    // deb(indices);
    if(count > 2 or (count == 2 and indices[1]-indices[0] != 1))
        return deb(mind);
    if(count == 1){
        // deb(days);
        int index = indices[0];
        deb(distances);
        distances[index] = distances[index] + distances[index + 1] + 1;
        distances.erase(distances.begin()+index+1);
        int maxd = 0;
        for(int i = 0;i < n-1;i++)
            maxd = max(maxd,(distances[i]-1)/2);
        maxd = max(maxd,distances[n-1]-1);
        deb(distances);
        deb(maxd);
    }
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
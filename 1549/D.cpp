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

#define int long long

template <typename T>
struct SegTree {
    int size, n, ie;
    vector<T> tree;
    T(*combine) (T x, T y);
    /**
     * n -> size of the input array
     * it -> identity element/value when query invalid such that combine fn works
     *			along with it (example: 0 for sum/xor/gcd, +inf for min, -inf for max)
     * */
    SegTree(int nn, int _ie, T(*_combine)(T x, T y)) {
        this->combine = _combine;
        this->ie = _ie;
        // it = ei;
        size = 1;
        while (size < nn) size *= 2;
        this->n = size;
        size *= 2;
        this->size = size;
        this->tree = vector<T>(size);
    }

    void init(vector<T> v) {
        for (int i = 0; i < (int)v.size(); i++)
            tree[i + n] = v[i];
    }

    void build() {
        for (int i = n - 1; i > 0; i--)
            tree[i] = combine(tree[2 * i], tree[2 * i + 1]);
    }

    void update(int i, T v) {
        i += n;
        tree[i] = v;
        while (i) {
            i /= 2;
            tree[i] = combine(tree[2 * i], tree[2 * i + 1]);
        }
    }

    T _query(int l, int r, int x, int lx, int rx) {
        if (r < lx or l > rx) return ie;
        if (l <= lx and r >= rx) return tree[x];

        int mx = lx + (rx - lx) / 2;
        return combine(_query(l, r, 2 * x, lx, mx), _query(l, r, 2 * x + 1, mx + 1, rx));
    }

    T query(int l, int r) {
        assert(l <= r);
        return _query(l, r, 1, 0, n - 1);
    }
};

int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

const int N = 2e6 + 10;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    vector<int> differences(n - 1);
    for (int i = 0; i < n-1;i++)
        differences[i] = abs(a[i + 1] - a[i]);
    SegTree<int> str(n - 1, 0,gcd);
    str.init(differences);
    str.build();
    int l = 0, r = 0,maxlen = 0;
    while(r < n-1){
        while(r < n-1 && str.query(l,r) > 1){
            r++;
        }
        maxlen = max(r - l, maxlen);
        l++;
        while(r < n-1 && l <= r && str.query(l,r) == 1)
            l++;
        if(l > r)
            r = l;
    }
    maxlen = max(r - l, maxlen);
    deb(maxlen+1);
}

int32_t main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
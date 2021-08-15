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
#define int ll

const int m = 1e9 + 7;

 // To compute x^y under modulo m
int power(int x, int y, int m)
{
    if (y == 0)
        return 1;
    int p = power(x, y / 2, m) % m;
    p = (p * p) % m;
 
    return (y % 2 == 0) ? p : (x * p) % m;
}
 
// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
// Function to find modular inverse of a under modulo m
// Assumption: m is prime
int inverse(int a, int m)
{
    int g = gcd(a, m);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // If a and m are relatively prime, then modulo
        // inverse is a^(m-2) mode m
        return power(a, m - 2, m);
    }
}
 


const int MAXN = 2e5 + 1;
int factorial[MAXN + 10];

long long binomial_coefficient(int n, int k) {
    return factorial[n] * inverse(factorial[k] * factorial[n - k],m) % m;
}
const int md = 1e9 + 7;
long long binpow(long long a, long long b, long long md) {
    a %= md;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % md;
        a = a * a % md;
        b >>= 1;
    }
    return res;
}
void solve() {
    int n, k;
    cin >> n >> k;
    // if(k == 0)
    //     return deb(1);

    int combsum = 1;
    for (int i = 0; i < n; i+=2) {
        combsum += binomial_coefficient(n, i);
        combsum %= md;
    }
    int ans = 0;
    for (int i = 0; i < k;i++){
        ans += (combsum * binpow(2, n * i, md) % md) % md;
    }
    deb(ans%md);
}

int32_t main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
    int T = 1;
    cin >> T;
    factorial[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        factorial[i] = factorial[i - 1] * i % m;
    }

    while (T--) solve();
    return 0;
}
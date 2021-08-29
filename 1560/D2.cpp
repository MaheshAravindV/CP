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

vector<string> powers = {"1","2","4","8","16","32","64","128","256","512","1024","2048","4096","8192","16384","32768","65536","131072","262144","524288","1048576","2097152","4194304","8388608","16777216","33554432","67108864","134217728","268435456","536870912","1073741824","2147483648","4294967296","8589934592","17179869184","34359738368","68719476736","137438953472","274877906944","549755813888","1099511627776","2199023255552","4398046511104","8796093022208","17592186044416","35184372088832","70368744177664","140737488355328","281474976710656","562949953421312","1125899906842624","2251799813685248","4503599627370496","9007199254740992","18014398509481984","36028797018963968","72057594037927936","144115188075855872","288230376151711744","576460752303423488","1152921504606846976","2305843009213693952","4611686018427387904","9223372036854775808","18446744073709551616","36893488147419103232","73786976294838206464","147573952589676412928","295147905179352825856","590295810358705651712","1180591620717411303424","2361183241434822606848","4722366482869645213696","9444732965739290427392","18889465931478580854784","37778931862957161709568","75557863725914323419136","151115727451828646838272","302231454903657293676544","604462909807314587353088","1208925819614629174706176","2417851639229258349412352","4835703278458516698824704","9671406556917033397649408","19342813113834066795298816","38685626227668133590597632","77371252455336267181195264","154742504910672534362390528","309485009821345068724781056","618970019642690137449562112","1237940039285380274899124224","2475880078570760549798248448","4951760157141521099596496896","9903520314283042199192993792","19807040628566084398385987584","39614081257132168796771975168","79228162514264337593543950336","158456325028528675187087900672","316912650057057350374175801344","633825300114114700748351602688"};
// vector<string> powers = {"65536"};
const int N = 2e6 + 10;
void solve() {
    string n;
    cin >> n;
    int mincost = 10000;
    for (auto& x : powers) {
        int np = 0,cost = 0,matches = 0;
        for (int i = 0; i < x.length();i++){
            while(np < n.length() && n[np] != x[i])
                np++,cost++;
            if(np < n.length() && n[np] == x[i])
                matches++,np++;
        }
        // deb(cost, np, matches);
        cost += (n.length() - np) + (x.length() - matches);
        mincost = min(mincost, cost);
    }
    deb(mincost);
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
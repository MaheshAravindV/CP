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
vector<bool> eq;
vector<unsigned int> cnt;
ll sz;
vector<bool> tree;

bool isEq(int i1,int i2){
    if(i1 >= sz/2 and i2 >= sz/2) return tree[i1] == tree[i2];
    if(i1 >= sz/4 and i2 >= sz/4){
        if(tree[i1] == tree[i2]){
            int llc = i1*2+1,lrc = i1*2+2;
            int rlc = i2*2+1,rrc = i2*2+2;
            return (tree[llc] == tree[rlc] and tree[lrc] == tree[rrc]) or (tree[llc] == tree[rrc] and tree[lrc] == tree[rlc]);
        }
        return false;
    }
    if(i1 >= sz/8 and i2 >= sz/8){
        if(tree[i1] == tree[i2]){
            int llc = i1*2+1,lrc = i1*2+2;
            int rlc = i2*2+1,rrc = i2*2+2;
            return (isEq(llc,rlc) and isEq(lrc,rrc)) or (isEq(llc,rrc) and isEq(lrc,rlc));
        }
        return false;
    }
    int i = i1,j = i2;
    if(i > j) swap(i,j);
    if(eq[i * (sz/8) - (i - 1) * i / 2 + j - i]) return true;
    if(tree[i1] == tree[i2]){
        int llc = i1*2+1,lrc = i1*2+2;
        int rlc = i2*2+1,rrc = i2*2+2;
        eq[i * (sz/8) - (i - 1) * i / 2 + j - i] = (isEq(llc,rlc) and isEq(lrc,rrc)) or (isEq(llc,rrc) and isEq(lrc,rlc));
        return eq[i * (sz/8) - (i - 1) * i / 2 + j - i];
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    sz = pow(2,n)-1;
    tree = vector<bool>(sz,false);
    int s2 = sz/8;
    eq = vector<bool>((s2*(s2+1))/2);
    cnt = vector<unsigned int>(sz,1);
    char c;
    for(int i = 0;i < sz;i++){
        cin >> c;
        if(c == 'B') tree[i] = true;
    }
    for(int i = sz/2-1;i >= 0;i--){
        ll res = (1LL*cnt[2*i+1] * cnt[2*i+2]) % 998244353;
        if(!isEq(2*i+1,2*i+2)) res = (2LL*res)%998244353;
        cnt[i] = res;
    }
    return deb(cnt[0]);
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
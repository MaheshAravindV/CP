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

int score(string s,int l,int r){
    if(l == r-1) return 1;
    if(l > r-1) return 0;
    vector<int> breaks;
    int curr = 0;
    for(int i = l;i <= r;i++){
        if(s[i] == '(') curr++;
        else curr--;
        if(curr == 0) breaks.push_back(i);
    }
    if(breaks.size() == 1) return 2*score(s,l+1,r-1);
    else{
        int sum = 0;
        int lcurr = l,rcurr;
        for(int i : breaks){
            rcurr = i;
            sum += score(s,lcurr,rcurr);
            lcurr = rcurr+1;
        }
        sum += score(s,lcurr,r);
        return sum;
    }
}

int scoreOfParentheses(string s) {
    int l = 0,r = s.size()-1;
    return score(s,l,r);
}

int main() {
    string s;
    cin >> s;
    deb(scoreOfParentheses(s));
}
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

string next(string curr){
    int k = curr.length()-1;
    if(curr == string(k+1,'z'))return string(k+2,'a');
    while(k > 0 && curr[k] == 'z')k--;
    curr[k]++;
    k++;
    while(k < (int)curr.length()){
        curr[k] = 'a';
        k++;

    }
    return curr;
}
set<string> ss;
int main(){
    // string curr = "a";
    // for(int i =0; i < 1000;i++){
    //     cout << curr << endl;
    //     curr = next(curr);
    // }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin  >> n;
        string s;
        cin  >> s;
        for(int i = 1;i <= n;i++)for(int j = 0; j < n-i+1;j++)ss.insert(s.substr(j,i));
        string curr = "a";
        while(ss.find(curr) != ss.end())curr = next(curr);
        cout << curr << '\n';    
        ss.clear();
    }
    return 0;
}
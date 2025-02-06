#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define per(i, n) for(int i = (n) - 1; i >= 0; i--)
using ll = long long;
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define vvl vector<vl>
using namespace std;
template<class T, class U>
bool chmax(T &a, const U &b){ return a < b ? (a = b, 1) : 0; }
template<class T, class U>
bool chmin(T &a, const U &b){ return a > b ? (a = b, 1) : 0; }
const ll inf=1LL<<60;

int main(void){
    string s,t;
    cin >> s >> t;
    vector<string> ans;
    vi flag(s.length(),false);
    rep(i,s.length()){
        if(s[i] > t[i]){
            s[i] = t[i];
            ans.push_back(s);
        }
        else if(s[i] == t[i])continue;
        else flag[i] = true;
    }
    per(i,s.length()){
        if(flag[i]){
            s[i] = t[i];
            ans.push_back(s);
        }
    }
    cout << ans.size() << endl;
    rep(i,ans.size()){
        cout << ans[i] << endl;
    }
    return 0;
}
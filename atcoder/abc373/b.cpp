#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define per(i, n) for(int i = (n) - 1; i >= 0; i--)
using ll = long long;
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define vvl vector<vl>
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using namespace std;
template<class T, class U>
bool chmax(T &a, const U &b){ return a < b ? (a = b, 1) : 0; }
template<class T, class U>
bool chmin(T &a, const U &b){ return a > b ? (a = b, 1) : 0; }
const ll inf=1LL<<60;

int main(void){
    string s;
    cin >> s;
    vi list(0);
    rep(i,26)list.push_back(s[i]-'A');
    vi list2(26);
    rep(i,26)list2[list[i]]=i;
    int ans = 0;
    rep(i,25)ans += abs(list2[i+1]-list2[i]);
    cout << ans << endl;
    return 0;
}
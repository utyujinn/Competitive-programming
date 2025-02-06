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
  string s,t;
  cin >> s >> t;
  int ans = 0;
  rep(i,min(s.length(),t.size())){
    if(s[i]!=t[i]){
      cout << i+1 << endl;
      return 0;
    }
  }
  if(s.length() != t.size()){
    cout << min(s.length(),t.length())+1 << endl;
    return 0;
  }
  cout << 0 << endl;
  return 0;
}
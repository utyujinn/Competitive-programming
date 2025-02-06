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
  ll n;
  cin>> n;
  vl k(n);
  rep(i,n)cin >> k[i];
  ll total = 0;
  rep(i,n)total += k[i];
  ll ans = total;
  rep(i,pow(2,n)){
    ll a =0,b=0;
    rep(j,n){
      if((i>>j)%2){
        a+=k[j];
      }
      else{
        b+=k[j];
      }
    }
    chmin(ans,max(a,b));
  }
  cout << ans;
}

/*
int main(void){
  ll n;
  cin>> n;
  vl k(n);
  rep(i,n)cin >> k[i];
  int total=0;
  rep(i,n)total += k[i];
  vl dp(total/2+1,-1);
  dp[0] = 1;
  rep(i,n){
    rep(j,total/2+1){
      if(j >= k[i])dp[j] = dp[j-k[i]];
    }
  }
  per(j,total/2+1){
    if(dp[j]==1){
      cout << total-j << endl;
      break;
    }
  }
  return 0;
}
*/
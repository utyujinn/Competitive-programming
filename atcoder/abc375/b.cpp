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
  cin >> n;
  ll x,y,px,py;
  double ans=0;
  cin >> x >> y;
  ans += sqrt(x*x+y*y);
  px = x;
  py = y;
  rep(i,n-1){
    cin >> x >> y;
    ans += sqrt((x-px)*(x-px)+(y-py)*(y-py));
    px = x; py = y;
  }
  ans += sqrt(x*x+y*y);
  cout << std::fixed << std::setprecision(10) << ans << endl;

  return 0;
}
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
  vector<vector<char>> a(n+1,vector<char>(n+1));
  vector<vector<char>> b(n+1,vector<char>(n+1));
  rep(i,n)rep(j,n)cin >> a[i+1][j+1];
  for(int i = 1; i <= (n/2);i++){
    if(i%2==1)
      b=a;
    else a=b;
    for(int j = i; j <= n+1-i; j++){
      for(int k = i; k <= n+1-i; k++){
        if(i%2==1)
          b[j][n+1-k] = a[k][j];
        else{
          a[j][n+1-k] = b[k][j];
        }
      }
    }
  }
  rep(i,n){
    rep(j,n){
      if((n/2)%2==0)
        cout << a[i+1][j+1];
      else
        cout << b[i+1][j+1];
    }
    cout << endl;
  }
  return 0;
}
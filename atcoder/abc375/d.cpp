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
  vl pc(26,-1);
  vl ppc(26,-1);
  vl ccnt(26,0);
  vl csum(26,0);
  vl psum(26,0);
  ll n = s.length();
  ll ans = 0;
  rep(i,n){
    int a = s[i]-'A';
    ll tmp = csum[a];
    if(pc[a] != -1){
      if(pc[a]!=i-1){
        csum[a] += csum[a]+(i-pc[a])*ccnt[a]-1;
      }
      else if(ccnt[a]>1){
        csum[a] += psum[a]+(i-ppc[a])*(ccnt[a]-1)-1;
      }
    }
    ccnt[a]++;
    ppc[a] = pc[a];
    pc[a] = i;
    psum[a] = tmp;
  }
  rep(i,26){
    ans += csum[i];
  }
  cout << ans << endl;
  return 0;
}
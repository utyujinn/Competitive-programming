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
  ll n,s,t;
  cin >> n >> s >> t;
  vi a(n),b(n),c(n),d(n);
  float line = 0;
  rep(i,n){
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    int dx = c[i]-a[i],dy = d[i]-b[i];
    line += sqrt(dx*dx+dy*dy)/t;
  }
  vector<vector<vector<vector<float>>>> cost(n,vector<vector<vector<float>>>(n,vector<vector<float>> (2,vector<float> (2))));
  
  rep(i,n)rep(j,n)rep(k,2)rep(l,2){
    int dx,dy;
    if(k == 0){
      if(l == 0){
        dx = a[j] - a[i];
        dy = b[j] - b[i];
      }
      if(l == 1){
        dx = c[j] - a[i];
        dy = d[j] - b[i];
      }
    }
    else{
      if(l == 0){
        dx = a[j] - c[i];
        dy = b[j] - d[i];
      }
      if(l == 1){
        dx = c[j] - c[i];
        dy = d[j] - d[i];
      }
    }
    cost[i][j][k][l] = sqrt(dx*dx+dy*dy)/s;
  }
  vl p(n);
  rep(i,n)p[i] = i;
  float ans = 50000;
  do{
    rep(j,pow(2,n)){
      float area = 0;
      rep(k,n-1){
        area += cost[p[k]][p[k+1]][(((~(j>>k))%2)+2)%2][(j>>(k+1))%2];
      }
      if(j%2==0)area += sqrt(a[p[0]]*a[p[0]] + b[p[0]]*b[p[0]])/s;
      else area += sqrt(c[p[0]]*c[p[0]] +d[p[0]]*d[p[0]])/s;
      chmin(ans,area);
    }
  }while(next_permutation(all(p)));

  cout << std::fixed << std::setprecision(10) << line+ans << endl;
  return 0;
}
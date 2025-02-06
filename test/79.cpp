#include<iostream>
#include<vector>

using namespace std;

int main(){
  int n,m,q;
  cin >> n >> m >> q;
  vector<vector<int>> list(n+1, vector<int>(n+1,0));
  for(int i = 0; i < m; i++){
    int l,r;
    cin >> l >> r;
    while(r!=n+1){
      list[l][r]++;
      r++;
    }
  }

  for(;q--;){
    int s,e;
    long ans = 0;
    cin >> s >> e;
    for(int i = s; i <= e; i++){
      ans += list[i][e];
    }
    cout << ans << endl;
  }
}


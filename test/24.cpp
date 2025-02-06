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

vi d,f;
vi seen;
int t = 0;
void dfs(vvi g,int v){
    d[v] = ++t;
    seen[v] = true;
    for(auto next_v : g[v]){
        if(seen[next_v])continue;
        else dfs(g,next_v);
    }
    f[v] = ++t;
}

int main(void){
    int n;
    cin >> n;
    vvi g(n+1,vi());
    rep(i,n){
        int u,k;
        cin >> u >> k;
        rep(j,k){
            int tmp;
            cin >> tmp;
            g[u].push_back(tmp);
        }
    }
    d.resize(n+1);
    f.resize(n+1);
    seen.resize(n+1,false);
    
    for(int i=1;i <= n; i++){
        if(!seen[i])dfs(g,i);
    }
    rep(i,n){
        cout << i+1 << " " << d[i+1] << " "<< f[i+1] << endl;
    }

    return 0;
}
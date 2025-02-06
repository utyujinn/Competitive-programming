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

int main(){
    int n,m;
    cin >> n >> m;
    vector<tuple<ll,ll,ll>> edges;
    rep(i,m){
        ll u,v,w;
        cin >> u >> v >> w;
        edges.emplace_back(u,v,w);
    }
    vl x(n+1,inf);
    vl seen(n+1,0);
    x[get<0>(edges[0])] = 0;
    rep(i,m){
    for(const auto& [u,v,w] : edges){
        if(!seen[u] && !seen[v])x[u] = 0;
        if(x[v]!=inf){
            x[u] = x[v]-w;
        }
        else{
            x[v] = x[u]+w;
        }
        seen[u] = 1;
        seen[v] = 1;
    }}
    ll max=x[1],min=x[1];

    rep(i,n){
        if(x[i+1] == inf)x[i+1] = 0;
        chmax(max,x[i+1]);
        chmin(min,x[i+1]);
    }
    if(max > 1000000000000000000){
        rep(i,n)x[i]-=max-1000000000000000000;
    }
    if(min < -1000000000000000000){
        rep(i,n)x[i]+=-1000000000000000000-min;
    }
    rep(i,n){
        cout << x[i+1] << ' ';
    }
}

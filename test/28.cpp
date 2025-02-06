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

    vi dist(n+1,-1);
    queue<int> que;
    dist[1] = 0; 
    que.push(1);

    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int nv:g[v]){
            if(dist[nv]!=-1)continue;
            else{
                dist[nv] = dist[v]+1;
                que.push(nv);
            }
        }
    }

    rep(i,n){
        cout << i+1 << " " << dist[i+1] << endl;
    }

    return 0;
}
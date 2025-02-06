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
    int r,c;
    cin >> r >> c;
    int sy,sx,gy,gx;
    cin >> sy >> sx >> gy >> gx;
    vector m(r+1,vector<char>(c+1));
    rep(i,r)rep(j,c)cin >> m[i+1][j+1];
    vvi dist(r+1,vi(c+1,-1));
    queue<pair<int,int>> que;

    dist[sy][sx] = 0;
    que.push(make_pair(sy,sx));

    while(!que.empty()){
        pair<int,int> v = que.front();
        que.pop();
        rep(i,4){
            pair<int,int> nv;
            if(i==0)nv = make_pair(v.first-1,v.second);
            if(i==1)nv = make_pair(v.first,v.second+1);
            if(i==2)nv = make_pair(v.first+1,v.second);
            if(i==3)nv = make_pair(v.first,v.second-1);
            if(dist[nv.first][nv.second] == -1 && m[nv.first][nv.second] == '.'){
                que.push(nv);
                dist[nv.first][nv.second] = dist[v.first][v.second] + 1;
            }
        }
    }
    cout << dist[gy][gx] << endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct UnionFind{
    vi parent,size;
    UnionFind(int n) : parent(n,-1), size(n,1){}
    int root(int x){
        if(parent[x]==-1)return x;
        return parent[x] = root(parent[x]);
    }
    bool isSame(int x,int y){
        return root(x)==root(y);
    }
    void unite(int x, int y){
        if(isSame(x,y))return;
        int rx = root(x);
        int ry = root(y);
        if(size[rx]<size[ry]){
            parent[rx] = ry;
            size[ry] += size[rx];
        }
        else{
            parent[ry] = rx;
            size[rx] += size[ry];
        }
    }
};

struct Edge {
    ll s,t,w;
};

bool comp_e(const Edge &e1, const Edge &e2) {
    return e1.w < e2.w;
}

int main(void){
    ll v,e;
    cin >> v >> e;
    vector<Edge> edges(e);
    rep(i,e){
        ll s,t,w;
        cin >> s >> t >> w;
        edges[i] = {s,t,w};
    }
    sort(edges.begin(),edges.end(),comp_e);

    UnionFind uf(v);

    ll ans = 0;
    ll cnt = 0;
    for(int i = 0;cnt < v-1 && i < e; i++){
        if(!uf.isSame(uf.root(edges[i].s),uf.root(edges[i].t))){
            uf.unite(edges[i].s,edges[i].t);
            ans += edges[i].w;
            cnt++;
        }
    }
    cout << ans << endl;
    return 0;
}

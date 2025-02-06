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
const ll inf=1LL<<60;

int main(void){
    int h,w,q;
    cin >> h >> w >> q;

    vector<set<int>> row(h),col(w);
    rep(i,h)rep(j,w){
        row[i].insert(j);
        col[j].insert(i);
    }

    /*
    auto erase = [&](int i, int j) { row[i].erase(j), col[j].erase(i); };

    while(q--){
        int r,c;
        cin >> r >> c;
        r--;c--;
        if(row[r].count(c)){
            erase(r,c);
            continue;
        }

        auto it = col[c].lower_bound(r);
        if(it != begin(col[c])){
            erase(*prev(it),c);
        }

        it = col[c].lower_bound(r);
        if(it != end(col[c])){
            erase(*it,c);
        }

        it = row[r].lower_bound(c);
        if(it != begin(row[r])){
            erase(r,*prev(it));
        }

        it = row[r].lower_bound(c);
        if(it != end(row[r])){
            erase(r,*it);
        }
    }
*/

    while(q--){
        int r,c;
        cin >> r >> c;
        r--;c--;
        if(row[r].count(c)){
            row[r].erase(c);
            col[c].erase(r);
            continue;
        }

        auto it = col[c].lower_bound(r);
        if(it != begin(col[c])){
            auto itr = *prev(it);
            row[itr].erase(c);
            col[c].erase(itr);
        }

        it = col[c].lower_bound(r);
        if(it != end(col[c])){
            int itr = *it;
            row[itr].erase(c);
            col[c].erase(itr);
        }

        it = row[r].lower_bound(c);
        if(it != begin(row[r])){
            int itr = *prev(it);
            row[r].erase(itr);
            col[itr].erase(r);
        }

        it = row[r].lower_bound(c);
        if(it != end(row[r])){
            int itr = *it;
            row[r].erase(itr);
            col[itr].erase(r);
        }
    }
    //*/
    int ans = 0;
    rep(i,h){
        ans+=row[i].size();
    }
    cout << ans << endl;
}

/*
int main(void){
    ll h,w,q;
    cin >> h >> w >> q;
    vvl wall(h,vl(w,true));
    ll ans = h*w;
    vvl lastru(h,vl(w,-1));
    vvl lastrd(h,vl(w,-1));
    vvl lastcl(h,vl(w,-1));
    vvl lastcr(h,vl(w,-1));
    vl rcnt(h,0);
    vl ccnt(w,0);
    while(q--){
        ll r,c;
        cin >> r >> c;
        r--;
        c--;
        if(wall[r][c]){
            wall[r][c]=false;
            ans--;
        }
        else {
            for(int i = r-1;i>=0;i--){
                if(ccnt[c]==h)break;
                if(lastru[i][c]!=-1)i=lastru[i][c],0;
                if(wall[i][c]){
                    wall[i][c]=false;
                    ans--;
                    ccnt[c]++;
                    lastru[r][c]=max(i-1,0);
                    break;
                }
            }
            for(int i = r+1;i<h;i++){
                if(ccnt[c]==h)break;
                if(lastrd[i][c]!=-1)i=lastrd[i][c];
                if(wall[i][c]){
                    wall[i][c]=false;
                    ans--;
                    ccnt[c]++;
                    lastrd[r][c]=min(i+1,(int)h-1);
                    break;
                }
            }
            for(int i = c-1;i>=0;i--){
                if(rcnt[r]==w)break;
                if(lastcl[r][i]!=-1)i=lastcl[r][i];
                if(wall[r][i]){
                    wall[r][i]=false;
                    ans--;
                    rcnt[r]++;
                    lastcl[r][c]=max(i-1,0);
                    break;
                }
            }
            for(int i = c+1;i<w;i++){
                if(rcnt[r]==w)break;
                if(lastcr[r][i]!=-1)i=lastcr[r][i];
                if(wall[r][i]){
                    wall[r][i]=false;
                    ans--;
                    rcnt[r]++;
                    lastcr[r][c]=min(i+1,(int)w-1);
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
*/
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
    int n;
    cin >> n;
    vi p(n),q(n);
    rep(i,n){
        cin >> p[i];
    }
    rep(i,n){
        cin >> q[i];
    }

    vi v(n);
    rep(i,n)v[i] = i+1;
    int idx=0;
    int a,b;
    do{
        bool flag = true;
        rep(i,n){
            if(p[i]!=v[i]){
                flag = false;
                break;
            }
        }
        if(flag == true)a = idx;

        flag = true;
        rep(i,n){
            if(q[i]!=v[i]){
                flag = false;
                break;
            }
        }
        if(flag == true)b = idx;
        idx++;
    }while(next_permutation(all(v)));
    
    cout << abs(a-b) << endl;

    return 0;
}
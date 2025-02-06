#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define per(i, n) for(int i = (n) - 1; i >= 0; i--)
using ll = long long;
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define vvl vector<vl>
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
template<class T, class U>
bool chmax(T &a, const U &b){ return a < b ? (a = b, 1) : 0; }
template<class T, class U>
bool chmin(T &a, const U &b){ return a > b ? (a = b, 1) : 0; }
const ll inf=1LL<<60;

int main(void){
    set<int> a;
    rep(i,10)a.insert(i);
    set<int>::iterator itr = a.begin();
    set<int>::iterator itr2 = next(itr);
    auto itr3 = a.lower_bound(1);
    cout << *itr3 << *prev(itr3) << *itr3 << endl;

    cout << *itr << *itr2 << endl;
    return 0;
}
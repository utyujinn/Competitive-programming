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
    ll n;
    cin >> n;
    ll in = n;
    vl prime_list(0);
    vl ans(0);
    while(n%2==0){
        ans.push_back(2);
        n/=2;
    }
    int i = 3;
    while(i*i < in){
        bool flag=0;
        for(auto a: prime_list){
            if(i%a==0){
                flag=1;
                break;
            }
        }
        if(flag==1){
            i+=2;
            continue;
        }
        else prime_list.push_back(i);

        while(n%i==0){
            ans.push_back(i);
            n/=i;
        }
        i+=2;
    }
    cout << in << ":";
    for(auto a: ans){
        cout << " " << a;
    }
    if(n!=1)cout << " " << n;
    cout << endl;

    return 0;
}
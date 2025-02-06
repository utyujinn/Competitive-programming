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
    vector<double> x(n),y(n);
    double ans = 0;
    rep(i,n){
        cin >> x[i] >> y[i];
    }
    vi a(n);
    rep(i,n){
        a[i] = i;
    }
    int c = 0;
    do {
        double tmp = 0;
    
        rep(i,n-1){
            tmp += sqrt(pow(x[a[i]]-x[a[i+1]],2)+pow(y[a[i]]-y[a[i+1]],2));
        }
        ans += tmp;
        c++;
    }while(next_permutation(a.begin(),a.end()));
    ans /= c;
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}

/*
int main(void){
    int n;
    cin >> n;
    vector<double> x(n),y(n);
    double ans = 0;
    rep(i,n){
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            ans += sqrt(pow(abs(x[i]-x[j]),2)+pow(abs(y[i]-y[j]),2));
        }
    }
    ans = ans/((n-1)*(n)/2)*(n-1);
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}
*/
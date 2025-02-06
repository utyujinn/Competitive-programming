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

template<int MOD> struct modint {
    ll x;
    mint(ll x=0){
        x = (x % mod + mod) % mod;
    }
    mint& operator+=(const mint& a){
        if((x += a.x) >= mod) x -= mod;
        return *this;
    }
}

template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};

template<int MOD> struct modint {
    ll val;
    constexpr modint(ll v = 0) noexept : val(v%MOD){
        if (val < 0) val += MOD;
    }

}

const int MOD = 998244353;
using mint = Fp<MOD>;

int main(){
    ll n,k;
    cin >> n >> k;
    vl a(n);
    rep(i,n)cin >> a[i];

    map<ll,mint> m;
    m[0]=1;
    mint all = 1;
    ll acc = 0;

    rep(i,n){
        acc += a[i];
        ll ban = acc - k;
        mint cur = all - m[ban];
        m[acc]+=cur,all+= cur;
        if(i+1==n)cout << cur.val() << endl;
    }
}
/*
int main(void){
    ll n,k;
    cin >> n >> k;
    vl a(n);
    rep(i,n)cin >> a[i];
    vvl sum(n+1,vl(n+1,0));
    rep(i,n)m[i+1][i+1]=a[i];

    for(int l = 2;l <= n; l++){
        for(int i = 1; i <= n-l+1; i++){
            int j = i+l-1;
            for(int k = i; k <= j-1; k++){
                m[i][j] = min(m[i][j],m[i][k]+m[k+1][j]+c[k-1]*c[j-1]*r[i-1]);
            }
        }
    }

    cout << m[1][n] << endl;
    return 0;
}
*/
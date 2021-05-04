#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
using pll = pair<long long, long long>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define REP(i, n) for (long long i = 0; i < (long long)(n); ++i)
#define REP2(i, a, b) for (long long i = a; i < (long long)(b); ++i)
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, deque<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class T> ostream& operator << (ostream &s, set<T> P)
{ for(auto it : P) { s << "<" << it << "> "; } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P)
{ for(auto it : P) { s << "<" << it.first << "->" << it.second << "> "; } return s << endl; }
 
// 4-neighbor (or 8-neighbor)
// (dx[0], dy[0])=(1,0) で右に1進む。(dx[4], dy[4])=(1, 1) で斜め右45度方向に1進む
const vector<int> dx = {1, 0, -1, 0, 1, -1, 1, -1};
const vector<int> dy = {0, 1, 0, -1, 1, 1, -1, -1};
 
// Union-Find
struct UnionFind {
    vector<int> par;
 
    UnionFind() { }
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};
 
ostream& operator << (ostream& s, UnionFind uf) {
    map<int, vector<int> > res;
    for (int i = 0; i < uf.par.size(); ++i) {
        int r = uf.root(i);
        res[r].push_back(i);
    }
    for (map<int, vector<int> >::iterator it = res.begin(); it != res.end(); ++it) {
        s << endl;
        for (int j = 0; j < (int)it->second.size(); ++j) {
            s << it->second[j] << ", ";
        }
    }
    return s << endl;
}
 
// modint
template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() const { return MOD; }
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
            a -= t * b, swap(a, b);
            u -= t * v, swap(u, v);
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
    friend constexpr istream& operator >> (istream& is, Fp<MOD>& x) noexcept {
        is >> x.val;
        x.val %= MOD;
        if (x.val < 0) x.val += MOD;
        return is;
    }
    friend constexpr ostream& operator << (ostream& os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD>& r, long long n) noexcept {
        if (n == 0) return 1;
        if (n < 0) return modpow(modinv(r), -n);
        auto t = modpow(r, n / 2);
        t = t * t;
        if (n & 1) t = t * r;
        return t;
    }
    friend constexpr Fp<MOD> modinv(const Fp<MOD>& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b, swap(a, b);
            u -= t * v, swap(u, v);
        }
        return Fp<MOD>(u);
    }
};
 
// Binomial coefficient
template<class T> struct BiCoef {
    vector<T> fact_, inv_, finv_;
    constexpr BiCoef() {}
    constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1) {
        init(n);
    }
    constexpr void init(int n) noexcept {
        fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);
        int MOD = fact_[0].getmod();
        for(int i = 2; i < n; i++){
            fact_[i] = fact_[i-1] * i;
            inv_[i] = -inv_[MOD%i] * (MOD/i);
            finv_[i] = finv_[i-1] * inv_[i];
        }
    }
    constexpr T com(int n, int k) const noexcept {
        if (n < k || n < 0 || k < 0) return 0;
        return fact_[n] * finv_[k] * finv_[n-k];
    }
    constexpr T fact(int n) const noexcept {
        if (n < 0) return 0;
        return fact_[n];
    }
    constexpr T inv(int n) const noexcept {
        if (n < 0) return 0;
        return inv_[n];
    }
    constexpr T finv(int n) const noexcept {
        if (n < 0) return 0;
        return finv_[n];
    }
};
 
const int MOD = 1000000007;
//const int MOD = 998244353;
using mint = Fp<MOD>;
BiCoef<mint> bc;
 
 
 
int main() {
    int H, W, x, y;
    cin >> H >> W >> x >> y;
    --x, --y;  // 0スタートなので

    vector<string> fi(H);  // iを添え字にすることで行ベクトルであることを明示
    for (int i = 0; i < H; ++i) cin >> fi[i];

    /* ラムダ式
    キャプチャ[]という機能を使うことで、ラムダ式の外側で宣言されている変数のコピーを格納して、
    ラムダ式の内部で使えるようになる
    [&]でデフォルトのキャプチャとして参照を指定
    ラムダ式内部での変更は元の変数へ、元の変数に対する変更はラムダ式の内部へと相互に影響
    またmutable指定をしていなくても（元の変数がconstでなければ）変更可能 */

    // int i, int jを引数に持ち，boolを返す関数(オブジェクト)をokに格納
    auto ok = [&](int i, int j) -> bool {
        // (i, j) が盤面外の場合はfalse
        if (i < 0 || i >= H || j < 0 || j >= W) return false;
        if (fi[i][j] == '#') return false;
        return true;
    };

    int res = 1;  // 自分自身
    // 4-neighbor (or 8-neighbor)
    // const vector<pair<int, int>> dxdy = {}
    // const vector<int> dx = {1, 0, -1, 0, 1, -1, 1, -1};
    // const vector<int> dy = {0, 1, 0, -1, 1, 1, -1, -1};

    for (int dir = 0; dir < 4; ++dir) {  // 方向は4つ
        int cx = x + dx[dir], cy = y + dy[dir];
        // ↑ ここまでで4通りの移動を表現できた
        while (ok(cx, cy)) {  // '.'かどうか判定
            ++res;
            // 同じ方向に進み続ける
            cx += dx[dir], cy += dy[dir];  
        }
    }
    cout << res << endl;
}
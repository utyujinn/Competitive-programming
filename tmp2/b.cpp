#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

struct DP {
    int dp;
    DP(int val) : dp(val) {}
};

vector<vector<int>> G; // 隣接リスト
vector<int> dp;        // 各頂点のDP値

// 二項演算を表すラムダ式
function<int(int, int)> merge_dp = [](int dp_cum, int d) -> int {
    return max(dp_cum, d); // dpの最大値を取る
};

// 新たな部分木のDPを計算するラムダ式
function<int(DP)> add_root = [](DP d) -> int {
    return DP(d.dp + 1).dp; // 根を追加
};

// DFS関数
void dfs(int v, int p = -1) { // 頂点v, 親p
    int deg = G[v].size();     // 頂点vの次数
    if (deg == 1 && p != -1) { // 末端にいる時
        dp[v] = 0;
        return;
    }
    int dp_cum = 0;
    for (int i = 0; i < deg; i++) {
        int u = G[v][i]; // u: vの子
        if (u == p) continue; // 親なら探索しない
        dfs(u, v); // dp[u] の計算
        dp_cum = merge_dp(dp_cum, dp[u]); // 1.の二項演算
    }
    dp[v] = add_root(DP(dp_cum)); // 2.の計算
}

int main() {
    int N, M;
    cin >> N >> M;
    G.resize(N);
    dp.resize(N, 0);
    // 辺の入力
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
				u--,v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    // DFSの実行
    dfs(0); // 根を0と仮定
    // 結果の出力
    for (int i = 0; i < N; i++) {
        cout << "dp[" << i << "] = " << dp[i] << endl;
    }
    return 0;
}

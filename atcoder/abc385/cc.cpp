#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int max_decoration_buildings(int n, const vector<int>& heights) {
    unordered_map<int, vector<int>> height_indices;

    // 高さごとのビルのインデックスを記録
    for (int i = 0; i < n; ++i) {
        height_indices[heights[i]].push_back(i);
    }

    int max_count = 1; // 1つのビルを選んだ場合を考慮

    // 各高さについて
    for (const auto& [height, indices] : height_indices) {
        int length = indices.size();
        if (length < 2) {
            continue;
        }

        // 等間隔の組み合わせをチェック
        for (int i = 0; i < length; ++i) {
            for (int j = i + 1; j < length; ++j) {
                int interval = indices[j] - indices[i];
                int count = 2; // 最初の2つのビルをカウント

                // 次のビルを探す
                int next_index = indices[j] + interval;
                while (find(indices.begin(), indices.end(), next_index) != indices.end()) {
                    count++;
                    next_index += interval;
                }

                max_count = max(max_count, count);
            }
        }
    }

    return max_count;
}

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int result = max_decoration_buildings(n, h);
    cout << result << endl;

    return 0;
}

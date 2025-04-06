#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

using Matrix = vector<vector<long long>>;
using Vector = vector<long long>;

Matrix multiply(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

Matrix matrix_pow(Matrix A, long long p) {
    int n = A.size();
    Matrix result(n, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) result[i][i] = 1; // 単位行列
    while (p) {
        if (p % 2) result = multiply(result, A);
        A = multiply(A, A);
        p /= 2;
    }
    return result;
}

Vector multiply(const Matrix& A, const Vector& v) {
    int n = A.size();
    Vector result(n, 0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            result[i] = (result[i] + A[i][j] * v[j]) % MOD;
    return result;
}

int main() {
    Matrix A = {
        {25, 24, 24, 24, 0},
        {1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 26}
    };
    long long exponent = 1e18;
    Vector initialVector = {1, 0, 0, 0, 0};
    Vector result = multiply(matrix_pow(A, exponent), initialVector);
    long ans=0;
    for(int i=0;i<4;i++){
      ans=(ans+result[i])%MOD;
    }
    cout<<ans<<endl;
    return 0;
}

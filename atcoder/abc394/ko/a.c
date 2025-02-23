#include <stdio.h>
#include <float.h>

int main() {
    float value = 1.0f;
    float sum = 0.0f;
    int count = 0;

    // 浮動小数点の精度を測定
    while (1) {
        sum += value;
        count++;

        // ある桁数での正確な値との誤差を測定
        if (sum != (float)count) {
            break; // 誤差が発生した場合にループを終了
        }
    }

    printf("float型で正確に表せる桁数: %d\n", count - 1);
    printf("floatの精度: %e\n", FLT_EPSILON);

    return 0;
}

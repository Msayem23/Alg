#include <iostream>
using namespace std;

int main() {
    const int N = 3;

    // Updated augmented matrix
    float ar[N][N + 1] = {
        {1, 1, 1, 10},
        {3, 0, 2, 19},
        {3, 2, 4, 27}
    };

    // Forward elimination
    for (int i = 0; i < N; i++) {
        float pivot = ar[i][i];
        for (int j = i; j <= N; j++) {
            ar[i][j] /= pivot;
        }
        for (int k = i + 1; k < N; k++) {
            float factor = ar[k][i];
            for (int j = i; j <= N; j++) {
                ar[k][j] -= factor * ar[i][j];
            }
        }
    }

    // Back substitution
    float x[N];
    for (int i = N - 1; i >= 0; i--) {
        x[i] = ar[i][N];
        for (int j = i + 1; j < N; j++) {
            x[i] -= ar[i][j] * x[j];
        }
    }

    // Output
    for (int i = 0; i < N; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}

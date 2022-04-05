#include "temp.h"

std::vector<Fraction > gaussFraction(std::vector<std::vector<Fraction > >& A, std::vector<Fraction >& b) {
    int n = A.size();

    std::vector<std::vector<Fraction > > Matrix (n, std::vector<Fraction > (n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Matrix[i][j] = A[i][j];
        }
        Matrix[i][n] = b[i];
    }

    std::vector<std::vector<Fraction > > Matrix_copy (n, std::vector<Fraction > (n + 1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            Matrix_copy[i][j] = Matrix[i][j];
        }
    }

    for (int k = 0; k < n; k++) {
        std::cout << "k = " << k << std::endl;
        for (int i = 0; i < n + 1; i++) {
            Matrix_copy[k][i] /= Matrix[k][k];
        }

        for (int i = k + 1; i < n; i++) {
            Fraction koef = Matrix_copy[i][k] / Matrix_copy[k][k];
            for(int j = 0; j < n + 1; j++) {
                Matrix_copy[i][j] -= Matrix_copy[k][j] * koef;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n + 1; j++) {
                Matrix[i][j] = Matrix_copy[i][j];
            }
        }
    }

    for (int k = n - 1; k > -1; k--) {
        for (int i = n; i > -1; i--) {
            Matrix_copy[k][i] /= Matrix[k][k];
        }

        for (int i = k - 1; i > -1; i--) {
            Fraction koef = Matrix_copy[i][k] / Matrix_copy[k][k];
            for(int j = n; j > - 1; j--) {
                Matrix_copy[i][j] -= Matrix_copy[k][j] * koef;
            }
        }
    }

    std::vector<Fraction > x(n);
    for (int i = 0; i < Matrix_copy.size(); i++) {
        x[i] = Matrix_copy[i][Matrix_copy[0].size() - 1];
    }

    return x;
}

std::vector<std::vector<Fraction > > grapeFraction(const std::vector<std::vector<Fraction> >& G, const std::vector<std::vector<Fraction> >& H) {
    int a = G.size();
    int b = G[0].size();
    assert(H.size() == b);
    int c = H[0].size();
    int d = b / 2;
    // вычисление rowFactors для G
    std::vector<Fraction > rowFactor (a);
    for (int i = 0; i < a; i++) {
        rowFactor[i] = G[i][0] * G[i][1];
        for(int j = 1; j < d; j++) {
            rowFactor[i] += G[i][2 * j] * G[i][2 * j + 1];
        }
    }
    // вычисление columnFactors для H
    std::vector<Fraction > columnFactor (c);
    for (int i = 0; i < c; i++) {
        columnFactor[i] = H[0][i] * H[1][i];
        for (int j = 1; j < d; j++) {
            columnFactor[i] += H[2 * j][i] * H[2 * j + 1][i];
        }
    }
    // вычисление матрицы R
    std::vector<std::vector<Fraction > > R (a, std::vector<Fraction > (c, Fraction(0,1)));
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < c; j++) {
            R[i][j] = -rowFactor[i] - columnFactor[j];
            for (int k = 0; k < d; k++) {
                R[i][j] += (G[i][2 * k] + H[2 * k + 1][j]) * (G[i][2 * k + 1] + H[2 * k][j]);
            }
        }
    }
    // прибавление членов в случае нечетной общей размерности
    if (2 * d != b) {
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < c; j++) {
                R[i][j] += G[i][b - 1] * H[b - 1][j];
            }
        }
    }

    return R;
};

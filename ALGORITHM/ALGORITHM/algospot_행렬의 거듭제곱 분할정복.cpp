#include <iostream>
#include <string.h>
using namespace std;
#define MATRIX_SIZE 50

class SquareMatrix {
private:
	int **matrix;
	int s;
public:
	SquareMatrix() {}
	SquareMatrix(int n, int val) {
		s = n;
		matrix = new int*[n];
		for (int i = 0; i < n; i++) {
			matrix[i] = new int[n];
			memset(matrix[i], 0, sizeof(int)*n);
			matrix[i][i] = val;
		}
	}
	int size() {
		return s;
	}
	SquareMatrix operator*(SquareMatrix m) {
		int i, j, k;
		for (i = 0; i < s; i++) {
			for (j = 0; j < s; j++) {
				int tmp = 0;
				for (k = 0; k < s; k++) {
					tmp += this->matrix[i][k] * m.matrix[k][j];
				}
				this->matrix[i][j] = tmp;
			}
		}
		return *this;
	}
	void printMatrix() {
		for (int i = 0; i < s; i++) {
			for (int j = 0; j < s; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};

SquareMatrix identityMatrix(int n) {
	SquareMatrix s(n, 1);
	return s;
}

SquareMatrix pow(const SquareMatrix &A, int m) {
	SquareMatrix M;
	if (m == 0) return identityMatrix(MATRIX_SIZE);
	if (m % 2 == 1) return pow(A, m - 1) * A;
	M = pow(A, m / 2);
	return M*M;
}

int main()
{
	SquareMatrix m1(MATRIX_SIZE,2);
	
	m1.printMatrix();
	m1 = pow(m1, 20);
	m1.printMatrix();

	return 0;
}
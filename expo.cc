#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
void power(int M[][36], int M_p[][36], int M_pow[][36], int dim) {
	for(int k = 0; k < dim; k++) {
		for(int i = 0; i < dim; i++) {
			int sum = 0;
			for(int j = 0; j < dim; j++) {
				sum += M[k][j] * M_p[j][i];
			}
			M_pow[k][i] = sum % 2;
		}
	}
	
}
int trace(int M[][36], int dim) {
	int sum = 0;
	for(int i = 0; i < dim; i++) {
		sum += M[i][i];
	}
	return sum;
}
int main() {
	// n^2 x n^2 matrix
	int M[36][36];
	int M_pow[36][36];
	int M_p[36][36];
	int c_par[20][20];
	int pow = 1;
	int dim = 36;
	int ldim = 6;
	int period = 1;
	int limit = 20;
	for(int i = 0; i < dim; i++) {
		for(int j = 0 ; j < dim; j++) {
			M[i][j] = 0;
			M_pow[i][j] = 0;
			M_p[i][j] = 0;
		}
	}
	for(int i = 0; i < limit; i++) {
		for(int j = 0; j < limit; j++) {
			c_par[i][j] = 0;
		}
	}
	// main diag
	for(int i = 0; i < dim; i++) {
		M[i][i] = 0;
		M_p[i][i] = 0;
		M_pow[i][i] = 0;
	}
	// 2nd diag
	for(int i = 0; i < dim - 1; i++) {
		int num = 1;
		if((i + 1) % ldim == 0) {
			num = 0;
		}
		M[i + 1][i] = num;
		M[i][i + 1] = num;
		M_p[i + 1][i] = num;
		M_p[i][i + 1] = num;
		M_pow[i + 1][i] = num;
		M_pow[i][i + 1] = num;
	}
	// 3rd diag
	for(int i = 0; i < dim - ldim; i++) {
		M[i + ldim][i] = 1;
		M[i][i + ldim] = 1;
		M_p[i + ldim][i] = 1;
		M_p[i][i + ldim] = 1;
		M_pow[i + ldim][i] = 1;
		M_pow[i][i + ldim] = 1;
	}
	// do the power
	// trace(M_p, dim) != dim || period == 1
	while(period < 20) {
		cout << "Power of T: " << period << endl;
		for(int i = 0; i < dim; i++) {
			for(int j = 0; j < dim; j++) {
				cout << M_pow[i][j];
				c_par[period][j] += M_pow[i][j];
				if(j < dim - 1)
					cout << " ";
			}
			cout << endl;
		}
		power(M, M_p, M_pow, dim);
		for(int i = 0; i < dim; i++) {
			for(int j = 0; j < dim; j++) {
				M_p[i][j] = M_pow[i][j];
			}
		}
		
		period += 1;
	}
	for(int i = 0; i < dim; i++) {
			for(int j = 0; j < dim; j++) {
				cout << M_pow[i][j];
				cout << " ";
			}
			cout << endl;
		}
	cout << endl;
	cout << "Period: " << period << endl;
	cout << "Period matrix: " << endl;
	for(int i = 0; i < limit; i++) {
		for(int j = 0; j < limit; j++) {
			cout << c_par[i][j] % 2 << " ";
		}
		cout << endl;
	}
}






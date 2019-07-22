#include <cmath>			// Call out math function
#include<iostream>
 	#include "vector.h"		// Vector operation
 	#include "matrix.h"		// Matrix operation
 	#include "constants.h"
 	

#include <cstdlib>			// Std functions?

#include <cassert>			// Assert function
#include <ctime>			// For stuff to be fully random, and shit


using namespace std;		// Standard name calling

int main()
{
	srand ( time(NULL) ); // Make random values truly random
	// Set parameters
	double *v, *w, *t, *u, *x, *y;
	int size_v, size_w, size_t, size_u, size_x, size_y;
	
	double **A, **B, **C, **D, **E, **F, **G;
	int numRows_A, numCols_A,
		numRows_B, numCols_B,
		numRows_C, numCols_C,
		numRows_D, numCols_D,
		numRows_E, numCols_E,
		numRows_F, numCols_F,
		numRows_G, numCols_G;
	
	int alpha, p, det_A, det_B;
	
	/**
	Select: v, w = begin vectors
			A, B = begin matrices
			t = v+w  u=A*v   x = alpha*v
			C = A+B  D=A-B
			E = A*B
			F = alpha * A
			G = transpose(A)
	**/
	
	// Input size for vectors and matrices
	cout << "Input length of vector v ";
	cin >> size_v;
	cout << "Input length of vector w ";
	cin >> size_w;
	cout << "Input length of vector t ";
	cin >> size_t;
	cout << "Input length of vector u ";
	cin >> size_u;
	cout << "Input length of vector x ";
	cin >> size_x;
	cout << "Input length of vector y ";
	cin >> size_y;
	
	cout << "Input the number of rows for matrix A ";
	cin >> numRows_A;
	cout << "Input the number of columns for matrix A ";
	cin >> numCols_A;
	cout << "Input the number of rows for matrix B ";
	cin >> numRows_B;
	cout << "Input the number of columns for matrix B ";
	cin >> numCols_B;
	
	cout << "Input the number of rows for matrix C ";
	cin >> numRows_C;
	cout << "Input the number of columns for matrix C ";
	cin >> numCols_C;
	cout << "Input the number of rows for matrix D ";
	cin >> numRows_D;
	cout << "Input the number of columns for matrix D ";
	cin >> numCols_D;
	
	cout << "Input the number of rows for matrix E ";
	cin >> numRows_E;
	cout << "Input the number of columns for matrix E ";
	cin >> numCols_E;
	cout << "Input the number of rows for matrix F ";
	cin >> numRows_F;
	cout << "Input the number of columns for matrix F ";
	cin >> numCols_F;

	cout << "Input the number of rows for matrix G ";
	cin >> numRows_G;
	cout << "Input the number of columns for matrix G ";
	cin >> numCols_G;
	
	cout << "Input alpha constant ";
	cin >> alpha;
	cout << "Input p value ";
	cin >> p;
	
	
	
	// Allocation values for vectors	
	v = allocateVec(size_v);
	w = allocateVec(size_w);
	t = allocateVec(size_t);
	u = allocateVec(size_u);
	x = allocateVec(size_x);
	y = allocateVec(size_y);
	
	// Random values for v and w
	randomVec(v, size_v);
	randomVec(w, size_w);
	
	// Zero values for t, u, x
	zeroVec(t, size_t);
	zeroVec(u, size_u);
	zeroVec(x, size_x);
	zeroVec(y, size_y);
	
	// Allocation values for matrices
	A = allocate(numRows_A, numCols_A);
	B = allocate(numRows_B, numCols_B);
	C = allocate(numRows_C, numCols_C);	
	D = allocate(numRows_D, numCols_D);
	E = allocate(numRows_E, numCols_E);
	F = allocate(numRows_F, numCols_F);
	G = allocate(numRows_G, numCols_G);
	
	// Random values for A and B
	randomMat(A, numRows_A, numCols_A);
	randomMat(B, numRows_A, numCols_B);
	
	// Zero values for matrices C, D, E, F, G
	zeroMat(C, numRows_C, numCols_C);
	zeroMat(D, numRows_D, numCols_D);
	zeroMat(E, numRows_E, numCols_E),
	zeroMat(F, numRows_F, numCols_F);
	zeroMat(G, numRows_G, numCols_G);
	
	// Print original values: vector v and w, matrices A and B
	cout << "Vector v is " << endl;
	printVec(v, size_v);
	cout << " " << endl;
	
	cout << "Vector w is " << endl;
	printVec(w, size_w);
	cout << " " << endl;
	
	cout << "Matrix A is " << endl;
	printMat(A, numRows_A, numCols_A);
	cout << " " << endl;
	
	cout << "Matrix B is " << endl;
	printMat(B, numRows_B, numCols_B);
	cout << " " << endl;
	
	// t=v+w and print vector
	addVecVec(v, size_v,
			  w, size_w,
			  t, size_t);
	cout << "Vector t=v+w is " << endl;
	printVec(t, size_t);
	cout << " " << endl;
	
	// u=v-w and print vector
	subVecVec(v, size_v,
			  w, size_w,
			  u, size_u);
	cout << "Vector u=v-w is " << endl;
	printVec(u, size_u);
	cout << " " << endl;
	
	// Calculate norm of the vector
	double norm_v, norm_w;
	norm_v = norm(v, size_v, p);
	norm_w = norm(w, size_w, p);
	
	cout << "Norm " << p << " of v is " << norm_v << endl;
	cout << "Norm " << p << " of w is " << norm_w << endl;
	cout << "Norm infite of v is " << norm(v, size_v, p_inf) << endl;
	cout << "Norm infite of w is " << norm(w, size_w, p_inf) << endl;
	cout << endl;
	
	// x = alpha * v and print
	multiScaVec(v, size_v,
				alpha,
				x, size_x);
	cout << "x= alpha * v is " << endl;
	printVec(x, size_x);
	cout << endl;
	
	// y = A*v and print
	multiVecMat(A, numRows_A, numCols_A,
				v, size_v,
				y, size_y);
	cout << "Vector y=A*v is " << endl;
	printVec(y, size_y);
	cout << endl;
	
	// C = A+B and print
	addMatMat(A, numRows_A, numCols_A,
			  B, numRows_B, numCols_B,
			  C, numRows_C, numCols_C);
	cout << "C=A+B is " << endl;
	printMat(C, numRows_C, numCols_C);
	cout << " " << endl;
	
	// D=A-B and print
	subMatMat(A, numRows_A, numCols_A,
			  B, numRows_B, numCols_B,
			  D, numRows_D, numCols_D);
	cout << "D=A-B is " << endl;
	printMat(D, numRows_D, numCols_D);
	cout << " " << endl;
	
	// E= A*B and print
	multiMatMat(A, numRows_A, numCols_A,
			   B, numRows_B, numCols_B,
			   E, numRows_E, numCols_E);
	cout << "Matrix E=A*B is " << endl;
	printMat(E, numRows_E, numCols_E);
	cout << " " << endl;
	
	// F= alpha*A and print
	multiScaMat(A, numRows_A, numCols_A,
				alpha,
				F, numRows_A, numCols_F);
	cout << "Matrix F= alpha * A is " << endl;
	printMat(F, numRows_F, numCols_F);
	cout << " " << endl;
	
	// G=transpose(A) and print
	transMat(A, numRows_A, numCols_A,
			 G, numRows_G, numCols_G);
	cout << "Matrix G, transpose of A is " << endl;
	printMat(G, numRows_G, numRows_G);
	cout << endl;
	
/**	// det of matrices A and B
	det_A = determinant(A, numRows_A, numRows_A);
	det_B = determinant(B, numRows_B, numRows_B);
	cout << "Determinant of Matrix A is " << det_A << endl;
	cout << "Determinant of Matrix B is " << det_B << endl; **/
	
	// Deallocation
	deallocateVec(v);
	deallocateVec(w);
	deallocateVec(t);
	deallocateVec(u);
	deallocateVec(x);
	deallocateVec(y);
	
	deallocate(A, numRows_A, numCols_A);
	deallocate(B, numRows_B, numCols_B);
	deallocate(C, numRows_C, numCols_C);
	deallocate(D, numRows_D, numCols_D);
	deallocate(E, numRows_E, numCols_E);
	deallocate(F, numRows_F, numCols_F);
	deallocate(G, numRows_G, numCols_G);	
	
	return 0;
}

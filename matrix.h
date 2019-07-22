#ifndef _MATRIX_HEADER_
#define _MATRIX_HEADER_

// Memory allocation
double ** allocate(const int& numRows, const int& numCols);

// Delete memory and values
void deallocate(double ** A, const int& numRows, const int& numCols);

// Put in the matrix: zero entries
void zeroMat(double** A, const int& numRows, const int& numCols);

// Put in the matrix: random values, select btw 0 and 20
void randomMat(double** A, const int& numRows, const int& numCols);

/**

// 4. Set entry v_i with a given value for vector v of size size
double& setElementMat(double** A, const int& numRows, const int& numCols,
				   const int& i,
				   const int& j);
				   
**/

// Print out the matrix 
void printMat(double** A, const int& numRows, const int& numCols);

//  Adding matrices
void addMatMat(double** A, const int& numRows_A, const int& numCols_A,
			   double** B, const int& numRows_B, const int& numCols_B,
			   double** C, const int& numRows_C, const int& numCols_C);

// Subtrating matrices C=A-B
void subMatMat(double** A, const int& numRows_A, const int& numCols_A,
			   double** B, const int& numRows_B, const int& numCols_B,
			   double** C, const int& numRows_C, const int& numCols_C);
			   
// Multiply a vector and a matrix w=A*v
void multiVecMat(double** A, const int& numRows_A, const int& numCols_A,
				 double* v, const int& size_v,
				 double* w, const int& size_w);
				 
// Multiply a scalar with a matix B=alpha*A
void multiScaMat(double** A, const int& numRows_A, const int& numCols_A,
				 const int& alpha,
				 double** B, const int& numRows_B, const int& numCols_B);

// Multiply a vector with a vector C=A*B
void multiMatMat(double** A, const int& numRows_A, const int& numCols_A,
				 double** B, const int& numRows_B, const int& numCols_B,
				 double** C, const int& numRows_C, const int& numCols_C);
				 
// Transpose matrix A --> B
void transMat(double** A, const int& numRows_A, const int& numCols_A,
			  double** B, const int& numRows_B, const int& numCols_B);

/** // Det of matrix
int determinant(double** A, const int& numRows_A, const int& numCols_A);
**/


#endif

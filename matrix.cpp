#include <cmath>			// Call out math function
#include<iostream>
 	#include "matrix.h"		// Matrix operation
 	#include "vector.h"
 	
 	
#include <cstdlib>			// Std functions?

#include <cassert>			// Assert function
#include <ctime>			// For stuff to be fully random, and shit

using namespace std;

// Allocation values
double ** allocate(const int& numRows, const int& numCols)
{
	double **A;
	A = new double*[numRows];
	
	for (int i=0; i<numRows; ++i)
		A[i] = new double[numCols];
	return A;
}

// Delete memory and values
void deallocate(double ** A, const int& numRows, const int& numCols)
{
	for (int i = 0; i<numRows; ++i)
		delete[] A[i];
	
	delete[] A;
}

// Put in the matrix: zero entries
void zeroMat(double** A, const int& numRows, const int& numCols)
{
	assert((numRows>=0) && (numCols>=0)); // Make sure some idiots put in the correct values, perhaps?
	for (int i=0; i<numRows; ++i)
		for (int j=0; j<numCols; ++j)
			A[i][j] = 0;
}

// Put in the matrix: random values, select btw 0 and 20
// Possibility for manual input limit later?
void randomMat(double** A, const int& numRows, const int& numCols)
{
	assert((numRows>=0) && (numCols>=0)); // Make sure some idiots put in the correct values, perhaps?
	
	int l;
	cout << "Enter limit for Matrix" << endl;
	cin >> l;
	for (int i=0; i<numRows; ++i)
		for (int j=0; j<numCols; ++j)
			A[i][j] = (double)(rand()% l);
	
}

/**
// Change the data of a certain element within the matrix
double& setElementMat(double** A, const int& numRows, const int& numCols,
				   const int& i,
				   const int& j)
{
	assert((i>=0) && (i<numRows);			// Again, making sure the input numbers are correct
	assert((j>=0) && (j<numCols));			// Ditto
	
	return A[i][j];
}
**/

// Print out the matrix
void printMat(double** A, const int& numRows, const int& numCols)
{
	cout << endl;
	for (int i =0; i<numRows; ++i)
	{
		for (int j= 0; j<numCols; ++j)
			cout << " " << A[i][j];
		cout << endl;
	}
	cout << endl;
}

// Adding matrices C=A+B
void addMatMat(double** A, const int& numRows_A, const int& numCols_A,
			   double** B, const int& numRows_B, const int& numCols_B,
			   double** C, const int& numRows_C, const int& numCols_C)
{
	assert((numRows_A == numRows_B) && (numCols_A == numCols_B)); // Make sure the "first" two matrices are at same size
	assert((numRows_C == numRows_B) && (numCols_C == numCols_B)); // Make sure the prep'ed matrix for result match the dimension with the first 2
	
	for (int i=0; i< numRows_C; ++i)
	{
		for (int j = 0; j<numCols_C; ++j)
			C[i][j] = A[i][j] + B[i][j];
	}
}

// Subtrating matrices C=A-B
void subMatMat(double** A, const int& numRows_A, const int& numCols_A,
			   double** B, const int& numRows_B, const int& numCols_B,
			   double** C, const int& numRows_C, const int& numCols_C)
{
	assert((numRows_A == numRows_B) && (numCols_A == numCols_B)); // Make sure the "first" two matrices are at same size
	assert((numRows_C == numRows_B) && (numCols_C == numCols_B)); // Make sure the prep'ed matrix for result match the dimension with the first 2
	
	for (int i=0; i< numRows_C; ++i)
	{
		for (int j = 0; j<numCols_C; ++j)
			C[i][j] = A[i][j] - B[i][j];
	}
}

// Multiply a vector and a matrix w=A*v
void multiVecMat(double** A, const int& numRows_A, const int& numCols_A,
				 double* v, const int& size_v,
				 double* w, const int& size_w)
{
	assert(numCols_A == size_v);   // Make sure the dimensions of the matrix match the dimensions of the vectors
	assert(numRows_A == size_w);
	
	zeroVec(w, size_w);
	
	for (int i=0; i<size_w; ++i)
		for (int j=0; j<numCols_A; ++j)
			w[i] += A[i][j] * v[j];

}

// Multiply a scalar with a matix B=alpha*A
void multiScaMat(double** A, const int& numRows_A, const int& numCols_A,
				 const int& alpha,
				 double** B, const int& numRows_B, const int& numCols_B)
{
	assert ((numRows_A == numRows_B) && (numCols_A == numCols_B));  // Make sure the prep'ed matrix match the original matrix in dimension
	for (int i=0; i<numRows_B; ++i)
		for (int j=0; j<numCols_B; ++j)
			B[i][j] = alpha * A[i][j];
}

// Multiply a vector with a vector C=A*B
void multiMatMat(double** A, const int& numRows_A, const int& numCols_A,
				 double** B, const int& numRows_B, const int& numCols_B,
				 double** C, const int& numRows_C, const int& numCols_C)
{
	assert((numRows_A == numRows_B) && (numCols_A == numCols_B));  // Make sure the "first" two matrices are at same size
	assert((numRows_C == numRows_B) && (numCols_C == numCols_B)); // Make sure the prep'ed matrix for result match the dimension with the first 2
	
	zeroMat(C, numRows_C, numCols_C);
	
	for (int i = 0; i< numRows_C; ++i)
		for (int j = 0; j < numCols_C; ++j)
			for (int k = 0; k < numCols_A; ++k)
				C[i][j] += A[i][k] * B[k][j];
 }

// Transpose matrix A --> B
void transMat(double** A, const int& numRows_A, const int& numCols_A,
			  double** B, const int& numRows_B, const int& numCols_B)
{
	assert(numRows_A == numCols_B);
	assert(numCols_A == numRows_B);
	for (int i=0; i<numRows_A; ++i)
		for (int j=0; j<numCols_A; ++j)
			B[j][i] = A[i][j];
}

/** // Det of matrix
int determinant(double** A, const int& numRows_A, const int& numCols_A) 
{   
   int det = 0;
   double** subA;
   assert(numRows_A == numCols_A);
   
   if (numRows_A == 2)
      return ((A[0][0] * A[1][1]) - (A[1][0] * A[0][1]));
   else 
   {
      for (int x = 0; x < numRows_A; x++) 
	  {
            int subi = 0; 
            for (int i = 1; i < numRows_A; i++) 
			{
               int subj = 0;
               for (int j = 0; j < numRows_A; j++) 
			   {
                  if (j == x)
                  continue;
                  subA[subi][subj] = A[i][j];
                  subj++;
               }
               subi++;
            }
            det = det + (pow(-1, x) * A[0][x] * determinant(subA, numRows_A -1, numCols_A -1));
      }
   }
   return det;
} **/


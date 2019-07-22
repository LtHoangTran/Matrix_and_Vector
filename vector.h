#ifndef _VECTOR_HEADER_
#define _VECTOR_HEADER_

// Allocation values
double* allocateVec(const int& size);

// Delete memory and values
void deallocateVec(double* a);

// Put in the vector: zero entries
void zeroVec(double* a, const int& size_a);

// Put in the vector: random values, select btw 0 and 20
void randomVec(double* a, const int& size_a);

// Print out the vector
void printVec(double* a, const int& size_a);

// Calcualte the norm
double norm(double* v, const int& size, const int& p);

// Adding 2 vectors c=a+b
void addVecVec(double* a, const int& size_a,
			   double* b, const int& size_b,
			   double* c, const int& size_c);
			   
// Substracting b from a to have c, or c=a-b
void subVecVec(double* a, const int& size_a,
			   double* b, const int& size_b,
			   double* c, const int& size_c);

// Dot product of 2 vectors dot = a.b
double dotVecVec(double* a, const int& size_a,
				 double* b, const int& size_b);


// Cross product of 2 vectors A=a*b
void crossVecVec(double* a, const int& size_a,
				 double* b, const int& size_b,
				 double** A, const int& numRows_A, const int& numCols_A);

// Multiply a vector with a scalar b=alpha * a
void multiScaVec(double* a, const int& size_a,
				 const int& alpha,
				 double* b, const int& size_b);

#endif

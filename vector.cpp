#include <iostream>
#include <cassert>	// Assert function
#include <cstdlib>
#include <cmath>
#include "vector.h"
#include "constants.h"


#include <ctime>			// For stuff to be fully random

using namespace std;

// Allocation values
double* allocateVec(const int& size)
{
	double* a;
	a = new double[size];
	return a;
}

// Delete memory and values
void deallocateVec(double* a)
{
	delete[] a;
}

// Put in the vector: zero entries
void zeroVec(double* a, const int& size_a)
{
	assert(size_a >= 0);
	for (int i = 0; i < size_a; ++i)
		a[i] = 0;
}

// Put in the vector: random values, select btw 0 and 20
// Possibility for manual input limit later?
void randomVec(double* a, const int& size_a)
{
	assert(size_a >= 0);
	int l;
	cout << "Enter limit for Vector " << endl;
	cin >> l;
	for (int i = 0; i < size_a; ++i)
		a[i] = (double)(rand()% l);
}

// Print out the vector
void printVec(double* a, const int& size_a)
{
	cout << endl;
	for (int i =0; i<size_a; ++i)
		cout << " " << a[i] << " ";
	cout << endl;
}


// Calcualte the norm
double norm(double* v, const int& size, const int& p)
{
	assert((p > 0) && (p < p_inf + 1));
	
	// Normal p	
	if (p < p_inf)
	{
		double norm(0);
		for (int i = 0; i < size; ++i)
			norm += pow(abs(v[i]), p);
		norm = pow(norm, 1.0/p);
		return norm;
	}
	
	
	// Infinite p
	else
	{
		double norm(abs(v[0]));
		for (int i = 1; i < size - 1; ++i)
			if (norm <= abs(v[i + 1]))
				norm = v[i + 1];
		return norm;
	}
}

// Adding 2 vectors c=a+b
void addVecVec(double* a, const int& size_a,
			   double* b, const int& size_b,
			   double* c, const int& size_c)
{
	assert(size_a == size_b); // Make sure 2 vectors have the same size
	assert(size_a == size_c);
	
	for(int i =0; i<size_a; ++i)
		c[i] = a[i] + b[i];
}

// Substracting b from a to have c, or c=a-b
void subVecVec(double* a, const int& size_a,
			   double* b, const int& size_b,
			   double* c, const int& size_c)
{
	assert(size_a == size_b); // Make sure 2 vectors have the same size
	assert(size_a == size_c);
	
	for(int i =0; i<size_a; ++i)
		c[i] = a[i] - b[i];
}


// Dot product of 2 vectors dot=a.b
double dotVecVec(double* a, const int& size_a,
				 double* b, const int& size_b)
{
	assert(size_a == size_b); // Make sure 2 vectors have the same size
	
	double dot(0);
	
	for (int i=0; i<size_a; ++i)
		dot += a[i] * b[i];
	
	return dot; 
}

// Cross product of 2 vectors A=a*b
void crossVecVec(double* a, const int& size_a,
				 double* b, const int& size_b,
				 double** A, const int& numRows_A, const int& numCols_A)
{
	assert(size_a == numRows_A); 
	assert(size_b == numCols_A); // Matrix size must match the vectors
	
	for (int i=0; i<numRows_A; ++i)
		for (int j=0; j<numCols_A; ++j)
			A[i][j] = a[i] * b[j];
}

// Multiply a vector with a scalar b=alpha * a
void multiScaVec(double* a, const int& size_a,
				 const int& alpha,
				 double* b, const int& size_b)
{
	assert(size_a == size_b); // Make sure 2 vectors have the same size
	for (int i=0; i<size_b; ++i)
		b[i] = alpha * a[i];
}


#ifndef __MATRIX__H__
#define __MATRIX__H__

// typedef Matrix
typedef struct Matrix {
    unsigned int nrows;
    unsigned int ncols;
    TElement** data;
} TMatrix;

// Allocates memory to create a new matrix
TMatrix* newMatrix(unsigned int nrows, unsigned int ncols);

// Deallocates memory of a matrix
void freeMatrix(TMatrix* m);

// Sets all entries in a matrix to value v
void resetMatrix(TMatrix* m, TElement v);

void setMatrix(TMatrix* m, TElement* V, int n);

// Compares all entries in matrix m to matrix n, returns 1 if true, 0 if false. -1 if something is NULL, -2 if different dimensions.
int compareMatrix(TMatrix* m, TMatrix* n);

// Updates the value in entry [row,col] with value v
void putEntry(TMatrix* m, unsigned int row, unsigned int col, TElement v);

// Gets the value at entry [row,col].
TElement getEntry(TMatrix* m, unsigned int row, unsigned int col);

// Writes the values from matrix m into as much available space as possible in matrix t. For example if m is of size mxn, and
// the output is of size axb where m<a and n<b the rows 0,...,a adn column 0,...,b are written into t.
void copyMatrix(TMatrix* m, TMatrix* t);

// Write the transpose of matrix m into t.
void transpose(TMatrix* m, TMatrix* t);

// print matrix
void printMatrix(TMatrix* m);

// Adds two matrices m and n and writes result into t, matrices must be the same size
void addMatrix(TMatrix* m, TMatrix* n, TMatrix* t);

// Multiplies two matrices m and n and writes result into t, cols in m must equal rows in n, and t must be of correct size.
void multiplyMatrix(TMatrix* m, TMatrix* n, TMatrix* t);

TElement determinant(TMatrix* m);

#endif

#include "helpers.h"
#include "matrix.h"

TMatrix* newMatrix(unsigned int nrows, unsigned int ncols) {
    // allocate space for matrix struct
    TMatrix* newM = (TMatrix*) malloc(sizeof(TMatrix));

    // allocate space for the pointers to arrays
    TElement** data = (TElement**) malloc(nrows*sizeof(TElement*));

    // allocate space for all elements
    TElement* storage = (TElement*) malloc(nrows*ncols*sizeof(TElement));

    if (newM == NULL || data == NULL || storage == NULL) {
        free(newM);
        free(data);
        free(storage);
        return NULL;
    }

    for (int i = 0; i < nrows; i++) {
        data[i] = storage + ncols*i;
    }
    newM->data = data;
    newM->nrows = nrows;
    newM->ncols = ncols;

    return newM;
}


void freeMatrix(TMatrix* m) {
    if (m == NULL) {
        return;
    }
    if (m->data) {
        free(m->data[0]);
        free(m->data);
    }

    free(m);
}

void putEntry(TMatrix* m, unsigned int row, unsigned int col, TElement v) {
    if (m == NULL || m->data == NULL || row >= m->nrows || col >= m->ncols) {
        return;
    }

    m->data[row][col] = v;
}

TElement getEntry(TMatrix* m, unsigned int row, unsigned int col) {
    if (m == NULL || m->data == NULL || row >= m->nrows || col >= m->ncols) {
        return MATRIX_NOT_DEFINED;
    }

    return m->data[row][col];
}

void resetMatrix(TMatrix* m, TElement v) {
    if (m == NULL || m->data == NULL) {
        return;
    }

    for (int i = 0; i < m->nrows; i++) {
        for (int j = 0; j < m->ncols; j++) {
            m->data[i][j] = v;
        }
    }
}

void setMatrix(TMatrix* m, TElement* V, int n) {
    if (m == NULL || m->data == NULL || V == NULL || n > m->nrows * m->ncols)
        return;

    for (int i = 0; i < n; i++) {
        int row = i / m->ncols;
        int col = i % m->ncols;
        m->data[row][col] = V[i];
    }
}

int compareMatrix(TMatrix *m, TMatrix *n) {
    if (m == NULL || m->data == NULL || n == NULL || n->data == NULL) {
        return MATRIX_NOT_DEFINED;
    }

    if (m->nrows != n->nrows || m->ncols != n->ncols) {
        return MATRIX_DIMENSIONS_INCORRECT;
    }

    for (int i = 0; i < m->nrows; i++) {
        for (int j = 0; j < m->ncols; j++) {
            if (m->data[i][j] != n->data[i][j])
                return FALSE;
        }
    }

    return TRUE;
}



void copyMatrix(TMatrix *m, TMatrix *t) {
    if (m == NULL || t == NULL || m->data == NULL || t->data == NULL) {
        return;
    }

    for (int i = 0; i < min(m->nrows, t->nrows); i++) {
        for (int j = 0; j < min(m->ncols, t->ncols); j++) {
            t->data[i][j] = m->data[i][j];
        }
    }
}

void transpose(TMatrix *m, TMatrix *t) {
    if (m == NULL || t == NULL || m->data == NULL || t->data == NULL || m->nrows != t->ncols || m->ncols != t->nrows)
        return;
    
    for (int i = 0; i < m->nrows; i++) {
        for (int j = 0; j < m->ncols; j++) {
            t->data[j][i] = m->data[i][j];
        }
    }
}

void printMatrix(TMatrix* m) {
    if (m == NULL || m->data == NULL)
        return;
    
    for (int i = 0; i < m->nrows; i++) {
        for (int j = 0; j < m->ncols; j++) {
            printf("%3d ", m->data[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(TMatrix* m, TMatrix* n, TMatrix* t) {
    if (m == NULL || m->data == NULL || n == NULL || n->data == NULL || t == NULL || t->data == NULL || m->nrows != n->nrows || m->nrows != t->nrows || n->nrows != t->nrows || m->ncols != n->ncols || m->ncols != t->ncols || n->ncols != t->ncols)
        return;
    
    for (int i = 0; i < m->nrows; i++) {
        for (int j = 0; j < m->ncols; j++) {
            t->data[i][j] = m->data[i][j] + n->data[i][j];
        }
    }
}

void multiplyMatrix(TMatrix* m, TMatrix* n, TMatrix* t) {
    if (m == NULL || m->data == NULL || n == NULL || n->data == NULL || t == NULL || t->data == NULL || m->ncols != n->nrows || m->nrows != t->nrows || n->ncols != t->ncols)
        return;

    for (int i = 0; i < m->nrows; i++) {
        for (int j = 0; j < n->ncols; j++) {
            int sum = 0;
            for (int p = 0; p < m->ncols; p++) {
                sum += m->data[i][p] * n->data[p][j];
            }
            t->data[i][j] = sum;
        }
    }
}

TElement determinant(TMatrix* m) {
    if (m == NULL || m->data == NULL || m->nrows != m->ncols)
        return -1;

    int n = m->nrows;
    if (n == 2) 
        return m->data[0][0]*m->data[1][1] - m->data[0][1]*m->data[1][0];

    TElement det = 0;

    for (int i = 0; i < m->ncols; i++) {

        TMatrix* submatrix = newMatrix(n-1, n-1);
        int n_elements = (n-1)*(n-1);
        TElement* sublist = (TElement*) malloc(n_elements*sizeof(TElement));

        int idx = 0;
        for (int r = 1; r < m->nrows; r++) {
            for (int c = 0; c < m->ncols; c++) {
                if (c == i) continue;
                sublist[idx++] = m->data[r][c];
            }
        }


        setMatrix(submatrix, sublist, n_elements);

        int sign = (i%2==0) ? 1 : -1;

        det += sign * m->data[0][i] * determinant(submatrix);

        freeMatrix(submatrix);
        free(sublist);
    }
    return det;
    
}
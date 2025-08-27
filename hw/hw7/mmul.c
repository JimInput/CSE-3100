#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "matrix.h"

// Search TODO to find the locations where code needs to be completed

#define     NUM_THREADS     10

typedef struct {
    unsigned int id;
    TMatrix *m, *n, *t;
} thread_arg_t;

static void * thread_main(void * p_arg)
{
    thread_arg_t* args = (thread_arg_t*) p_arg;
    int size = (args->m->nrows / NUM_THREADS)+1;
    for (int row = size*args->id; row < size*args->id+size && row < args->m->nrows; row++) {
        for (int col = 0; col < args->n->ncols; col++) {
            double sum = 0;
            // printf("i: %d, row: %d, col: %d\n", args->id, row, col);
            for (int e = 0; e < args->m->ncols; ++e) {
                sum = sum + args->m->data[row][e] * args->n->data[e][col];
            }
            args->t->data[row][col] = sum;
        }
    }
    return NULL;
}

void assign_args(thread_arg_t* args, int i, TMatrix* m, TMatrix* n, TMatrix* t) {
    args->id = i;
    args->m = m;
    args->n = n;
    args->t = t;
}

/* Return the sum of two matrices.
 *
 * If any pthread function fails, report error and exit. 
 * Return NULL if anything else is wrong.
 *
 * Similar to mulMatrix, but with multi-threading.
 */
TMatrix * mulMatrix_thread(TMatrix *m, TMatrix *n)
{
    if (    m == NULL || n == NULL
         || m->ncols != n->nrows )
        return NULL;

    TMatrix * t = newMatrix(m->nrows, n->ncols);
    if (t == NULL)
        return t;

    //TODO
    pthread_t threads[NUM_THREADS];
    thread_arg_t thread_args[NUM_THREADS];
    int rc;
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        // assign_args(&thread_args[i], i, m, n, t);
        thread_args[i].id = i;
        thread_args[i].m = m;
        thread_args[i].n = n;
        thread_args[i].t = t;
        rc = pthread_create(&threads[i], NULL, thread_main, &thread_args[i]);
        if (rc)
            exit(-1);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc)
            exit(-1);
    }

    return t;
}

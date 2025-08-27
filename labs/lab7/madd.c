#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "matrix.h"

#define     NUM_THREADS     4

typedef struct {
    unsigned int id;
    TMatrix *m, *n, *t;
} thread_arg_t;

/* the main function of threads */
static void * thread_main(void * p_arg)
{
    // TODO
    thread_arg_t* args = (thread_arg_t*) p_arg;
    int size = (args->t->nrows / NUM_THREADS)+1;
    for (int row = size*args->id; row < size*args->id+size && row < args->t->nrows; row++) {
        for (int col = 0; col < args->t->ncols; col++) {
            // printf("id: %d, row: %d, col: %d\n", args->id, row, col);
            args->t->data[row][col] = args->m->data[row][col] + args->n->data[row][col];
        }
    }

    return NULL;
}

/* Return the sum of two matrices. The result is in a newly creaed matrix. 
 *
 * If a pthread function fails, report error and exit. 
 * Return NULL if something else is wrong.
 *
 * Similar to addMatrix, but this function uses 2 threads.
 */
TMatrix * addMatrix_thread(TMatrix *m, TMatrix *n)
{
    if (    m == NULL || n == NULL
         || m->nrows != n->nrows || m->ncols != n->ncols )
        return NULL;

    TMatrix * t = newMatrix(m->nrows, m->ncols);
    if (t == NULL)
        return t;

    // TODO
    pthread_t threads[NUM_THREADS];
    thread_arg_t thread_args[NUM_THREADS];
    int rc;
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i].id = i;
        thread_args[i].m = m;
        thread_args[i].n = n;
        thread_args[i].t = t;
        rc = pthread_create(&threads[i], NULL, thread_main, &thread_args[i]);
        if (rc) {
            exit(-1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            exit(-1);
        }
    }

    // for (int row = 0; row < t->nrows; row++) {
    //     for (int col = 0; col < t->ncols; col++) {
    //         printf("%f\n", t->data[row][col]);
    //     }
    // }

    return t;
}

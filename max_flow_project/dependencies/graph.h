#ifndef __GRAPH__H__
#define __GRAPH__H__

typedef struct Graph {
    int** matrix;
    int nvertices;
    int nedges;
} TGraph;

TGraph* newGraph(int nvertices);

void freeGraph(TGraph* G);

void addVertex(TGraph* G, int v);

void addEdge(TGraph* G, int v, int u, int w);

int* neighbors(TGraph* G, int v);

int isConnected(TGraph* G, int v, int u);

TGraph* dfs(TGraph* G, int v);

TGraph* bfs(TGraph* G, int v);

int maxFlow(TGraph* G);

TGraph** min_cut(TGraph* G);





#endif
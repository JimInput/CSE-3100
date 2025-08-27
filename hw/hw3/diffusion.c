#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//TODO
//Implement the below function
//Simulate one particle moving n steps in random directions
//Use a random number generator to decide which way to go at every step
//When the particle stops at a final location, use the memory pointed to by grid to 
//record the number of particles that stop at this final location
//Feel free to declare, implement and use other functions when needed

void one_particle(int ***grid, int n)
{
	int x=0, y=0, z=0;

	for (int i = 0; i < n; ++i) {
		int dir = (rand() % 6) + 1;
		switch (dir) {
			case 1: ++x; break;
			case 2: --x; break;
			case 3: ++y; break;
			case 4: --y; break;
			case 5: ++z; break;
			case 6: --z; break;
		}
	}

	++grid[x+n][y+n][z+n];
}

//This function returns the fraction of particles that lie within the distance
//r*n from the origin (including particles exactly r*n away)
//The distance used here is Euclidean distance
//Note: you will not have access to math.h when submitting on Mimir
double density(int ***grid, int n, double r)
{
	int size = 2*n+1;
	int count = 0;
	int total_particles = 0;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			for (int k = 0; k < size; ++k) {
				// convert from table coordinates to real coordinates
				int x = i - n;
				int y = j - n;
				int z = k - n;
				if (x*x + y*y + z*z <= r*r*n*n) {
					count += grid[i][j][k];
				}
				total_particles += grid[i][j][k];
			}
		}
	}

	return (double) count / total_particles;
} 


//use this function to print results
void print_result(int ***grid, int n)
{
    printf("radius density\n");
    for(int k = 1; k <= 20; k++)
    {
        printf("%.2lf   %lf\n", 0.05*k, density(grid, n, 0.05*k));
    }
}

void diffusion(int n, int m)
{
	int size = 2*n+1;
	int ***grid = (int ***) malloc(size*sizeof(int **));
	for (int i = 0; i < size; ++i) {
		grid[i] = (int **) malloc(size*sizeof(int *));
		for (int j = 0; j < size; ++j) {
			grid[i][j] = (int *) calloc(size,sizeof(int));
		}
	}

	for(int i = 1; i<=m; i++) one_particle(grid, n);

	print_result(grid, n);

}

int main(int argc, char *argv[])
{
	
	if(argc != 3)
	{
		printf("Usage: %s n m\n", argv[0]);
		return 0; 
	}
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);

	assert(n >= 1 && n <=50);
	assert(m >= 1 && m <= 1000000);
	srand(12345);
	diffusion(n, m);
	return 0;
}
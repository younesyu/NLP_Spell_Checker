#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFINITY 999

int minimum (int a, int b) {
	int min = (a < b)? a : b;
	return (min < 0)? INFINITY : min;
}

int minimum3 (int a, int b, int c) {
	return minimum(minimum(a, b), c);
}

int OSA_distance (char *a, char *b) {
	int i, j;
	int cost;
	int distance[strlen(a) + 1][strlen(b) + 1];


	/*	Initializing the distance matrix	*/
	for (i = 0; i <= strlen(a); ++i)
		for (j = 0; j <= strlen(b); ++j)
			distance[i][j] = INFINITY;

	/* Core optimal string alignment distance algorithm */
	for (i = 0; i <= strlen(a); ++i)
		distance[i][0] = i;

	for (j = 0; j <= strlen(b); ++j)
		distance[0][j] = j;

	for (i = 0; i <= strlen(a); ++i) {
		for (j = 0; j <= strlen(b); ++j) {
			cost = (a[i] == b[j]);

			distance[i][j] = minimum3(distance[i - 1][j] + 1,				 		// deletion
									  distance[i][j - 1] + 1,						// insertion 
									  distance[i - 1][j - 1] + cost); 				// substitution
			if (i > 1 
				&& j > 1
				&& a[i] == b[j - 1]
				&& a[i - 1] == b[j])
				distance[i][j] = minimum(distance[i][j], distance[i - 2][j - 2]); 	// transposition
		}
	}

	return distance[strlen(a) + 1][strlen(b) + 1];
}

int main (int argc, char* argv[]) {
	char *string1 = (char *) argv[1];
	char *string2 = (char *) argv[2];
	printf("Mot1\tMot2\tDistance de Levenshtein\n");
	printf("%s\t%s\t%d\n\n\n", string1, string2, OSA_distance(string1, string2));
}
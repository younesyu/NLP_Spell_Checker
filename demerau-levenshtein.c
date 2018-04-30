#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFINITY 50
#define ALPHABET 26

int minimum (int a, int b) {
	int min = (a < b)? a : b;
	return (min < 0)? INFINITY : min;
}

int minimum3 (int a, int b, int c) {
	return minimum(minimum(a, b), c);
}
/*
int minimum4 (int a, int b, int c, int d) {
	return minimum(minimum(a, b), minimum(c, d));
}

int DL_distance (char *a, char *b) {
	int i, j;
	int k, l;
	int da[ALPHABET], db;
	int distance[strlen(a) + 2][strlen(b) + 2];
	int maxdist;

	for (i = 0; i < ALPHABET; ++i)
		da[i] = 0;

	maxdist = strlen(a) + strlen(b);
	distance[0][0] = maxdist;

	for (i = 0; i <= strlen(a); ++i) {
		distance[i][0] = maxdist;
		distance[i][1] = i;
	}
	
	for (j = 0; j <= strlen(b); ++j) {
		distance[0][j] = maxdist;
		distance[1][j] = j;
	}

	for(i = 1; i <= strlen(a); ++i) {
		db = 0;
		for(j = 1; j <= strlen(b); ++j) {
			k = da[b[j]];
			l = db;
			if (a[i] == b[j]) {
				cost = 0;
				db = j;
			}
			else cost = 1;
			int ioffset = i + 2, joffset = j + 2;
			distance[ioffset][joffset] = minimum3(distance[ioffset - 1][joffset - 1] + cost,		 // substitution
									  distance[ioffset - 1][joffset] + 1,						 // deletion
									  distance[ioffset][joffset - 1] + 1,						 // insertion
									  distance[k-1, l-1] + (i-k-1) + 1 + (j - l - 1) // transposition
									  );

		}
		da[a[i]] = i;
	}
	return distance[strlen(a) + 2][strlen(b) + 2];
}
*/

int OSA_distance (char *a, char *b) {
	int i, j;
	int cost;
	int distance[strlen(a) + 1][strlen(b) + 1];

	/*	Initializing the distance matrix	*/
	for (i = 0; i <= strlen(a); ++i)
		for (j = 0; j <= strlen(b); ++j)
			distance[i][j] = INFINITY;

	for (i = 0; i <= strlen(a); ++i)
		distance[i][0] = i;

	for (j = 0; j <= strlen(b); ++j)
		distance[0][j] = j;

	/* Core optimal string alignment distance algorithm */
	for (i = 1; i <= strlen(a); ++i) {
		for (j = 1; j <= strlen(b); ++j) {
			cost = !(a[i - 1] == b[j - 1]);
			distance[i][j] = minimum3(distance[i - 1][j] + 1,				 			// deletion
									  distance[i][j - 1] + 1,							// insertion 
									  distance[i - 1][j - 1] + cost); 					// substitution
			if (i > 1 && j > 1
				&& a[i] == b[j - 1]
				&& a[i - 1] == b[j])
				distance[i][j] = minimum(distance[i][j], distance[i - 2][j - 2] + cost); // transposition
		}
	}

	return distance[strlen(a)][strlen(b)];
}

int main (int argc, char* argv[]) {
	char *string1 = (char *) argv[1];
	char *string2 = (char *) argv[2];
	printf("Mot1\tMot2\tDistance de Levenshtein\n");
	printf("%s\t%s\t%d\n\n\n", string1, string2, OSA_distance(string1, string2));
}
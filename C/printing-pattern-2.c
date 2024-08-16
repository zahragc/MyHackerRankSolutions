/*
https://www.hackerrank.com/challenges/printing-pattern-2/problem

Printing Pattern Using Loops
Difficulty: Medium
Max Score: 30

This answer score: 30
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
  	int width = (2 * n) - 1;
  	int *arr = (int*) malloc(width * sizeof(int));
	
	int m = 0;
  	for (int w = n; w >=1; w--) {
  		for (int i = m; i < width - m; i++) {
  			arr[i] = w ;
  		}
  		m++;
  		// print arr
   		for (int s = 0; s < width; s++) {
  			printf("%d ", arr[s]);
  		}
  		printf("\n");
  	}

  	m = width / 2;
  	for (int w = 2; w <= n; w++) {
  		for (int i = m;  i < width - m; i++) {
  			arr[i] = w ;
  		}
  		m--;
  		// print arr
   		for (int s = 0; s < width; s++) {
  			printf("%d ", arr[s]);
  		}
  		printf("\n");
  	}  	
  	
    return 0;
}
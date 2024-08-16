/*
https://www.hackerrank.com/challenges/dynamic-array-in-c/problem

Dynamic Array in C
Difficulty: Medium
Max Score: 40

This answer score: 40
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;

int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);
    
    // answer-p1
    total_number_of_books = (int *) malloc(total_number_of_shelves * sizeof(int));    
    total_number_of_pages = malloc(total_number_of_shelves * sizeof(int*));    
    total_number_of_pages = malloc(total_number_of_shelves * sizeof(int*));        
    int last[total_number_of_shelves];

    for (int i=0; i < total_number_of_shelves; i++) {
    	total_number_of_books[i] = 0;
    	last[i] = 0;
    	total_number_of_pages[i] = malloc(1100 * sizeof(int));
    	for(int j=0; j < 1100; j++) {
    		total_number_of_pages[i][j] = 0;
    	}
    }
    // end answer-p1
    
    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            /*
             * Process the query of first type here.
             */
            int x, y;
            scanf("%d %d", &x, &y);
            // answer-p2
            // place y pages book at the end of shelf x
            total_number_of_books[x] += 1;
            total_number_of_pages[x][last[x]] = y;
            last[x] += 1;
            // end answer-p2

        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}
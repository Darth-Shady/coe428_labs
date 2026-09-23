#include <stdlib.h>
#include "towers.h"
#include <stdio.h> // "A message is displayed on stderr and the exit status is non-zero." --> gonna need stdio.h
//#include "towers.c"

int main(int argc, char **argv)
{
    int n = 3;
    int from = 1;
    int dest = 2;
    
    if (argc == 1) {
        // it will default to towers (3, 1, 2) 
    } else if (argc == 2) {
        n = atoi(argv[1]);
    } else if (argc == 4) {
        n = atoi(argv[1]);
        from = atoi(argv[2]);
        dest = atoi(argv[3]);

        if (from < 1 || from > 3 ||
            dest < 1 || dest > 3 ||
            from == dest) {
            fprintf(stderr, "Invalid tower IDs\n");
            exit(1);
        }
    } 
    
    else {
        fprintf(stderr, "Invalid number of arguments\n");
        exit(1);
    }
    
    if (n < 0) {
        fprintf(stderr, "Invalid number of disks\n");
        exit(1);
    }
    
    towers(n, from, dest);
    exit(0);
}


/* current sequence for n = 3
 * 
 * 
*/


/* correct sequence for n = 3
 * 1 3
 * 2 3 
 * 3 2
 * 1 3
 * 2 1
 * 2 3
 * 1 3
 */

/* correct sequence for n = 4
 * 1 2
 * 1 3
 * 2 3
 * 1 2
 * 3 1
 * 3 2
 * 1 2
 * 1 3
 * 2 3
 * 2 1
 * 3 1
 * 2 3
 * 1 2
 * 1 3
 * 2 3
 */

/**
 * @file lab3/r_client.c
 * @author Hrishikesh Vaze (PB09)
 * @date 2023-01-31
 * @brief Client implementation for RPC
 */

#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <rpc/rpc.h>
#include <netinet/in.h>
#include "square.h"

int main(int argc, char **argv)
{
    /* the client handle is like a file handle,here it points to
    some structure of information maintained by RPC runtime */

    CLIENT *cl;       // RPC RUNTIME HANDLE
    square_in in;     // STRUCTURE FOR INPUT
    square_out *outp; //
    if (argc != 3)    // 4 ARGUMENTS IS A NECESSITY
        exit(0);

    /* this clnt_create allocates one of these structures and returns its pointers to us and we then pass this pointer to RPC runtime each time we call a remote procedure*/

    cl = clnt_create(argv[1], SQUARE_PROG, SQUARE_VERS, "tcp");

    /*argv[1] is IP address*/

    in.arg1 = atol(argv[2]);
    // in.arg2 = atol(argv[3]);

    /*conversion from uppercase to lowercase done and _1 is appended*/

    /* THE CLIENT CALLS A REMOTE PROCEDURE */

    if ((outp = squareproc_1(&in, cl)) == NULL)
        exit(0);

    /*The result is returned back */
    printf("result : %ld\n", outp->res1);
    exit(0);
}

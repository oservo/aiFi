#ifndef FOUNDATION__DESIGN_BY_CONTRACT
#define FOUNDATION__DESIGN_BY_CONTRACT

/* [INCLUDE] *************/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

#include "popc.h"
/* [/INCLUDE] ************/

/* [DEFINE] *************/
#define dbcCleanErrno() (errno == 0 ? "None" : strerror(errno))

#define dbcLogError(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, dbcCleanErrno(), ##__VA_ARGS__)
#define dbcLogWarning(M, ...) fprintf(stderr, "[WARNING] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, dbcCleanErrno(), ##__VA_ARGS__)
#define dbcLogTest(M, ...) fprintf(stderr, "[TEST] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, dbcCleanErrno(), ##__VA_ARGS__)

/* 
	USAGE:
	
	// With no args
	dbcAssert(self != NULL, "[Server] Failed to create server.");

	// With formatting args
	dbcAssert((self->socket = u_open(self->port)) != -1, "[Server] Failed to bind to port %i:",self->port);
*/

// HARD ASSERT
#define dbcAssert(A, M, ...) if(!(A)) {dbcLogError(M, ##__VA_ARGS__); assert(A); }
#define dbcPreCondition 	dbcAssert
#define dbcPostCondition 	dbcAssert
#define dbcInvariant 			dbcAssert
#define dbcRequire 				dbcPreCondition
#define dbcEnsure 				dbcPostCondition

// SOFT WARNING
#define dbcWarning(A, M, ...) if(!(A)) {dbcLogWarning(M, ##__VA_ARGS__); }

// TDD (TEST DRIVEN DEVELOPMENT)
#define dbcTest(A, M, ...) if(!(A)) {dbcLogTest(M, ##__VA_ARGS__); }

/* [/DEFINE] ************/

/* [CONST] *************/
//#define REQUIRED STUFFS HERE
/* [/CONST] ************/

/* [TYPE] *************/


/* [/TYPE] ************/

/* [VARIABLE] *************/

/* [/VARIABLE] ************/

/* [DECLARATION] *************/
#ifdef Cplusplus
extern "C" {
#endif



#ifdef Cplusplus
}
#endif
/* [/DECLARATION] ************/

#endif

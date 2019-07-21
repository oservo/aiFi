#ifndef FRAMEWORK__POPC
#define FRAMEWORK__POPC

// <INCLUDE> //
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

// </INCLUDE> //

// <DEFINE> //
//#define REQUIRED STUFFS HERE
#define ptr         *
#define ptr1d       *
#define ptr2d       **
#define ptr3d       ***
#define ptr4d       ****

#define ptrVal      *
#define ptrVal1d    *
#define ptrVal2d    **
#define ptrVal3d    ***
#define ptrVal4d    ****

#define addr        &

#define fnPtr       *
#define fnPtr1d     *
#define fnPtr2d     **
#define fnPtr3d     ***
#define fnPtr4d     ****


#define public
#define protected 	static
#define private 		static

#define object 			void

#define bool 				int
#define true 				1
#define false 			0
#define null				NULL
#define UNKNOWN			NULL

#define property 		typedef struct
#define subject 		typedef struct
#define pattern 	typedef struct
#define pattern			typedef struct
#define class				typedef struct
#define interface 	typedef struct
#define generic			typedef struct
#define template		typedef struct

#define enumeration	typedef enum
#define delegation	typedef

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


// </DEFINE> //



/* <CONST> *************/
//#define REQUIRED STUFFS HERE
/* </CONST> ************/

/* <TYPE> *************/

enumeration {
	vtInt,
	vtChar,
	vtShort,
	vtLong,
	vtFloat,
	vtDouble,
	vtAny
} varType;

subject var {
	object ptr o; //OBJECT
	const varType t; //TYPE
} var;

pattern varProto {

} varProto;


subject array {

} array;


pattern arraySingleton {
	array ptr (fnPtr arrayNew) ();
	void (fnPtr arrayDel) (array ptr obj);
} arraySingleton;


subject string {

} string;

pattern stringSingleton {
	string ptr (fnPtr stringNew) ();
	void (fnPtr stringDel) (string ptr obj);
} stringSingleton;

/* </TYPE> ************/


/* <VARIABLE> *************/

/* </VARIABLE> ************/


// <DECLARATION> //

#ifdef Cplusplus
extern "C" {
#endif


varProto ptr varProtoNew ();

var ptr varNew (varType vt, object ptr obj);
//var ptr varInt (object ptr obj);
void varDel (var ptr obj);

//var ptr varSet (object ptr obj);
//var ptr varGet (object ptr obj);

arraySingleton ptr arraySingletonNew ();

array ptr arrayNew ();
void arrayDel (array ptr obj);



stringSingleton ptr stringSingletonNew ();

string ptr stringNew ();
void stringDel (string ptr obj);


#ifdef Cplusplus
}
#endif

// </DECLARATION> //


#endif

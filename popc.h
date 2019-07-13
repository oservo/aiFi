#ifndef FRAMEWORK__POPC
#define FRAMEWORK__POPC

// [INCLUDE] //
//#include REQUIRED HEADERS HERE
// [/INCLUDE] //

// [DEFINE] //
//#define REQUIRED STUFFS HERE
#define ptr         *
#define ptr2d       **
#define ptr3d       ***
#define ptr4d       ****

#define ptrVal      *
#define ptrVal2d    **
#define ptrVal3d    ***
#define ptrVal4d    ****

#define addr        &

#define fnPtr       *
#define fnPtr2d     **
#define fnPtr3d     ***
#define fnPtr4d     ****


#define public
#define protected 	static
#define private 		static

#define any 				void

#define bool 				int
#define true 				1
#define false 			0
#define null				NULL


#define property 		typedef struct
#define subject 		typedef struct
#define prototype 	typedef struct

#define enumeration	typedef enum
#define delegation	typedef

// [/DEFINE] //



/* [CONST] *************/
//#define REQUIRED STUFFS HERE
/* [/CONST] ************/

/* [TYPE] *************/

/* [/TYPE] ************/


/* [VARIABLE] *************/

/* [/VARIABLE] ************/


// [DECLARATION] //

#ifdef Cplusplus
extern "C" {
#endif



#ifdef Cplusplus
}
#endif

// [/DECLARATION] //


#endif

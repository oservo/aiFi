#ifndef DATA_STRUCTURE__TREE
#define DATA_STRUCTURE__TREE

/* [INCLUDE] *************/
#include "popc.h"
/* [/INCLUDE] ************/

/* [DEFINE] *************/
//#define REQUIRED STUFFS HERE
/* [/DEFINE] ************/

/* [CONST] *************/
//#define REQUIRED STUFFS HERE
/* [/CONST] ************/

/* [TYPE] *************/
subject treeNode treeNode; //FD!
subject treeNode {
	any ptr object;
	treeNode ptr left;
	treeNode ptr right;
} treeNode;

prototype treeProto {

} treeProto;

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

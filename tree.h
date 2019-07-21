#ifndef DATA_STRUCTURE__TREE
#define DATA_STRUCTURE__TREE

/* <INCLUDE> *************/
#include "popc.h"
/* </INCLUDE> ************/

/* <DEFINE> *************/
//#define REQUIRED STUFFS HERE
/* </DEFINE> ************/

/* <CONST> *************/
//#define REQUIRED STUFFS HERE
/* </CONST> ************/

/* <TYPE> *************/
subject treeNode treeNode; //FD!
subject treeNode {
	object ptr obj;
	treeNode ptr left;
	treeNode ptr right;
} treeNode;

pattern treeProto {

} treeProto;

/* </TYPE> ************/

/* <VARIABLE> *************/

/* </VARIABLE> ************/

/* <DECLARATION> *************/
#ifdef Cplusplus
extern "C" {
#endif

void treeInsertNode(treeNode ptr2d root, linkedListCompareDelegate compare, object ptr obj);
void inOrder(treeNode ptr root, linkedListDisplayDelegate display);
void postOrder(treeNode ptr root, linkedListDisplayDelegate display);
void preOrder(treeNode ptr root, linkedListDisplayDelegate display);

#ifdef Cplusplus
}
#endif
/* </DECLARATION> ************/

#endif

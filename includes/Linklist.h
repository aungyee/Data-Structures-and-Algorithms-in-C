#ifndef LISTLINK_H
#define LISTLINK_H
#include <stddef.h>
#include <stdio.h>

/*


CreateNewNode(size_t data): Create a New linklist node with data
LenOfLinklist(Node* Head): Calculate the length of the linklist
Delete_NodeatPos(Node* Head, int pos): Delete Node at index pos
Linklist_Get_at(Node* Head, int pos): Get the data at index pos
Linklist_set_at(Node*Head, int pos, size_t data): set the data of linklist at index pos	
 
*/


typedef struct Linklist{
	size_t data;
	struct Linklist* next; 
}Linklist;



//size_t Node* CreateNewNode(size_t data);

//size_t LenOfLinklist(Node* Head);

//size_t Delete_NodeAtPos(Node* Head,int pos);

//size_t LinkList_Get_at(Node* Head,int pos);

//size_t LinkList_set_at(Node* Head, int pos, size_t x);

#endif

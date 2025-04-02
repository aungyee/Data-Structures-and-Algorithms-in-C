#include <stdio.h>
#include "data_structures.h"
int main(){
	link_list *a;
	a = create_new_node(11);
	a->next = create_new_node(12);
	a->next->next = create_new_node(15);
	a->next->next->next = create_new_node(14);
	printf("show all data in linklist: ");
	traversal_link_list(a);
	printf("\n");
	a = link_list_set_at(a, 2, 13);
	printf("after insert data \"13\" at index \"2\": ");
	traversal_link_list(a);
	printf("\n");
	delete_node_at(a,4);
	printf("show the element after delete at index \"4\": ");
	traversal_link_list(a);
	printf("\n");
	printf("get the element at index \"3\": %zu",link_list_get_at(a,3));	
}

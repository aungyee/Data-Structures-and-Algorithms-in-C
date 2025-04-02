#include <stdio.h>
#include <stdlib.h>
#include "data_structures.h"


link_list *create_new_node(size_t data){
	link_list *a =(link_list*)malloc(sizeof (link_list));
	a->data = data;
	a->next = NULL;
	return a;
}

int length_of_link_list(link_list* l){
	if(l == NULL){
		return 1;
	}
	int count = 0;
	link_list *temp = l;
	while (temp != NULL){
		count++;
		temp = temp->next;
	}
	return count;
}

void traversal_link_list(link_list *l){
	if(l == NULL){
		printf("Linklist is Empty");
		exit(1);
	}
	link_list *temp = l;
	while (temp != NULL){
		printf("%zu ",temp->data);
		temp = temp->next;
	}
}


link_list *delete_node_at(link_list *l,int i){
	if(i > length_of_link_list(l)) {
		printf("Index Out of bound!");
		exit(1);
		}      
	link_list *temp = l;
	link_list *prev = NULL;
	if (temp == NULL){
		return l;
	}
	if(i ==1){
		l->next = temp;
		free(temp);
		return l;
	}
	for(int j = 0;j < i - 1 && temp != NULL;j++){
		prev = temp;
		temp = temp->next; 
	}
	
	if ( temp != NULL){
		prev->next = temp->next;
		free(temp);
	}
	return l;
}

size_t link_list_get_at(link_list *l,int i){
	if (i > length_of_link_list(l)) {
		printf(" index out of bound");
		exit(1);
	}
	
	link_list *temp = l;
	int x = 0;
	while(temp != NULL){
		if( x == i-1){
			return temp->data;
		}
		temp = temp->next;
		x = x + 1;	    
	}
	return 1;
}

link_list *link_list_set_at(link_list *l, int i, size_t x){
	if(i > length_of_link_list(l)) {
		printf("Index out of bound");
		exit(1);
	}
	link_list *temp = l;
	
	if (i < 1){
		return l;
	}
	
	if(i == 1 ){
		link_list *new_node = create_new_node(x);
		new_node -> next = l ;
		return new_node;
	}
	
	for(int j = 1; j < i - 1  && temp != NULL ; j++){
		printf("%zu",temp->data);
		temp = temp->next;
	}
	if (temp ==NULL){
		return l;
		}
	link_list *new_node = create_new_node(x);
	new_node->next = temp->next;
	temp->next = new_node;
	return l; 
} 


	



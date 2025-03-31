#include <stdio.h>
#include <stdlib.h>
#include "data_structures.h"


linklist *create_new_node(size_t data){
	linklist *a =(linklist*)malloc(sizeof (linklist));
	a->data = data;
	a->next = NULL;
	return a;
};

int length_of_linklist(linklist* l){
	if(l == NULL){
		return 1;
	}
	int count = 0;
	linklist *temp = l;
	while (temp != NULL){
		count++;
		temp = temp->next;
	}
	return count;
}

void traversal_linklist(linklist *l){
	if(l == NULL){
		printf("Linklist is Empty");
		exit(1);
	}
	linklist *temp = l;
//	printf("%zu->",temp);
	while (temp != NULL){
		printf("%zu ",temp->data);
		temp = temp->next;
	}
}


linklist* delete_node_at(linklist* l,int i){
	if(i > length_of_linklist(l)) {
		printf("Index Out of bound!");
		exit(1);
		}      
	linklist* temp = l;
	linklist* prev = NULL;
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

size_t linklist_get_at(linklist* l,int i){
	if (i > length_of_linklist(l)) {
		printf(" index out of bound");
		exit(1);
	}
	
	linklist *temp = l;
	int x = 0;
	while(temp != NULL){
		if( x == i-1){
			return temp->data;
		}
		temp = temp->next;
		x = x + 1;	    
	}
}

linklist* linkList_set_at(linklist* l, int i, size_t x){
	if(i > length_of_linklist(l)) {
		printf("Index out of bound");
		exit(1);
	}
	linklist* temp = l;
	
	if (i < 1){
		return l;
	}
	
	if(i == 1 ){
		linklist* new_node = create_new_node(x);
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
	linklist* new_node = create_new_node(x);
	new_node->next = temp->next;
	temp->next = new_node;
	return l; 
} 


	



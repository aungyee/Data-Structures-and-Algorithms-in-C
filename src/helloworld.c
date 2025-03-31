#include <stdio.h>
#include <stdlib.h>
#include "Linklist.h"
#define ERROR


Linklist *CreateNewNode(size_t data){
	Linklist *a =(Linklist*)malloc(sizeof (Linklist));
	a->data = data;
	a->next = NULL;
	return a;
};

int LenOfLinklist(Linklist *Head){
	if(Head == NULL){
		return 1;
	}
	int count = 0;
	Linklist *temp = Head;
	while (temp != NULL){
		count++;
		temp = temp->next;
	}
	return count;
}

void TrasalLinklist(Linklist *Head){
	if(Head == NULL){
		printf("Linklist is Empty");
		exit(1);
	}
	Linklist *temp = Head;
//	printf("%zu->",temp);
	while (temp != NULL){
		printf("%zu ",temp->data);
		temp = temp->next;
	}
}


Linklist* Delete_NodeAtPos(Linklist* Head,int pos){
	if(pos > LenOfLinklist(Head)) {
		printf("Index Out of bound!");
		exit(1);
		}      
	Linklist* temp = Head;
	Linklist* prev = NULL;
	if (temp == NULL){
		return Head;
	}
	if(pos ==1){
		Head->next = temp;
		free(temp);
		return Head;
	}
	for(int i = 0;i < pos - 1 && temp != NULL;i++){
		prev = temp;
		temp = temp->next; 
	}
	
	if ( temp != NULL){
		prev->next = temp->next;
		free(temp);
	}
	return Head;
}

size_t Linklist_Get_at(Linklist* Head,int pos){
	if (pos > LenOfLinklist(Head)) {
		printf(" index out of bound");
		exit(1);
	}
	
	Linklist *temp = Head;
	int i = 0;
	while(temp != NULL){
		if( i == pos-1){
			return temp->data;
		}
		temp = temp->next;
		i = i + 1;	    
	}
}

Linklist* LinkList_set_at(Linklist* Head, int pos, size_t x){
	if(pos > LenOfLinklist(Head)) {
		printf("Index out of bound");
		exit(1);
	}
	Linklist* temp = Head;
	Linklist* newNode = CreateNewNode(x);
	if (pos < 1){
		return Head;
	}
	
	if(pos ==1 ){
		newNode->next = Head;
		return newNode;
	}
	
	for(int i = 0; i < pos -1 && temp->next != NULL;i++){
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
	Head->next = temp;
	return Head; 
} 
int main(){
	Linklist* a;
	a = CreateNewNode(11);
	a->next=CreateNewNode(12);
	a->next->next = CreateNewNode(15);
	a = LinkList_set_at(a, 2, 13);
	TrasalLinklist(a);
	Delete_NodeAtPos(a,4);
	TrasalLinklist(a);
	printf("\n%i",Linklist_Get_at(a,1));
	
}

	



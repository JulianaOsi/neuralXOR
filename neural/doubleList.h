#pragma once
struct node {
	int value;
	node* next;
	node* previous;
};


void addInTail(node* head, int data);
void addInTop(node* head, int data);
void printElements(node* head);
struct node* addHead();
int findElement(node* head, int index);


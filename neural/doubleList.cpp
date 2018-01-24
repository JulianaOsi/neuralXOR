#include "stdafx.h"
#include "doubleList.h"

struct node* addHead() {
	node* head = new node; //creating head node

	head->previous = NULL;	   //pointer to the tail node
	head->next = NULL;		//pointer to the top node
	head->value = 3;
	return head;
}

void addInTail(node* head, int data) {  //accept the values of pointer to the tail and data

	node* tail = head;
	while (tail->previous) {
		tail = tail->previous;
	}

	node* newElement = new node; //create new element
	tail->previous = newElement;  //указатель хвоста на предыдущий = указатель на новый элемент
	newElement->next = tail;	//следующий нового элемента = бывший хвост
	/*т.е. содали двустороннюю связь м/у новым и хвостовым*/
	newElement->previous = NULL; //указатель нового на предыдущий = null
	newElement->value = data;
}

void addInTop(node* head, int data) {

	node* top = head;
	while (top->next) {
		top = top->next;
	}

	node* newElement = new node;
	top->next = newElement;
	newElement->previous = top;

	newElement->next = NULL;
	newElement->value = data;
}

void printElements(node* head) {
	node* p = head;
	while (p->previous) {
		p = p->previous;
	}

	while (p)
	{
		cout << p->value << endl;
		p = p->next;
	}
}

int findElement(node* head, int index) {
	node* p = head;
	while (p->previous) {
		p = p->previous;
	}
	int ind = 0;
	while (ind != index) {
		p = p->next;
		ind++;
	}
	return p->value;
}

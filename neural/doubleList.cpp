#include "stdafx.h"
#include "doubleList.h"

struct node* addHead(int value) {
	node* head = new node;		//создание корневого узла

	head->previous = NULL;		//обнуление указателя на предыдущий узел
	head->next = NULL;			//обнуление указателя на следующий узел
	head->value = value;		//занесение значения в узел
	return head;				//возвращение корневого узла
}

void addInTail(node* head, int data) {

	node* tail = head;			//создание временного указателя на корень
	while (tail->previous) {	//поиск хвостового узла
		tail = tail->previous;
	}

	node* newElement = new node;//создание указателя на новый узел
	/*создание двусторонней связи между созданным узлом и хвостовым*/
	tail->previous = newElement;
	newElement->next = tail;	
	newElement->previous = NULL;//обнуление указателя на предыдущий узел
	newElement->value = data;	//занесение значения в новый узел
}

void addInTop(node* head, int data) {

	node* top = head;			//создание временного указателя на корень
	while (top->next) {			//поиск верхнего узла
		top = top->next;
	}

	node* newElement = new node;//создание указателя на новый узел
	/*создание двусторонней связи между созданным узлом и верхним*/
	top->next = newElement;
	newElement->previous = top;

	newElement->next = NULL;	//обнуление указателя на следующий узел
	newElement->value = data;	//занесение значения в новый узел
}

void printElements(node* head) {
	node* p = head;				//создание временного указателя на корень
	while (p->previous) {		//поиск хвостового узла
		p = p->previous;
	}

	while (p)					//печать значений всех узлов, начиная с хвостового
	{
		cout << p->value << endl;
		p = p->next;
	}
}

int findElement(node* head, int index) {
	node* p = head;				//создание временного указателя на корень
	while (p->previous) {		//поиск хвостового узла
		p = p->previous;
	}
	int ind = 0;
	while (ind != index) {		//перебор всех узлов, начиная с хвостового
		p = p->next;			//пока не найден узел с нужным индексом
		ind++;
	}
	return p->value;			//возвращение значения в узле
}

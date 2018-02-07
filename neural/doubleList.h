#pragma once
#include "stdafx.h"

/*структура, описывающая узел списка*/
template <typename T>
struct node {
	T value;			//значение в узле
	node<T>* next;			//указатель на следующий узел
	node<T>* previous;		//указатель на предыдущий узел
};

template <typename T>
struct node<T>* addHead(T value) {
	node<T>* head = new node<T>;		//создание корневого узла

	head->previous = NULL;		//обнуление указателя на предыдущий узел
	head->next = NULL;			//обнуление указателя на следующий узел
	head->value = value;		//занесение значения в узел
	return head;				//возвращение корневого узла
}

template <typename T>
void addInTail(node<T>* head, T data) {

	node<T>* tail = head;			//создание временного указателя на корень
	while (tail->previous) {	//поиск хвостового узла
		tail = tail->previous;
	}

	node<T>* newElement = new node<T>;//создание указателя на новый узел
								/*создание двусторонней связи между созданным узлом и хвостовым*/
	tail->previous = newElement;
	newElement->next = tail;
	newElement->previous = NULL;//обнуление указателя на предыдущий узел
	newElement->value = data;	//занесение значения в новый узел
}

template <typename T>
void addInTop(node<T>* head, T data) {

	node<T>* top = head;			//создание временного указателя на корень
	while (top->next) {			//поиск верхнего узла
		top = top->next;
	}

	node<T>* newElement = new node<T>;//создание указателя на новый узел
								/*создание двусторонней связи между созданным узлом и верхним*/
	top->next = newElement;
	newElement->previous = top;

	newElement->next = NULL;	//обнуление указателя на следующий узел
	newElement->value = data;	//занесение значения в новый узел
}
template <typename T>
void printElements(node<T>* head) {
	node<T>* p = head;				//создание временного указателя на корень
	while (p->previous) {		//поиск хвостового узла
		p = p->previous;
	}

	while (p)					//печать значений всех узлов, начиная с хвостового
	{
		cout << p->value << endl;
		p = p->next;
	}
}
template <typename T>
T findElement(node<T>* head, int index) {
	node<T>* p = head;				//создание временного указателя на корень
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

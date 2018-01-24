#pragma once

/*структура, описывающая узел списка*/
struct node {
	int value;			//значение в узле
	node* next;			//указатель на следующий узел
	node* previous;		//указатель на предыдущий узел
};

/*создает корень списка, value - значение в корне, возвращает указатель на корень списка*/
struct node* addHead(int value);

/*добавление элемента в конец списка, head - указатель на корень списка , data - содержимое*/
void addInTail(node* head, int data);

/*добавление элемента в начало списка, head - указатель на корень списка , data - содержимое*/
void addInTop(node* head, int data);

/*вывод списка на печать, head - указатель на корень списка*/
void printElements(node* head);

/*поиск элемента по индексу, head - указатель на корень списка , index - порядковый номер, возвращает значение в узле*/
int findElement(node* head, int index);


#include "stdafx.h"
#include "doubleList.h"

struct node* addHead(int value) {
	node* head = new node;		//�������� ��������� ����

	head->previous = NULL;		//��������� ��������� �� ���������� ����
	head->next = NULL;			//��������� ��������� �� ��������� ����
	head->value = value;		//��������� �������� � ����
	return head;				//����������� ��������� ����
}

void addInTail(node* head, int data) {

	node* tail = head;			//�������� ���������� ��������� �� ������
	while (tail->previous) {	//����� ���������� ����
		tail = tail->previous;
	}

	node* newElement = new node;//�������� ��������� �� ����� ����
	/*�������� ������������ ����� ����� ��������� ����� � ���������*/
	tail->previous = newElement;
	newElement->next = tail;	
	newElement->previous = NULL;//��������� ��������� �� ���������� ����
	newElement->value = data;	//��������� �������� � ����� ����
}

void addInTop(node* head, int data) {

	node* top = head;			//�������� ���������� ��������� �� ������
	while (top->next) {			//����� �������� ����
		top = top->next;
	}

	node* newElement = new node;//�������� ��������� �� ����� ����
	/*�������� ������������ ����� ����� ��������� ����� � �������*/
	top->next = newElement;
	newElement->previous = top;

	newElement->next = NULL;	//��������� ��������� �� ��������� ����
	newElement->value = data;	//��������� �������� � ����� ����
}

void printElements(node* head) {
	node* p = head;				//�������� ���������� ��������� �� ������
	while (p->previous) {		//����� ���������� ����
		p = p->previous;
	}

	while (p)					//������ �������� ���� �����, ������� � ����������
	{
		cout << p->value << endl;
		p = p->next;
	}
}

int findElement(node* head, int index) {
	node* p = head;				//�������� ���������� ��������� �� ������
	while (p->previous) {		//����� ���������� ����
		p = p->previous;
	}
	int ind = 0;
	while (ind != index) {		//������� ���� �����, ������� � ����������
		p = p->next;			//���� �� ������ ���� � ������ ��������
		ind++;
	}
	return p->value;			//����������� �������� � ����
}
